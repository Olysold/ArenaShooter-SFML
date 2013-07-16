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

namespace Dir
{
    const int NE = 45;
    const int E  = 90;
    const int SE = 135;
    const int S  = 180;
    const int SW = 225;
    const int W  = 270;
    const int NW = 315;
    const int N  = 360;
}

namespace util
{
    std::string getDate();
    std::string enumToString(Status);
    float       degToRad(float degrees);
    float       radToDeg(float radians);

    template <class T1, class T2, class T3> bool isBetween(T1 a, T2 b, T3 c)
    {
        return (a > b && a < c);
    }

    template <class T> std::string PODToString(T type)
    {
        std::stringstream ss;
        ss << type;
        return ss.str();
    }
}

#endif
