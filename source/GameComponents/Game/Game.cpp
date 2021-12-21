//
// Created by mikeasta on 16.10.2021.
//

#include "Game.h"
unsigned int Enemy::s_id = 0;

void Game::stop() {
    game_goes = false;
}

void Game::start() {
    if (!game_is_started) {

        // ############# GAME KEEPPING INITIALIZING #############
        game_goes       = true;
        game_is_started = true;
        // ######################################################


        // ############# CONTROLS INITIALIZING #############
        std::string command;
        auto controls_interface = ControlsByCLI();
        auto controls_manager   = ControlsManager(controls_interface);
        // #################################################

        // ############# MAIN MENU #############
        auto menu = MainMenu();
        menu.call(controls_interface);
        // #####################################


        // ############# RESPONSE ENGINE #############
        auto response_lib = Response().getResponseLib();
        // ###########################################


        // ############# FIELD, PLAYER & ENEMIES INIT. #############
        unsigned int field_rows = 5;
        unsigned int field_cols = 10;
        auto generator  = FieldGenerator();
        auto cells      = generator.generateField(field_rows, field_cols);
        auto new_field  = Field(cells, field_rows, field_cols);
        auto new_player = Player(100, 100, 100);
        FieldAggregate aggregator;
        aggregator.aggregate(new_field, new_player);
        // #########################################################

        Level current_level = Level(new_field, new_player, controls_manager);
        while(game_goes) {
            command = current_level.start();

            if (command == response_lib["game_end"]) {
                game_goes = false;
            } else if (command == response_lib["game_load"]) {
                // Load game
            }
        }
    }
}

