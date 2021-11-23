//
// Created by mikeasta on 23.11.2021.
//

#include "Controls.h"

void Controls::call(std::map<std::string, char> &controls) {
    while(true) {
        system("clear");
        std::cout << "\n================================================================================";
        std::cout << "\n                            OOP - GAME - Controls                               ";
        std::cout << "\n================================================================================";

        for (auto control_unit: controls) {
            std::cout << "\n" << control_unit.first << " - " << control_unit.second;
        }

        std::cout << "\n================================================================================";
        std::cout << "\n Type \"up\", \"left\", \"down\" or \"right\" to change control key.";
        std::cout << "\nEnter \"1\" to return to main menu: ";
        std::string option = "";
        std::cin >> option;
        std::cout << "\nOption: " << option;

        // Exit Controls
        if (option == "1") {
            return;
        } else if (option == "up" || option == "left" || option == "down" || option == "right") {
            std::cout << "\n================================================================================";
            std::cout << "\n Type a key to change " << option << " key:";
            char new_key = *"";
            char old_key = controls[option];
            std::cin >> new_key;
            std::cout << "\nNew-Key: " << new_key;

            controls[option] = new_key;

            for (auto control_unit: controls) {
                if ((control_unit.second == new_key) & (option != control_unit.first)) {
                    controls[control_unit.first] = old_key;
                }
            }
        }
    }
}