#include "util.hpp"

#include <ctime>

std::string util::getDate()
{
    time_t timer;
    timer = time(nullptr);

    struct tm* date = localtime(&timer);

    std::stringstream ss;

    ss  << (date->tm_year+1900) << "/"
        << (date->tm_mon+1) << "/"
        << date->tm_mday <<  ", "
        << date->tm_hour << ":"
        << date->tm_min << ":"
        << date->tm_sec;

    return ss.str();
}

std::string util::enumToString(Status stat)
{
    switch (stat)
    {
    case Status::AlreadyOpen:
        return "Already Open";
        break;
    case Status::FailedToOpen:
        return "Failed To Open";
        break;
    case Status::NotGood:
        return "Not Good";
        break;
    case Status::Success:
        return "Success";
        break;
    default:
        return "Unknown Status";
        break;
    }

    return "Unknown Status2";
}

float util::degToRad(float degrees)
{
    return (degrees / 180.f) * 3.141592653;
}

float util::radToDeg(float radians)
{
    return (radians * 180.f) / 3.141592653;
}
