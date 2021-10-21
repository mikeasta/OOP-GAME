//
// Created by mikeasta on 18.10.2021.
//

#include "Combat.h"

Combat::Combat(unsigned int player_damage_done,
       bool is_player_critical,
       unsigned int enemy_damage_done,
       bool is_enemy_critical, bool is_enemy_died):
       player_damage_done(player_damage_done),
       is_player_critical(is_player_critical),
       enemy_damage_done(enemy_damage_done),
       is_enemy_critical(is_enemy_critical),
       is_enemy_died(is_enemy_died) {}

std::map<std::string, unsigned int> Combat::getCombatDetails() const {
    return {
        { "player_damage_done", player_damage_done },
        { "is_player_critical", is_player_critical },
        { "enemy_damage_done",  enemy_damage_done },
        { "is_enemy_critical",  is_enemy_critical },
        { "is_enemy_died",      is_enemy_died }
    };
}
