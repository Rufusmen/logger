//
// Created by rufus on 25.12.17.
//

#ifndef LOGICON_LOGGER_H
#define LOGICON_LOGGER_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
#define LOGGER Logger::getLogger()
/**
*   @brief Singleton Logger Class.
*   @note Logger file will be created in the same dir as built project.
*   @example LOGGER->err(" x var should be: %d and is: %d",x_should,x);
*/
class Logger
{
public:
    Logger(std::string path);
    /**
    *   @brief Logs info massage
    *   @param format string for the message to be logged.
    */
    void info(const char * format, ...);
    /**
    *   @brief Logs error massage
    *   @param format string for the message to be logged.
    */
    void err(const char * format, ...);
    /**
    *   @brief Logs warning massage
    *   @param format string for the message to be logged.
    */
    void warn(const char * format, ...);
    /**
    *   @brief Funtion to create the instance of logger class.
    *   @return singleton object of Clogger class..
    */
    static Logger* getLogger();
private:
    /**
    *    Default constructor for the Logger class.
    */
    Logger();
    /**
    *   copy constructor for the Logger class.
    */
    Logger(const Logger&){};             // copy constructor is private
    /**
    *   assignment operator for the Logger class.
    */
    Logger& operator=(const Logger&){ return *this; };  // assignment operator is private
    /**
    *   Log file name.
    **/
    static std::string logFileName;
    /**
    *   Singleton logger class object pointer.
    **/
    static Logger* logThis;
    /**
    *   Log file stream object.
    **/
    static std::ofstream logfile;
};
#endif //LOGICON_LOGGER_H