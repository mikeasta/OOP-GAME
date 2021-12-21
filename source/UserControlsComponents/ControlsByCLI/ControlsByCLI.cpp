//
// Created by mikeasta on 21.12.2021.
//

#include "ControlsByCLI.h"

ControlsByCLI::ControlsByCLI(std::map<std::string, std::string> binds) {
    size_t new_binds_set_size = binds.size();

    if (new_binds_set_size > 0) {
        this->binds = binds;
    }
}

std::string ControlsByCLI::listen() {
    std::string key;
    auto response_lib = Response().getResponseLib();
    std::cin >> key;

    // Check if key in binds
    return binds.count(key) != 0 ? binds[key] : response_lib["not_found"];
}

std::map<std::string, std::string> ControlsByCLI::getBinds() {
    return binds;
}

void ControlsByCLI::changeBind(std::string command, std::string new_bind) {

    // Check, if there are already any key with new_bind
    if (binds.count(new_bind) != 0) {
        auto pair_to_change = binds.find(command);
        std::string duplicate_command = binds[new_bind];

        binds[new_bind]               = pair_to_change->second;
        binds[pair_to_change->first]  = duplicate_command;
    } else {
        auto pair_to_change = binds.find(command);
        binds.erase(pair_to_change->first);
        binds[new_bind] = command;
    }
}