# dmlogger

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[dmlogger GitHub](https://github.com/brinkqiang/dmlogger)

## Build status
| [Linux][lin-link] | [MacOSX][osx-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![osx-badge]       | ![win-badge]        |

[lin-badge]: https://travis-ci.org/brinkqiang/dmlogger.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/brinkqiang/dmlogger "Travis build status"
[osx-badge]: https://travis-ci.org/brinkqiang/dmlogger.svg?branch=master "Travis build status"
[osx-link]:  https://travis-ci.org/brinkqiang/dmlogger "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/github/brinkqiang/dmlogger?branch=master&svg=true "AppVeyor build status"
[win-link]:  https://ci.appveyor.com/project/brinkqiang/dmlogger "AppVeyor build status"

## Intro
C++ format logging library. based on glog & fmt.
```cpp

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

```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmlogger/Lobby.svg)](https://gitter.im/brinkqiang/dmlogger)

## Thanks
