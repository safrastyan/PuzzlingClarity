bool validTime(std::string time) 
{
    if (time.size() != 5) {
        return false;
    }
    
    if (time[2] != ':') {
        return false;
    }

    if (!std::isdigit(time[0]) || !std::isdigit(time[1]) || !std::isdigit(time[3]) || !std::isdigit(time[4])) {
        return false;
    }

    if (std::stoi(time.substr(0, 2)) >= 24) {
        return false;
    }

    if (std::stoi(time.substr(3, 2)) >= 60) {
        return false;
    }

    return true;
}
