#pragma once

// Macros to disable copying and moving
#define DISALLOW_COPY(cname)                                    \
  cname(const cname &) = delete;                   /* NOLINT */ \
  auto operator=(const cname &)->cname & = delete; /* NOLINT */

#define DISALLOW_MOVE(cname)                               \
  cname(cname &&) = delete;                   /* NOLINT */ \
  auto operator=(cname &&)->cname & = delete; /* NOLINT */

#define DISALLOW_COPY_AND_MOVE(cname) \
  DISALLOW_COPY(cname);               \
  DISALLOW_MOVE(cname);

#define HANDLE_EXCEPTION(rc, fmt, ...) \
  do {                                 \
    if (rc != RC::SUCCESS) {           \
      LOG_PANIC(fmt, ##__VA_ARGS__);   \
      return rc;                       \
    }                                  \
  } while (0)
