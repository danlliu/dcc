
#ifndef _DCC_MACROS_H
#define _DCC_MACROS_H

#include <iostream>

#define UNREACHABLE(msg) \
  do { \
    std::cerr << "ASSERTION FAILED: UNREACHABLE" << std::endl; \
    std::cerr << "Message: " << msg << std::endl; \
    exit(2); \
  } while(0)

#define ERR_AND_EXIT(msg) \
  do { \
    std::cerr << msg << std::endl; \
    exit(1); \
  } while(0)

#endif
