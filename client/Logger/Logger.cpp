//
// Created by mikeasta on 03.11.2021.
//

#include "Logger.h"
Logger::Logger (Controller& controller):
    controller(controller) {};

Logger::~Logger() {
    std::cout << "file";
    std::ofstream fout;
    fout.open(filepath);
    if (fout.is_open()) {
        fout << "";
    }
    fout.close();
}

std::ostream& operator<<(std::ostream &out, const Logger &logger) {
    out << logger.controller.popUpdate();
    return out;
}

void Logger::log() {
    std::string update_string = controller.popUpdate();

    if (log_to_console) {
        std::cout << update_string;
    }

    if (log_to_file) {
        std::cout << "file";
        std::ofstream fout;
        fout.open(filepath, std::ios_base::app);
        if (fout.is_open()) {
            fout << update_string;
        }
        fout.close();
    }
}