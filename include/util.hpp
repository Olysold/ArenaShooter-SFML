#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

//STD
#include <sstream>
#include <string>

enum class Status
{
    Success,
    FailedToOpen,
    NotGood,
    AlreadyOpen
};

namespace util
{
    std::string getDate();
    std::string enumToString(Status);
    float       degToRad(float degrees);
    float       radToDeg(float radians);

    template <class T> std::string PODToString(T type)
    {
        std::stringstream ss;
        ss << type;
        return ss.str();
    }
}

#endif
