/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
//
// Created by Xie Meiyi
// Rewritten by Longda & Wangyunlai
//
//
#ifndef __OBSERVER_STORAGE_COMMON_INDEX_MANAGER_H_
#define __OBSERVER_STORAGE_COMMON_INDEX_MANAGER_H_

#include <cstring>
#include <sstream>
#include <functional>

#include "storage/record/record_manager.h"
#include "storage/default/disk_buffer_pool.h"
#include "util/comparator.h"
#include "util/date.h"
#include "type/value.h"

class AttrComparator {
public:
  void init(TypeId type, int length)
  {
    attr_type_ = type;
    attr_length_ = length;
  }

  int attr_length() const
  {
    return attr_length_;
  }

  int operator()(const char *v1, const char *v2) const
  {
    switch (attr_type_) {
      case INT: {
        Value lhs{INT, *(int32_t *)v1};
        Value rhs{INT, *(int32_t *)v2};
        return lhs.compare(rhs);
      } break;
      case FLOAT: {
        Value lhs{FLOAT, *(float *)v1};
        Value rhs{FLOAT, *(float *)v2};
        return lhs.compare(rhs);
      }
      case CHAR: {
        Value lhs{CHAR, v1, static_cast<size_t>(attr_length_)};
        Value rhs{CHAR, v2, static_cast<size_t>(attr_length_)};
        return lhs.compare(rhs);
      }
      case DATE: {
        return compare_date((void *)v1, (void *)v2);
      }
      default: {
        LOG_ERROR("unknown attr type %d", attr_type_);
      }
    }
  }

private:
  TypeId attr_type_;
  int attr_length_;
};

class KeyComparator {
public:
  void init(std::vector<TypeId> attr_types, std::vector<int> attr_lengths)
  {
    assert(attr_types.size() == attr_lengths.size());
    AttrComparator comparator{};
    for (std::vector<TypeId>::size_type i = 0; i < attr_types.size(); ++i) {
      comparator.init(attr_types[i], attr_lengths[i]);
      attr_comparators_.push_back(comparator);
    }
  }

  int operator()(const char *v1, const char *v2) const
  {
    int attr_length{};
    for (auto comparator : attr_comparators_) {
      int result = comparator(v1 + attr_length, v2 + attr_length);
      if (result != 0) {
        return result;
      }
      attr_length += comparator.attr_length();
    }

    const RID *rid1 = (const RID *)(v1 + attr_length);
    const RID *rid2 = (const RID *)(v2 + attr_length);
    return RID::compare(rid1, rid2);
  }

private:
  std::vector<AttrComparator> attr_comparators_;
};

class AttrPrinter {
public:
  void init(TypeId type, int length)
  {
    attr_type_ = type;
    attr_length_ = length;
  }

  int attr_length() const
  {
    return attr_length_;
  }

  std::string operator()(const char *v) const
  {
    switch (attr_type_) {
      case INT: {
        return std::to_string(*(int *)v);
      }
      case FLOAT: {
        return std::to_string(*(float *)v);
      }
      case CHAR: {
        std::string str;
        for (int i = 0; i < attr_length_; i++) {
          if (v[i] == 0) {
            break;
          }
          str.push_back(v[i]);
        }
        return str;
      }
      case DATE: {
        Date date{(void *)v};
        return date.to_string();
      }
      default: {
        LOG_ERROR("unknown attr type. %d", attr_type_);
      }
    }
  }

private:
  TypeId attr_type_;
  int attr_length_;
};

class KeyPrinter {
public:
  void init(std::vector<TypeId> attr_types, std::vector<int> attr_lengths)
  {
    assert(attr_types.size() == attr_lengths.size());
    AttrPrinter printer{};
    for (std::vector<TypeId>::size_type i = 0; i < attr_types.size(); ++i) {
      printer.init(attr_types[i], attr_lengths[i]);
      attr_printers_.push_back(printer);
    }
  }

  std::string operator()(const char *v) const
  {
    std::stringstream ss;
    ss << "{key:";

    int attr_length{};
    for (auto printer : attr_printers_) {
      ss << printer(v + attr_length) << ",";
      attr_length += printer.attr_length();
    }

    const RID *rid = (const RID *)(v + attr_length);
    ss << "rid:{" << rid->to_string() << "}}";
    return ss.str();
  }

private:
  std::vector<AttrPrinter> attr_printers_;
};

#define MAX_ATTR_NUM 4

/**
 * the meta information of bplus tree
 * this is the first page of bplus tree.
 */
struct IndexFileHeader {
  IndexFileHeader()
  {
    memset(this, 0, sizeof(IndexFileHeader));
    root_page = BP_INVALID_PAGE_NUM;
  }
  PageNum root_page;
  int32_t internal_max_size;
  int32_t leaf_max_size;
  int32_t attr_total_length;
  int32_t key_length;  // attr total length + sizeof(RID)
  int32_t attr_num;
  TypeId attr_type[MAX_ATTR_NUM];  // TODO: support up to 4 multi index
  int32_t attr_length[MAX_ATTR_NUM];

  std::string to_string() const
  {
    std::stringstream ss;

    ss << "attr_total_length:" << attr_total_length << ","
       << "key_length:" << key_length << ","
       << "attr_num:" << attr_num << ","
       << "attr_type:";
    for (auto i = 0; i < attr_num; ++i) {
      ss << attr_type[i] << ",";
    }
    ss << "attr_length:";
    for (auto i = 0; i < attr_num; ++i) {
      ss << attr_length[i] << ",";
    }
    ss << "root_page:" << root_page << ","
       << "internal_max_size:" << internal_max_size << ","
       << "leaf_max_size:" << leaf_max_size << ";";

    return ss.str();
  }
};

/**
 * the common part of page description of bplus tree
 * storage format:
 * | page type | item number | parent page id |
 */
struct IndexNode {
  static constexpr int HEADER_SIZE = 12;

  bool is_leaf;
  int key_num;
  PageNum parent;
};

/**
 * leaf page of bplus tree
 * storage format:
 * | common header | prev page id | next page id |
 * | key0, rid0 | key1, rid1 | ... | keyn, ridn |
 *
 * the key is in format: the key value of record and rid.
 * so the key in leaf page must be unique.
 * the value is rid.
 * can you implenment a cluster index ?
 */
struct LeafIndexNode : public IndexNode {
  static constexpr int HEADER_SIZE = IndexNode::HEADER_SIZE + 8;

  PageNum prev_brother;
  PageNum next_brother;
  /**
   * leaf can store order keys and rids at most
   */
  char array[0];
};

/**
 * internal page of bplus tree
 * storage format:
 * | common header |
 * | key(0),page_id(0) | key(1), page_id(1) | ... | key(n), page_id(n) |
 *
 * the first key is ignored(key0).
 * so it will waste space, can you fix this?
 */
struct InternalIndexNode : public IndexNode {
  static constexpr int HEADER_SIZE = IndexNode::HEADER_SIZE;

  /**
   * internal node just store order -1 keys and order rids, the last rid is last rght child.
   */
  char array[0];
};

class IndexNodeHandler {
public:
  IndexNodeHandler(const IndexFileHeader &header, Frame *frame);

  void init_empty(bool leaf);

  bool is_leaf() const;
  int key_size() const;
  int value_size() const;
  int item_size() const;

  void increase_size(int n);
  int size() const;
  void set_parent_page_num(PageNum page_num);
  PageNum parent_page_num() const;

  PageNum page_num() const;

  bool validate() const;

  friend std::string to_string(const IndexNodeHandler &handler);

protected:
  const IndexFileHeader &header_;
  PageNum page_num_;
  IndexNode *node_;
};

class LeafIndexNodeHandler : public IndexNodeHandler {
public:
  LeafIndexNodeHandler(const IndexFileHeader &header, Frame *frame);

  void init_empty();
  void set_next_page(PageNum page_num);
  void set_prev_page(PageNum page_num);
  PageNum next_page() const;
  PageNum prev_page() const;

  char *key_at(int index);
  char *value_at(int index);

  /**
   * 查找指定 key 的插入位置 (注意不是 key 本身)
   * 如果 key 已经存在，会设置 found 的值
   * NOTE: 当前 lookup 的实现效率非常低，你是否可以优化它
   */
  int lookup(const KeyComparator &comparator, const char *key, bool *found = nullptr) const;

  void insert(int index, const char *key, const char *value);
  void remove(int index);
  int remove(const char *key, const KeyComparator &comparator);
  RC move_half_to(LeafIndexNodeHandler &other, DiskBufferPool *bp);
  RC move_first_to_end(LeafIndexNodeHandler &other, DiskBufferPool *disk_buffer_pool);
  RC move_last_to_front(LeafIndexNodeHandler &other, DiskBufferPool *bp);
  /**
   * move all items to left page
   */
  RC move_to(LeafIndexNodeHandler &other, DiskBufferPool *bp);

  int max_size() const;
  int min_size() const;

  bool validate(const KeyComparator &comparator, DiskBufferPool *bp) const;

  friend std::string to_string(const LeafIndexNodeHandler &handler, const KeyPrinter &printer);

private:
  char *__item_at(int index) const;
  char *__key_at(int index) const;
  char *__value_at(int index) const;

  void append(const char *item);
  void preappend(const char *item);

private:
  LeafIndexNode *leaf_node_;
};

class InternalIndexNodeHandler : public IndexNodeHandler {
public:
  InternalIndexNodeHandler(const IndexFileHeader &header, Frame *frame);

  void init_empty();
  void create_new_root(PageNum first_page_num, const char *key, PageNum page_num);

  void insert(const char *key, PageNum page_num, const KeyComparator &comparator);
  RC move_half_to(LeafIndexNodeHandler &other, DiskBufferPool *bp);
  char *key_at(int index);
  PageNum value_at(int index);

  /**
   * 返回指定子节点在当前节点中的索引
   */
  int value_index(PageNum page_num);
  void set_key_at(int index, const char *key);
  void remove(int index);

  /**
   * 与 Leaf 节点不同，lookup 返回指定 key 应该属于哪个子节点，返回这个子节点在当前节点中的索引
   * 如果想要返回插入位置，就提供 insert_position 参数
   * NOTE: 查找效率不高，你可以优化它吗
   */
  int lookup(
      const KeyComparator &comparator, const char *key, bool *found = nullptr, int *insert_position = nullptr) const;

  int max_size() const;
  int min_size() const;

  RC move_to(InternalIndexNodeHandler &other, DiskBufferPool *disk_buffer_pool);
  RC move_first_to_end(InternalIndexNodeHandler &other, DiskBufferPool *disk_buffer_pool);
  RC move_last_to_front(InternalIndexNodeHandler &other, DiskBufferPool *bp);
  RC move_half_to(InternalIndexNodeHandler &other, DiskBufferPool *bp);

  bool validate(const KeyComparator &comparator, DiskBufferPool *bp) const;

  friend std::string to_string(const InternalIndexNodeHandler &handler, const KeyPrinter &printer);

private:
  RC copy_from(const char *items, int num, DiskBufferPool *disk_buffer_pool);
  RC append(const char *item, DiskBufferPool *bp);
  RC preappend(const char *item, DiskBufferPool *bp);

private:
  char *__item_at(int index) const;
  char *__key_at(int index) const;
  char *__value_at(int index) const;

  int value_size() const;
  int item_size() const;

private:
  InternalIndexNode *internal_node_;
};

class BplusTreeHandler {
public:
  RC create(const char *file_name, std::vector<TypeId> attr_types, std::vector<int> attr_lengths,
      int internal_max_size = -1, int leaf_max_size = -1);

  RC open(const char *file_name);

  RC close();

  RC insert_entry(const char *user_key, const RID *rid);

  RC delete_entry(const char *user_key, const RID *rid);

  bool is_empty() const;

  RC get_entry(const char *user_key, int key_len, std::list<RID> &rids);

  RC sync();

  void *alloc();

  void free(void *buf);

  /**
   * Check whether current B+ tree is invalid or not.
   * return true means current tree is valid, return false means current tree is invalid.
   * @return
   */
  bool validate_tree();

public:
  RC print_tree();
  RC print_leafs();

private:
  RC print_leaf(Frame *frame);
  RC print_internal_node_recursive(Frame *frame);

  bool validate_node(IndexNode *node);
  bool validate_leaf_link();
  bool validate_node_recursive(Frame *frame);

protected:
  RC find_leaf(const char *key, Frame *&frame);
  RC left_most_page(Frame *&frame);
  RC right_most_page(Frame *&frame);
  RC find_leaf_internal(const std::function<PageNum(InternalIndexNodeHandler &)> &child_page_getter, Frame *&frame);

  RC insert_into_parent(PageNum parent_page, Frame *left_frame, const char *pkey, Frame &right_frame);

  RC delete_entry_internal(Frame *leaf_frame, const char *key);

  RC insert_into_new_root(Frame *left_frame, const char *pkey, Frame &right_frame);

  template <typename IndexNodeHandlerType>
  RC split(Frame *frame, Frame *&new_frame);
  template <typename IndexNodeHandlerType>
  RC coalesce_or_redistribute(Frame *frame);
  template <typename IndexNodeHandlerType>
  RC coalesce(Frame *neighbor_frame, Frame *frame, Frame *parent_frame, int index);
  template <typename IndexNodeHandlerType>
  RC redistribute(Frame *neighbor_frame, Frame *frame, Frame *parent_frame, int index);

  RC insert_entry_into_parent(Frame *frame, Frame *new_frame, const char *key);
  RC insert_entry_into_leaf_node(Frame *frame, const char *pkey, const RID *rid);
  RC update_root_page_num();
  RC create_new_tree(const char *key, const RID *rid);

  RC adjust_root(Frame *root_frame);

private:
  char *make_key(const char *user_key, const RID &rid);
  void free_key(char *key);

protected:
  DiskBufferPool *disk_buffer_pool_ = nullptr;
  bool header_dirty_ = false;
  IndexFileHeader file_header_;

  KeyComparator key_comparator_;
  KeyPrinter key_printer_;

  common::MemPoolItem *mem_pool_item_ = nullptr;

private:
  friend class BplusTreeScanner;
  friend class BplusTreeTester;
};

class BplusTreeScanner {
public:
  BplusTreeScanner(BplusTreeHandler &tree_handler);
  ~BplusTreeScanner();

  /**
   * 扫描指定范围的数据
   * @param left_user_key 扫描范围的左边界，如果是 null，则没有左边界
   * @param left_len left_user_key 的内存大小 - 只有在变长字段中才会关注
   * @param left_inclusive 左边界的值是否包含在内
   * @param right_user_key 扫描范围的右边界。如果是 null，则没有右边界
   * @param right_len right_user_key 的内存大小 - 只有在变长字段中才会关注
   * @param right_inclusive 右边界的值是否包含在内
   */
  RC open(const char *left_user_key, int left_len, bool left_inclusive, const char *right_user_key, int right_len,
      bool right_inclusive);

  RC next_entry(RID *rid);

  RC close();

private:
  bool inited_ = false;
  BplusTreeHandler &tree_handler_;

  // 使用左右叶子节点和位置来表示扫描的起始位置和终止位置
  // 起始位置和终止位置都是有效的数据
  Frame *left_frame_ = nullptr;
  Frame *right_frame_ = nullptr;
  int iter_index_ = -1;
  int end_index_ = -1;  // use -1 for end of scan
};

#endif  //__OBSERVER_STORAGE_COMMON_INDEX_MANAGER_H_
