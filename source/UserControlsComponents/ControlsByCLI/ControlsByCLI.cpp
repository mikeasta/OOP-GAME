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

    // Check, if there are no any key with new_bind
    if (binds.count(new_bind) == 0) {
        std::pair<std::string, std::string> pair_to_change;
        for (auto pair: binds) {
            if (pair.second == command) {
                pair_to_change = pair;
                break;
            }
        }
        this->binds.erase(pair_to_change.first);
        this->binds[new_bind] = command;
    } else {
        std::pair<std::string, std::string> pair_to_change;
        for (auto pair: binds) {
            if (pair.second == command) {
                pair_to_change = pair;
                break;
            }
        }

        std::pair<std::string, std::string> duplicate_pair;
        for (auto pair: binds) {
            if (pair.first == new_bind) {
                duplicate_pair = pair;
                break;
            }
        }

        this->binds.erase(new_bind);
        this->binds.erase(pair_to_change.first);
        this->binds[pair_to_change.first] = duplicate_pair.second;
        this->binds[new_bind] = command;
    }
}