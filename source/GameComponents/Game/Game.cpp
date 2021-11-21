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


        // ############# TEST FILE STREAM #############
        std::ofstream out;
        out.open("/home/mikeasta/Programming/OOP-GAME/source/GameComponents/Game/output.txt");
        // ############################################


        // ############# RESPONSE ENGINE #############
        auto response_lib = Response().getResponseLib();
        // ###########################################


        // ############# FIELD, PLAYER & ENEMIES INIT. #############
        unsigned int field_rows = 5;
        unsigned int field_cols = 10;
        auto generator  = FieldGenerator();
        auto cells      = generator.generateField(field_rows, field_cols);
        auto new_field  = Field(cells, field_rows, field_cols);
        auto new_player = Player(10, 10, 20);
        FieldAggregate aggregator;
        aggregator.aggregate(new_field, new_player);
        auto player_controller = PlayerController(new_player, new_field);
        auto enemy_center      = EnemyManageCenter(new_field);
        // #########################################################


        // ############# LOGGER SETUP #############
        ControllerObserver cont_obs;
        cont_obs.addController(&player_controller);
        auto logger = Logger(cont_obs);
        logger.addLoggerUnit(std::cout, true, "cout");
        logger.addLoggerUnit(out, true, "output");
        // ########################################


        // ############# UI SETUP #############
        char command;
        system("clear");
        auto new_field_cli  = FieldCLI(new_field);
        auto new_player_cli = PlayerCLI(new_player);
        auto combat_drawer  = CombatCLI();
        auto equipment_cli  = EquipmentCLI(new_player);
        // ####################################


        // ############# GAME LOOP #############
        while (game_goes) {

            // ############# ENEMY STEPPING #############
            enemy_center.move_all();
            // ##########################################


            // ############# UI PRINTING #############
            new_field_cli.print();
            combat_drawer.print();
            new_player_cli.print();
            equipment_cli.print();
            logger.log();
            // #######################################


            // ############# PLAYER MOVEMENT #############
            std::cin >> command;
            std::pair<std::string, Combat> response = player_controller.move(command);
            system("clear");
            // ###########################################


            // ############# CHECKING FOR PLAYER STATE #############
            if (response.first == response_lib["win"] ||
                response.first == response_lib["draw"] ||
                response.first == response_lib["loss"]) {

                // Draw combat
                combat_drawer.setLastCombat(response.second);
            }

            if (response.first == response_lib["exit"] || response.first == response_lib["loss"]) {
                stop();
            }
            // ####################################################

        }
        // #####################################

    }
}

