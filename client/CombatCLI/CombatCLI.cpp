//
// Created by mikeasta on 18.10.2021.
//

#include "CombatCLI.h"

void CombatCLI::setLastCombat(Combat new_combat) { last_combat = new_combat; }

void CombatCLI::print() {
    std::map<std::string, unsigned int> details = last_combat.getCombatDetails();
    if (!details["player_damage_done"])
        return;

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

    std::cout << std::endl;
}