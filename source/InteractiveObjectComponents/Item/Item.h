//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_ITEM_H
#define OOP_GAME_ITEM_H

#include "../InteractiveObject/InteractiveObject.h"
#include <string>

class Item: public InteractiveObject {
protected:
    std::string item_name;
    int bonus_attack;
    int bonus_stamina;
    int bonus_defence;
public:
    // Constructor
    Item(std::string item_name = "Unnamed artifact", int bonus_attack = 0, int bonus_stamina = 0, int bonus_defence = 0);
    ~Item() = default;

    // Getter
    std::string getName();
    int getBonusAttack();
    int getBonusStamina();
    int getBonusDefence();

    // Pattern: Prototype
    virtual InteractiveObject* clone();

    // No setters for safety

};

#endif //OOP_GAME_ITEM_H
