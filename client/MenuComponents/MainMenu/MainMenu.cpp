//
// Created by mikeasta on 23.11.2021.
//

#include "MainMenu.h"

void MainMenu::call(ControlsInterface& control_interface) {
    Controls controls_menu = Controls();
    bool is_running = true;
    size_t curr_menu_pointer = 0;
    while(is_running) {
        system("clear");
        std::cout << "\n================================================================================";
        std::cout << "\n                                 OOP - GAME                                     ";
        std::cout << "\n================================================================================";

        // 1. Start game
        // 2. Controls
        // 3. Exit
        std::string menu_pointer = "\n> ";
        for (size_t i = 0; i < __menu_options.size(); i++) {
            std::cout << (curr_menu_pointer == i ? menu_pointer : "\n") + __menu_options[i];
        }

        std::cout << "\n================================================================================";
        std::cout << "\n Use \"w\" and \"s\" to switch between options. Enter \"1\" to accept :";
        char option = *"";
        std::cin >> option;

        if (option == *"w" || option == *"s") {
            if (option == *"w" & curr_menu_pointer > 0) {
                curr_menu_pointer--;
            } else if (option == *"s" & curr_menu_pointer < __menu_options.size() - 1) {
                curr_menu_pointer++;
            }
        } else if (option == *"1") {
            switch (curr_menu_pointer) {
                case 0: is_running = false; break;
                case 1: controls_menu.call(control_interface); break;
                case 2: exit(EXIT_SUCCESS);
            }
        }
    }
}

