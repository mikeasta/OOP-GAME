//
// Created by mikeasta on 16.10.2021.
//

#include "Game.h"

#include <termios.h>
#include <unistd.h>
#include <iostream>

void Game::stop() {
    game_goes = false;
}

void Game::start() {
    if (!game_is_started) {
        game_goes = true;
        game_is_started = true;

        unsigned int field_rows = 5;
        unsigned int field_cols = 10;
        auto generator = FieldGenerator();
        auto cells = generator.generateField(field_rows, field_cols);
        auto new_field = Field(cells, field_rows, field_cols);
        auto new_player = Player(10, 10, 20);

        auto new_field_cli  = FieldCLI(new_field);
        auto new_player_cli = PlayerCLI(new_player);
        auto combat_drawer  = CombatCLI();
        auto equipment_cli  = EquipmentCLI(new_player);

        // Fill field
        FieldAggregate aggregator;
        aggregator.aggregate(new_field, new_player);
        auto player_controller = PlayerController(new_player, new_field);

        // Detect all enemies
        auto enemy_center = EnemyManageCenter(new_field);

        char command;
        system("clear");

        while (game_goes) {

            // Enemy stepping
            enemy_center.move_all();

            // Print
            new_field_cli.print();
            combat_drawer.print();
            new_player_cli.print();
            equipment_cli.print();

            // Player move
            std::cin >> command;
            std::pair<std::string, Combat> response = player_controller.move(command);

            system("clear");
            if (response.first == "WIN" ||
                response.first == "DRAW" ||
                response.first == "LOSS") {

                // Draw combat
                combat_drawer.setLastCombat(response.second);
            }

            if (response.first == "EXIT" || response.first == "LOSS") {
                std::cout << "\nGame ends with command: " << response.first;
                stop();
            }
        }
    }
}

