#include "Logs.h"

using namespace ShatteredEngine_Utils;

void Logs::WriteLog(Logs::LogType pType, char* pMessage)
{
    char _buffer[26];
    time_t _time = NULL;

    time(&_time);
    const errno_t _err = ctime_s(_buffer, 26, &_time);

    if (_err != 0)
    {
        std::cout << "Error when loading time !" << std::endl;
    }
    
    // Remove \n of the string
    _buffer[strcspn(_buffer, "\r\n")] = '\0';

    // [Time] - [LogType]: Message
    switch (pType)
    {
    case LogType::INFO:
        std::cout << termcolor::white << "[" << termcolor::green << _buffer << termcolor::white << "] - [" << termcolor::green << "INFO" << termcolor::white << "]: " << termcolor::green << pMessage << termcolor::reset << std::endl;
        break;
    case LogType::WARN:
        std::cout << termcolor::white << "[" << termcolor::yellow << _buffer << termcolor::white << "] - [" << termcolor::yellow << "WARNING" << termcolor::white << "]: " << termcolor::yellow << pMessage << termcolor::reset << std::endl;
        break;
    case LogType::ERR:
        std::cout << termcolor::white << "[" << termcolor::red << _buffer << termcolor::white << "] - [" << termcolor::red << "ERROR" << termcolor::white << "]: " << termcolor::red << pMessage << termcolor::reset << std::endl;
        break;
    }
}