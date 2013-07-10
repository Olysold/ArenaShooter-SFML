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

enum class Severity
{
    None,
    Info,
    Minor,
    Major
};

namespace util
{
    std::string getDate();
    std::string enumToString(Status);
    std::string enumToString(Severity);

    template <class T> std::string PODToString(T type)
    {
        std::stringstream ss;
        ss << type;
        return ss.str();
    }
}

#endif
