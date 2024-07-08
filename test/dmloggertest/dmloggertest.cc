
#include "dmlogger.h"

int main(int argc, const char *const argv[])
{
    DMLOGGER_INIT();

    DM_WARN_IF(0, "{1}{0} {2}", "world", "hello", "DM_WARN_IF");
    DM_WARN_IF(1, "{1}{0} {2}", "world", "hello", "DM_WARN_IF");

    DM_INFO("{1}{0} {2}", "world", "hello", "DM_INFO");
    DM_WARN("{1}{0} {2}", "world", "hello", "DM_WARN");
    DM_CRITICAL("{1}{0} {2}", "world", "hello", "DM_CRITICAL");

    //DM_FATAL("{1}{0} {2}", "world", "hello",  "DM_WARN_IF");
    return 0;
}