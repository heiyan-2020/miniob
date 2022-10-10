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
// Created by Wangyunlai on 2021/5/14.
//

#include "rc.h"

#define RC_CASE_STRING(rc) \
  case rc:                 \
    return #rc

const char *strrc(RC rc)
{
  switch (rc) {
    RC_CASE_STRING(SUCCESS);
    RC_CASE_STRING(GENERIC_ERROR);
    RC_CASE_STRING(INVALID_ARGUMENT);
    RC_CASE_STRING(UNIMPLENMENT);
    RC_CASE_STRING(SQL_SYNTAX);
    RC_CASE_STRING(BUFFERPOOL);
    RC_CASE_STRING(RECORD);
    RC_CASE_STRING(INTERNAL);
    RC_CASE_STRING(PERM);
    RC_CASE_STRING(ABORT);
    RC_CASE_STRING(BUSY);
    RC_CASE_STRING(LOCKED);
    RC_CASE_STRING(NOMEM);
    RC_CASE_STRING(READONLY);
    RC_CASE_STRING(INTERRUPT);
    RC_CASE_STRING(IOERR);
    RC_CASE_STRING(CORRUPT);
    RC_CASE_STRING(NOTFOUND);
    RC_CASE_STRING(FULL);
    RC_CASE_STRING(CANTOPEN);
    RC_CASE_STRING(PROTOCOL);
    RC_CASE_STRING(EMPTY);
    RC_CASE_STRING(SCHEMA);
    RC_CASE_STRING(TOOBIG);
    RC_CASE_STRING(CONSTRAINT);
    RC_CASE_STRING(MISMATCH);
    RC_CASE_STRING(MISUSE);
    RC_CASE_STRING(NOLFS);
    RC_CASE_STRING(AUTH);
    RC_CASE_STRING(FORMAT);
    RC_CASE_STRING(RANGE);
    RC_CASE_STRING(NOTADB);
    RC_CASE_STRING(NOTICE);
    RC_CASE_STRING(DATEFORMAT);
    RC_CASE_STRING(EVALUATE);

    RC_CASE_STRING(BUFFERPOOL_EXIST);
    RC_CASE_STRING(BUFFERPOOL_FILEERR);
    RC_CASE_STRING(BUFFERPOOL_INVALIDNAME);
    RC_CASE_STRING(BUFFERPOOL_WINDOWS);
    RC_CASE_STRING(BUFFERPOOL_CLOSED);
    RC_CASE_STRING(BUFFERPOOL_OPEN);
    RC_CASE_STRING(BUFFERPOOL_NOBUF);
    RC_CASE_STRING(BUFFERPOOL_EOF);
    RC_CASE_STRING(BUFFERPOOL_INVALID_PAGE_NUM);
    RC_CASE_STRING(BUFFERPOOL_NOTINBUF);
    RC_CASE_STRING(BUFFERPOOL_PAGE_PINNED);
    RC_CASE_STRING(BUFFERPOOL_OPEN_TOO_MANY_FILES);
    RC_CASE_STRING(BUFFERPOOL_ILLEGAL_FILE_ID);

    RC_CASE_STRING(RECORD_CLOSED);
    RC_CASE_STRING(RECORD_OPENNED);
    RC_CASE_STRING(RECORD_INVALIDRECSIZE);
    RC_CASE_STRING(RECORD_INVALIDRID);
    RC_CASE_STRING(RECORD_NOMORERECINMEM);
    RC_CASE_STRING(RECORD_OPEN);
    RC_CASE_STRING(RECORD_NO_MORE_IDX_IN_MEM);
    RC_CASE_STRING(RECORD_INVALID_KEY);
    RC_CASE_STRING(RECORD_DUPLICATE_KEY);
    RC_CASE_STRING(RECORD_NOMEM);
    RC_CASE_STRING(RECORD_SCANCLOSED);
    RC_CASE_STRING(RECORD_SCANOPENNED);
    RC_CASE_STRING(RECORD_EOF);
    RC_CASE_STRING(RECORD_RECORD_NOT_EXIST);

    RC_CASE_STRING(SCHEMA_DB_EXIST);
    RC_CASE_STRING(SCHEMA_DB_NOT_EXIST);
    RC_CASE_STRING(SCHEMA_DB_NOT_OPENED);
    RC_CASE_STRING(SCHEMA_TABLE_NOT_EXIST);
    RC_CASE_STRING(SCHEMA_TABLE_EXIST);
    RC_CASE_STRING(SCHEMA_TABLE_NAME_ILLEGAL);
    RC_CASE_STRING(SCHEMA_FIELD_NOT_EXIST);
    RC_CASE_STRING(SCHEMA_FIELD_EXIST);
    RC_CASE_STRING(SCHEMA_FIELD_NAME_ILLEGAL);
    RC_CASE_STRING(SCHEMA_FIELD_MISSING);
    RC_CASE_STRING(SCHEMA_FIELD_REDUNDAN);
    RC_CASE_STRING(SCHEMA_FIELD_TYPE_MISMATCH);
    RC_CASE_STRING(SCHEMA_INDEX_NAME_REPEAT);
    RC_CASE_STRING(SCHEMA_INDEX_EXIST);
    RC_CASE_STRING(SCHEMA_INDEX_NOT_EXIST);
    RC_CASE_STRING(SCHEMA_INDEX_NAME_ILLEGAL);

    RC_CASE_STRING(IOERR_READ);
    RC_CASE_STRING(IOERR_SHORT_READ);
    RC_CASE_STRING(IOERR_WRITE);
    RC_CASE_STRING(IOERR_FSYNC);
    RC_CASE_STRING(IOERR_DIR_FSYNC);
    RC_CASE_STRING(IOERR_TRUNCATE);
    RC_CASE_STRING(IOERR_FSTAT);
    RC_CASE_STRING(IOERR_DELETE);
    RC_CASE_STRING(IOERR_BLOCKED);
    RC_CASE_STRING(IOERR_ACCESS);
    RC_CASE_STRING(IOERR_CHECKRESERVEDLOCK);
    RC_CASE_STRING(IOERR_CLOSE);
    RC_CASE_STRING(IOERR_DIR_CLOSE);
    RC_CASE_STRING(IOERR_SHMOPEN);
    RC_CASE_STRING(IOERR_SHMSIZE);
    RC_CASE_STRING(IOERR_SHMLOCK);
    RC_CASE_STRING(IOERR_SHMMAP);
    RC_CASE_STRING(IOERR_SEEK);
    RC_CASE_STRING(IOERR_DELETE_NOENT);
    RC_CASE_STRING(IOERR_MMAP);
    RC_CASE_STRING(IOERR_GETTEMPPATH);
    RC_CASE_STRING(IOERR_CONVPATH);
    RC_CASE_STRING(IOERR_VNODE);
    RC_CASE_STRING(IOERR_BEGIN_ATOMIC);
    RC_CASE_STRING(IOERR_COMMIT_ATOMIC);
    RC_CASE_STRING(IOERR_ROLLBACK_ATOMIC);
    RC_CASE_STRING(IOERR_DATA);
    RC_CASE_STRING(IOERR_CORRUPTFS);
    RC_CASE_STRING(IOERR_OPEN_TOO_MANY_FILES);

    RC_CASE_STRING(LOCKED_LOCK);
    RC_CASE_STRING(LOCKED_UNLOCK);
    RC_CASE_STRING(LOCKED_SHAREDCACHE);
    RC_CASE_STRING(LOCKED_VIRT);
    RC_CASE_STRING(LOCKED_NEED_WAIT);
    RC_CASE_STRING(LOCKED_RESOURCE_DELETED);

    RC_CASE_STRING(BUSY_RECOVERY);
    RC_CASE_STRING(BUSY_SNAPSHOT);
    RC_CASE_STRING(BUSY_TIMEOUT);

    RC_CASE_STRING(CANTOPEN_NOTEMPDIR);
    RC_CASE_STRING(CANTOPEN_ISDIR);
    RC_CASE_STRING(CANTOPEN_FULLPATH);
    RC_CASE_STRING(CANTOPEN_CONVPATH);
    RC_CASE_STRING(CANTOPEN_DIRTYWAL);
    RC_CASE_STRING(CANTOPEN_SYMLINK);

    RC_CASE_STRING(READONLY_RECOVERY);
    RC_CASE_STRING(READONLY_CANTLOCK);
    RC_CASE_STRING(READONLY_ROLLBACK);
    RC_CASE_STRING(READONLY_DBMOVED);
    RC_CASE_STRING(READONLY_CANTINIT);
    RC_CASE_STRING(READONLY_DIRECTORY);

    RC_CASE_STRING(ABORT_ROLLBACK);

    RC_CASE_STRING(CONSTRAINT_CHECK);
    RC_CASE_STRING(CONSTRAINT_COMMITHOOK);
    RC_CASE_STRING(CONSTRAINT_FOREIGNKEY);
    RC_CASE_STRING(CONSTRAINT_FUNCTION);
    RC_CASE_STRING(CONSTRAINT_NOTNULL);
    RC_CASE_STRING(CONSTRAINT_PRIMARYKEY);
    RC_CASE_STRING(CONSTRAINT_TRIGGER);
    RC_CASE_STRING(CONSTRAINT_UNIQUE);
    RC_CASE_STRING(CONSTRAINT_VIRT);
    RC_CASE_STRING(CONSTRAINT_ROWID);
    RC_CASE_STRING(CONSTRAINT_PINNED);

    RC_CASE_STRING(NOTICE_RECOVER_WAL);
    RC_CASE_STRING(NOTICE_RECOVER_ROLLBACK);
    RC_CASE_STRING(NOTICE_AUTOINDEX);

    RC_CASE_STRING(AUTH_USER);

    default: {
      return "UNKNOWN";
    }
  }
}
