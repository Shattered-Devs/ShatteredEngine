#ifndef UTILS_LOGS_H
#define UTILS_LOGS_H

#include <ctime>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <cstring>
#include <termcolor/termcolor.hpp>

namespace ShatteredEngine_Utils
{
    class Logs
    {
    public:
    enum class LogType
    {
        INFO,
        WARN,
        ERR
    };

    static void WriteLog(Logs::LogType pType, char const *pMessage);
    };    
}

#endif //UTILS_LOGS_H