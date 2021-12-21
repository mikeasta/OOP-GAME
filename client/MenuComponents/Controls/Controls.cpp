//
// Created by mikeasta on 23.11.2021.
//

#include "Controls.h"

void Controls::call(ControlsInterface& controls) {
    while(true) {
        system("clear");
        std::cout << "\n================================================================================";
        std::cout << "\n                            OOP - GAME - Controls                               ";
        std::cout << "\n================================================================================";

        for (auto control_unit: controls.getBinds()) {
            std::cout << "\n" << control_unit.second << " - " << control_unit.first;
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
        } else {
            std::cout << "\n================================================================================";
            std::cout << "\n Type a key to change " << option << " key:";
            std::string new_key;
            std::cin >> new_key;
            std::cout << "\nNew-Key: " << new_key;
            controls.changeBind(option, new_key);
        }
    }
}