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
public:
    void place(Item* curr_item, Cell* curr_cell);
    void fillField(Field* field);
};

#endif //OOP_GAME_ITEMPLACER_H
