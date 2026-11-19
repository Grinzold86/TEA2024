#include <version.h>

const char* projectName()
{
    return "tea24";
}

int major()
{
    return 12;
}

int minor()
{
    return 1;
}
int patch()
{
    return 10;
}

std::string fullVersion()
{
    return std::string(projectName()) + "-" + std::to_string(major()) + "." + std::to_string(minor()) + "." + std::to_string(patch());
}