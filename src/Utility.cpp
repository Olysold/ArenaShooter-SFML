#include "Utility.hpp"

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

std::string util::enumToString(Severity sev)
{
    switch (sev)
    {
    case Severity::None:
        return "None";
        break;
    case Severity::Info:
        return "Info";
        break;
    case Severity::Minor:
        return "Minor";
        break;
    case Severity::Major:
        return "Major";
        break;
    default:
        return "Unknown Severity";
        break;
    }

    return "Unknown Severity2";
}
