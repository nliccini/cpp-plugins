#ifndef __I_LOGGER_H
#define __I_LOGGER_H

namespace i
{
    class logger {
        public:
            virtual ~logger(){}
            virtual void log() = 0;
    };
}

#endif // __I_LOGGER_H