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
        unsigned int field_rows = 5, field_cols = 10;
        RandomNumberGenerator randomizer;
        FieldGenerator generator = FieldGenerator();
        Cell*** cells            = generator.generateField(field_rows, field_cols);
        Field new_field          = Field(cells, field_rows, field_cols);
        Player new_player        = Player(10, 100, 20);
        FieldCLI new_field_cli   = FieldCLI(&new_field);
        PlayerCLI new_player_cli = PlayerCLI(&new_player);
        CombatCLI combat_drawer  = CombatCLI();

        // Fill field
        FieldAggregate aggregator;
        aggregator.aggregate(&new_field, &new_player);
        PlayerController player_controller = PlayerController(&new_player, &new_field);

        // Detect all enemies
        EnemyManageCenter enemy_center = EnemyManageCenter(&new_field);

        bool game_goes = true;
        std::string command;
        system("clear");
        while (game_goes) {

            // Enemy stepping
            enemy_center.move_all();

            // Print
            new_field_cli.print();
            new_player_cli.print();

            // Player move
            std::cin >> command;
            if (sizeof(command)) {

                // get char
                std::pair<std::string, Combat> response = player_controller.move(command);
                system("clear");
                if (response.first == "WIN" ||
                    response.first == "DRAW" ||
                    response.first == "LOSS") {

                    // Draw combat
                    combat_drawer.print(response.second);
                }

                if (response.first == "EXIT" || response.first == "LOSS")
                    game_goes = false;
            }

            command = *"";
            sleep(0.1);
        }
    }
}

