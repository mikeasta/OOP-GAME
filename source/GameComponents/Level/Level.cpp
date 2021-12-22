//
// Created by mikeasta on 21.12.2021.
//

#include "Level.h"

Level::Level(Field &field, Player &player, ControlsManager& controls_manager):
    field(field),
    player(player),
    controls_manager(controls_manager){
}

void Level::game_end() {
    std::map<std::string, std::string> response_lib = Response().getResponseLib();
    result    = response_lib["game_end"];
    game_goes = false;
}

std::string Level::start() {
    game_goes = true;
    std::string command;

    // ############# TEST FILE STREAM #############
    std::ofstream out;
    out.open("/home/mikeasta/Programming/OOP-GAME/source/GameComponents/Game/output.txt");
    // ############################################


    // ############# RESPONSE ENGINE #############
    auto response_lib = Response().getResponseLib();
    // ###########################################


    // ############# FIELD, PLAYER & ENEMIES INIT. #############
    auto player_controller = PlayerController(player, field);
    auto enemy_center      = EnemyManageCenter(field);
    // #########################################################


    // ############# TASK MANAGER SETUP #############
    auto field_observer = FieldObserver(field);
    auto field_stats = field_observer.getFieldStats();
    auto ct = CollectionerTask(field_stats);
    auto tm = TaskManager<CollectionerTask>(ct);
    //################################################


    // ############# LOGGER SETUP #############
    ControllerObserver cont_obs;
    cont_obs.addController(&player_controller);
    auto logger = Logger(cont_obs);
    logger.addLoggerUnit(std::cout, true, "cout");
    logger.addLoggerUnit(out, true, "output");
    // ########################################


    // ############# UI SETUP #############
    system("clear");
    auto new_field_cli  = FieldCLI(field);
    auto new_player_cli = PlayerCLI(player);
    auto combat_drawer  = CombatCLI();
    auto equipment_cli  = EquipmentCLI(player);
    auto task_cli       = TaskCLI<CollectionerTask>(tm);
    // ####################################


    // ############# GAME LOOP #############
    bool isTaskDone;
    while (game_goes) {

        // ############# ENEMY STEPPING #############
        enemy_center.move_all();
        // ##########################################


        // ############# UI PRINTING #############
        new_field_cli.print();
        task_cli.print();
        combat_drawer.print();
        new_player_cli.print();
        equipment_cli.print();
        logger.log();
        // #######################################


        // ############# EVENT LISTENING #############
        std::pair<std::string, Combat> response;
        command = controls_manager.listen();
        if (controls_manager.checkForMovement(command)) {
            response = player_controller.move(command);
        } else if (controls_manager.checkForSaving(command)) {
            SerializeWriter writer;
            writer.write(field, player);
        } else if (controls_manager.checkForLoading(command)) {
            result = response_lib["game_load"];
        }

        isTaskDone = tm.update(field_observer.getFieldStats(), response.first);
        system("clear");
        // ###########################################


        // ############# CHECKING FOR PLAYER STATE #############
        if (isTaskDone) {
            player_controller.enableLeaving();
        }

        if (response.first == response_lib["win"] ||
            response.first == response_lib["draw"] ||
            response.first == response_lib["loss"]) {

            // Draw combat
            combat_drawer.setLastCombat(response.second);
        }

        if (response.first == response_lib["exit"] || response.first == response_lib["loss"]) {
            game_end();
        }
        // ####################################################

    }

    return result;
}

