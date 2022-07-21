//
// Created by Павло Коваль on 21.07.2022.
//

#include "TimeWorker.h"

std::string TimeWorker::getCurrentTime()  {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
