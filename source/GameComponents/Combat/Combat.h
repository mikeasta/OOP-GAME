//
// Created by mikeasta on 18.10.2021.
//

#ifndef OOP_GAME_COMBAT_H
#define OOP_GAME_COMBAT_H

#include <map>
#include <string>

struct CombatDetailsStruct {
    unsigned int player_damage_done = 0;
    bool is_player_critical = false;
    unsigned int enemy_damage_done = 0;
    bool is_enemy_critical = false;
    bool is_enemy_died = false;
};

class Combat {
private:
    unsigned int player_damage_done;
    bool is_player_critical;
    unsigned int enemy_damage_done;
    bool is_enemy_critical;
    bool is_enemy_died;
public:
    explicit Combat(unsigned int player_damage_done = 0,
        bool is_player_critical = false,
        unsigned int enemy_damage_done = 0,
        bool is_enemy_critical = false,
        bool is_enemy_died = false);

    explicit Combat(CombatDetailsStruct details);

    std::map<std::string, unsigned int> getCombatDetails() const;
};

#endif //OOP_GAME_COMBAT_H
