//
// Created by mikeasta on 31.10.2021.
//

#include "Controller.h"


void Controller::update(std::string upd_str = "") {

    // Check for null update
    if (upd_str != "") {
        time_t now = time(0);
        struct tm tstruct;
        tstruct = *localtime((&now));
        char time_chars[8];
        strftime(time_chars, sizeof(time_chars), "%X", &tstruct);
        std::string time_string = std::string(time_chars);
        update_message += "\n[time_string]: " + upd_str;
    } else {
        update_message = upd_str;
    }
}

std::string Controller::popUpdate() {
    auto tmp = update_message;
    update("");
    return tmp;
}
