//
// Created by mikeasta on 18.10.2021.
//

#include "CombatCLI.h"

void CombatCLI::print(Combat combat_results) {
    std::map<std::string, unsigned int> details = combat_results.getCombatDetails();

    std::cout << "\nCombat:";
    std::cout << "\nPlayer done " << details["player_damage_done"] << " damage. ";
    if (details["is_player_critical"])
        std::cout << "(Critical)";

    if (details["is_enemy_died"]) {
        std::cout << "\nEnemy died";
        return;
    }

    std::cout << "\nOpponent done " << details["enemy_damage_done"] << " damage. ";
    if (details["is_enemy_critical"])
        std::cout << "(Critical)";
}