#include "Logs.h"

using namespace ShatteredEngine_Utils;

void Logs::WriteLog(Logs::LogType pType, char const *pMessage)
{
    auto _time = std::chrono::system_clock::now();

    std::time_t _time_t = std::chrono::system_clock::to_time_t(_time);

    char *_stringTime = std::ctime(&_time_t);
    
    // Remove \n of the string
    _stringTime[strcspn(_stringTime, "\r\n")] = '\0';

    // [Time] - [LogType]: Message
    switch (pType)
    {
    case LogType::INFO:
        std::cout << termcolor::white << "[" << termcolor::green << _stringTime << termcolor::white << "] - [" << termcolor::green << "INFO" << termcolor::white << "]: " << termcolor::green << pMessage << termcolor::reset << std::endl;
        break;
    case LogType::WARN:
        std::cout << termcolor::white << "[" << termcolor::yellow << _stringTime << termcolor::white << "] - [" << termcolor::yellow << "WARNING" << termcolor::white << "]: " << termcolor::yellow << pMessage << termcolor::reset << std::endl;
        break;
    case LogType::ERR:
        std::cout << termcolor::white << "[" << termcolor::red << _stringTime << termcolor::white << "] - [" << termcolor::red << "ERROR" << termcolor::white << "]: " << termcolor::red << pMessage << termcolor::reset << std::endl;
        break;
    }
}
