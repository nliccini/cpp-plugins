#ifndef __LOGGER_H
#define __LOGGER_H

#if defined(_WIN32)
    // Windows
    #define EXPORT __declspec(dllexport)
#else
    // Linux
    #define EXPORT __attribute__((visibility("default")))
#endif

#include <string>
#include <ilogger.h>

class logger : public i::logger {
    public:
        logger();
        ~logger();

        void log();

    private:
        int _counter;
};

extern "C" EXPORT std::string version()
{
    return "0.0.1";
}

extern "C" EXPORT i::logger * create_logger()
{
    return new logger();
};

#endif // __LOGGER_H
