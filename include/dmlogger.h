
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMLOGGER_H_INCLUDE__
#define __DMLOGGER_H_INCLUDE__

#define GOOGLE_GLOG_DLL_DECL
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include "dmutil.h"
#include "dmformat.h"

#include "config.h"

#include <limits.h>

#include "glog/logging.h"
#include "glog/raw_logging.h"
#include "glog/stl_logging.h"
#include "glog/log_severity.h"

#include "utilities.h"

using namespace GOOGLE_NAMESPACE;

class CDMLogger
{
public:
       CDMLogger()
       : m_argv0("dmlogger")
       {
           InitGoogleLogging(m_argv0);
           __Init();
       }
       
       CDMLogger(const char* argv0)
       : m_argv0(argv0)
       {
           InitGoogleLogging(m_argv0);
           __Init();
       }
       
       ~CDMLogger()
       {
           ShutdownGoogleLogging();
       }
       
private:
        void __Init()
        {
            FLAGS_max_log_size = 4096;
            FLAGS_stop_logging_if_full_disk = false;
            FLAGS_alsologtostderr = true;
            FLAGS_logtostderr = false;
            FLAGS_colorlogtostderr = true;
            FLAGS_minloglevel = 0;
            FLAGS_logbufsecs = 0;
            FLAGS_logcloselevelrepeat = true;
            
            FLAGS_log_dir = DMGetRootPath();
        }        
private:
        const char* m_argv0;
};


#define DM_INFO(...)		do{ LOG(INFO) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_WARN(...)		do{ LOG(WARNING) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_CRITICAL(...)	do{ LOG(ERROR) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_FATAL(...)		do{ LOG(FATAL) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_INFO_IF(condition, ...)         do{ LOG_IF(INFO, condition) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_WARN_IF(condition, ...)         do{ LOG_IF(WARNING, condition) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_CRITICAL_IF(condition, ...)     do{ LOG_IF(ERROR, condition) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_FATAL_IF(condition, ...)        do{ LOG_IF(FATAL, condition) << std::move(fmt::format(__VA_ARGS__));}while(0)

#define DM_ASSERT(condition)          LOG_ASSERT(condition)

#define DMLOGGER_INIT()               CDMLogger oInitGoogleLogging
#define DMLOGGER_INIT_ARG(name)       CDMLogger oInitGoogleLogging(name)


#endif // __DMLOGGER_H_INCLUDE__
