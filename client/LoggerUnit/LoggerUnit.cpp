//
// Created by mikeasta on 16.11.2021.
//
#include <fstream>
#include "LoggerUnit.h"

LoggerUnit::LoggerUnit(std::ostream &output_stream, bool is_output_enable, std::string logger_unit_id):
    output_stream(output_stream),
    is_output_enable(is_output_enable),
    logger_unit_id(logger_unit_id) {}

LoggerUnit::~LoggerUnit() {
    if (output_stream) {
        if (typeid(output_stream).name() == typeid(std::fstream).name() &&
                !static_cast<std::fstream&>(output_stream).is_open()) {
            dynamic_cast<std::ofstream*>(&output_stream)->close();
        }
    }
}

void LoggerUnit::log(std::string message) {
    if (is_output_enable) {
        output_stream << message;
    }
}

void LoggerUnit::toggleOutput() {
    is_output_enable = !is_output_enable;
}

std::string LoggerUnit::getId() const {
    return logger_unit_id;
}