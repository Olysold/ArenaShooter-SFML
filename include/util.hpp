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

enum Direction
{
    N0 = 0,
    N360 = 360,
    S = 180,
    E = 90,
    W = 270,
    NE = 45,
    SE = 135,
    NW = 315,
    SW = 225
};

namespace util
{
    std::string getDate();
    std::string enumToString(Status);
    float       degToRad(float degrees);
    float       radToDeg(float radians);
    bool        isNegative(const double);

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
