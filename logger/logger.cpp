#include "logger.h"

#include <iostream>

logger::logger() : _counter(0)
{

}

logger::~logger()
{
    std::cout << "Destroying logger with count " << _counter << std::endl;
}

void logger::log()
{
    std::cout << ">> Log count: " << ++_counter << std::endl;
}