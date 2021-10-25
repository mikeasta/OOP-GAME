//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_PLAYER_H
#define OOP_GAME_PLAYER_H

#include "../../GameComponents/Response/Response.h"
#include "../Character/Character.h"
#include "../Equipment/Equipment.h"
#include "../Item/Item.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../GameComponents/Combat/Combat.h"
#include "../Enemy/Enemy.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <string>
#include <vector>
#include <tuple>

class Player: public Character {
private:
    Equipment* equipment;
    bool is_spawned = false;
public:
    explicit Player(int damage = 0, int stamina = 0, int defence = 0);
    ~Player() override = default;

    // Combat states
    int getFullDamage() const;
    int getFullStamina() const;
    int getFullDefence() const;

    std::map<std::string, int> getEquipmentLabels();
    void take(Item* item);
    void spawn(Field &field);

    std::pair<std::string, Combat> attack(Character* opponent);
};

#endif //OOP_GAME_PLAYER_H
