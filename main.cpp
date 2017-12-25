#include "logger.h"

int main() {
    Logger::init("nowylog.txt");
    Logger::debug("Jakiś debug");
    Logger::info("Chyba działa");
    int x=5,y=x--;
    Logger::init("nowylog.txt");
    Logger::warn("innyy stuff : %c %f %0.1lf", 'a', 0.5123123, 847387.312312);
    Logger::err("x jest: %d , a miał byc %d", y, x);
    return 0;
}