//
// Created by mikeasta on 16.10.2021.
//

#include "Game.h"

#include <termios.h>
#include <unistd.h>
#include <iostream>

//для установления ввода символов в терминале в режим, не требующий перевода строки
void clear_input()
{
    static struct termios told, tnew;
    tcgetattr(STDIN_FILENO, &told);
    tnew = told;
    tnew.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &tnew);
}

void Game::start() {
    if (!game_is_started) {
        clear_input();
        game_is_started = true;
        unsigned int field_rows = 5, field_cols = 7;
        RandomNumberGenerator randomizer;
        FieldGenerator generator = FieldGenerator();
        Cell*** cells = generator.generateField(field_rows, field_cols);
        Field new_field = Field(cells, field_rows, field_cols);
        Player new_player = Player(10, 10, 10);
        FieldCLI new_field_cli = FieldCLI(&new_field);

        // Fill field
        FieldAggregate aggregator;
        aggregator.aggregate(&new_field, &new_player);
        PlayerController player_controller = PlayerController(&new_player, &new_field);

        bool game_goes = true;
        std::string command = "";
        while (game_goes) {

            // Print
            std::cout << "\x1B[2J\x1B[H";
            new_field_cli.print();

            // Player move
            std::cin >> command;
            if (sizeof(command)) {
                // get char
                std::string response = player_controller.move(command);
                if (response == "EXIT")
                    game_goes = false;
            }

            command = *"";
            sleep(0.1);
        }
    }
}

