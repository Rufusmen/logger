//
// Created by rufus on 25.12.17.
//

#include "logger.h"
std::string Logger::logFileName;
Logger* Logger::logThis = NULL;
std::ofstream Logger::logfile;
int _vscprintf (const char * format, va_list pargs) {
    int retval;
    va_list argcopy;
    va_copy(argcopy, pargs);
    retval = vsnprintf(nullptr, 0, format, argcopy);
    va_end(argcopy);
    return retval;
}

const std::string time(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
    std::string str(buffer);
    return str;
}

Logger::Logger() { logFileName = "Logicon.log"; }

Logger* Logger::getLogger(){
    if (logThis == nullptr){
        logThis = new Logger();
        logfile.open(logFileName.c_str(), std::ios::out | std::ios::app);
    }
    return logThis;
}

void Logger::info(const char * format, ...)
{
    char* sMessage = nullptr;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsnprintf(sMessage, nLength, format, args);
    logfile << time() << "[INFO]:\t";
    logfile << sMessage << "\n";
    va_end(args);

    delete [] sMessage;
}
void Logger::err(const char * format, ...)
{
    char* sMessage = nullptr;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsnprintf(sMessage, nLength, format, args);
    logfile << time() << "[ERR]:\t";
    logfile << sMessage << "\n";
    va_end(args);

    delete [] sMessage;
}
void Logger::warn(const char * format, ...)
{
    char* sMessage = nullptr;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsnprintf(sMessage, nLength, format, args);
    logfile << time() << "[WARN]:\t";
    logfile << sMessage << "\n";
    va_end(args);

    delete [] sMessage;
}

Logger::Logger(std::string path) {
    if (logThis == nullptr){
        Logger::logFileName = path;
        logThis = new Logger();
        logfile.open(path.c_str(), std::ios::out | std::ios::app);
    }
}
