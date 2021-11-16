//
// Created by mikeasta on 16.11.2021.
//

#ifndef OOP_GAME_LOGGERUNIT_H
#define OOP_GAME_LOGGERUNIT_H
#include <fstream>
#include <string>
#include <iostream>

class LoggerUnit {
private:
    std::ostream& output_stream = std::cout;
    bool is_output_enable = true;
    std::string logger_unit_id;
public:
    // Constructor
    LoggerUnit(std::ostream& output_stream, bool is_output_enable, std::string logger_unit_id);
    ~LoggerUnit();

    // Log func.
    void log(std::string message);

    // Setter
    void toggleOutput();

    // Getter
    bool isOutputEnable() const;
    std::string getId() const;
};

#endif //OOP_GAME_LOGGERUNIT_H
