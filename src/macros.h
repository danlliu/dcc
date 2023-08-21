
#ifndef _DCC_MACROS_H
#define _DCC_MACROS_H

#include <iostream>

#define INFO(x) "\033[96m" x "\033[0m"
#define WARNING(x) "\033[93m" x "\033[0m"
#define ERROR(x) "\033[91m" x "\033[0m"

#define UNREACHABLE(msg)                                              \
  do {                                                                \
    std::cerr << ERROR("ASSERTION FAILED: UNREACHABLE") << std::endl; \
    std::cerr << "Message: " << msg << std::endl;                     \
    exit(2);                                                          \
  } while (0)

#define ERR_AND_EXIT(msg)                              \
  do {                                                 \
    std::cerr << ERROR("ERROR: ") << msg << std::endl; \
    exit(1);                                           \
  } while (0)

#endif
