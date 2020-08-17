#ifndef UTILS_LOGS_H
#define UTILS_LOGS_H

#include <ctime>
#include <iostream>
#include <chrono>
#include <string>
#include <cstring>
#include "../../3rdParty/termcolor/include/termcolor/termcolor.hpp"

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

    static void WriteLog(Logs::LogType pType, char* pMessage);
    };    
}

#endif //UTILS_LOGS_H