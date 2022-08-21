#ifndef UTILITY_H
#define UTILITY_H

#include <string>

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.
extern int short_array_int[10];
extern int long_array_int[5000];
extern std::string short_array_string[10];
extern std::string long_array_string[5000];

#endif
