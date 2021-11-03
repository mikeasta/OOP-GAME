//
// Created by mikeasta on 18.10.2021.
//

#include "Combat.h"

Combat::Combat(unsigned int player_damage_done,
       bool is_player_critical,
       unsigned int enemy_damage_done,
       bool is_enemy_critical, bool is_player_died, bool is_enemy_died):
       player_damage_done(player_damage_done),
       is_player_critical(is_player_critical),
       enemy_damage_done(enemy_damage_done),
       is_enemy_critical(is_enemy_critical),
       is_player_died(is_player_died),
       is_enemy_died(is_enemy_died) {}

Combat::Combat(CombatDetailsStruct details):
        player_damage_done(details.player_damage_done),
        is_player_critical(details.is_player_critical),
        enemy_damage_done(details.enemy_damage_done),
        is_enemy_critical(details.is_enemy_critical),
        is_player_died(details.is_player_died),
        is_enemy_died(details.is_enemy_died) {}

std::map<std::string, unsigned int> Combat::getCombatDetails() const {
    return {
        { "player_damage_done", player_damage_done },
        { "is_player_critical", is_player_critical },
        { "enemy_damage_done",  enemy_damage_done },
        { "is_enemy_critical",  is_enemy_critical },
        { "is_player_died",      is_player_died },
        { "is_enemy_died",      is_enemy_died }
    };
}

std::string Combat::getCombatDetailsToString() const {
    std::string result;
    result += ("Player done " + std::to_string(player_damage_done) + " damage" );
    if (is_player_critical) {
        result += " (critical)";
    }

    if (is_enemy_died) {
        result += ". Enemy died.";
        return result;
    }

    result += (". Enemy done " + std::to_string(enemy_damage_done) + " damage");
    if (is_enemy_critical) {
        result += " (critical)";
    }

    if (is_player_died) {
        result += ". Player died.";
        return result;
    }
}