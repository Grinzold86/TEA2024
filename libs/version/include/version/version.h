
#ifndef VERSION_H
#define VERSION_H


#include <string>
#include <fmt/chrono.h>
#include <fmt/format.h>

const char* projectName();
int major();
int minor();
int patch();
std::string fullVersion();

#endif 