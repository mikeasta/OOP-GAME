//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_PLAYER_H
#define OOP_GAME_PLAYER_H

#include "../Character/Character.h"
#include "../Equipment/Equipment.h"
#include "../Item/Item.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <string>

class Player: public Character {
private:
    Equipment* equipment;
    bool is_spawned = false;
public:
    Player(int damage = 0, int stamina = 0, int defence = 0);
    virtual ~Player() = default;

    // Combat states
    int getFullDamage() const;
    int getFullStamina() const;
    int getFullDefence() const;

    void take(Item* item);
    virtual void spawn(Field* field, unsigned int x = 0, unsigned int y = 0) final;

    std::string attack(Character* opponent);
};

#endif //OOP_GAME_PLAYER_H
