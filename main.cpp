#include <iostream>
#include "logger.h"

int main() {
    Logger("nowylog.txt");
    LOGGER->info("Chyba działa");
    int x=5,y=x--;
    LOGGER->err("x jest: %d , a miał byc %d",y,x);
    LOGGER->warn("innyy stuff : %c %f %0.1lf",'a',0.5123123,847387.312312);
    return 0;
}