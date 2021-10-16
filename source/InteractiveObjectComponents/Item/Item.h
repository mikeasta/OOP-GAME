//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_ITEM_H
#define OOP_GAME_ITEM_H

#include "../InteractiveObject/InteractiveObject.h"
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"

class Item: public InteractiveObject {
protected:
    std::string item_name;
    int bonus_attack;
    int bonus_stamina;
    int bonus_defence;
public:
    // Constructor
    Item() {};
    Item(std::string item_name, int bonus_attack, int bonus_stamina, int bonus_defence);
    ~Item() = default;

    // Getter
    std::string getName();
    int getBonusAttack();
    int getBonusStamina();
    int getBonusDefence();

    // Pattern: Prototype
    // Clones current Item
    virtual InteractiveObject* clone();

    // Pattern: Factory Method
    // Creates Item object with item type
    Item* create(std::string item_type);
    // Creates random Item object with item type
    Item* create();
};

#endif //OOP_GAME_ITEM_H
