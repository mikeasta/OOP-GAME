//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_ITEMPLACER_H
#define OOP_GAME_ITEMPLACER_H

#include "../Item/Item.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <type_traits>

class ItemPlacer {
private:
    std::map<std::string, std::vector<int>> item_voc = {
            { "Light rune of damage",  {5, 0, 0} },
            { "Medium rune of damage", {15, 0, 0} },
            { "Large rune of damage",  {30, 0, 0} },
            { "Light rune of stamina", {0, 5, 0} },
            { "Medium rune of stamina",{0, 25, 0} },
            { "Strong rune of stamina",{0, 100, 0} },
            { "Light rune of defence", {0, 0, 5} },
            { "Medium rune of defence",{0, 0, 25} },
            { "Large rune of defence", {0, 0, 50} },
    };
public:
    void place(Item* curr_item, Cell* curr_cell);
    void fillField(Field &field);
};

#endif //OOP_GAME_ITEMPLACER_H
