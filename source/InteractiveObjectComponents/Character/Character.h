//
// Created by mikeasta on 12.10.2021.
//

#ifndef OOP_GAME_CHARACTER_H
#define OOP_GAME_CHARACTER_H

#include "../../CellComponents/Cell/Cell.h"
#include "../../FieldComponents/Field/Field.h"
#include "../InteractiveObject/InteractiveObject.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <tuple>
#include <iostream>
#include <string>

class Character: public InteractiveObject {
protected:
    int damage;
    int stamina;
    int defence;
    Cell* curr_cell = nullptr;
public:
    // Constructors
    Character(int damage = 0, int stamina = 0, int defence = 0);
    virtual ~Character() = default;

    // Getters
    int getDamage() const;
    int getStamina() const;
    int getDefence() const;
    Cell* getCurrentCell() const;

    // Setters
    void buffDamage(int val);
    void buffStamina(int val);
    void buffDefence(int val);
    void setCurrentCell(Cell* new_curr_cell);

    virtual void stepOnCell(Cell* cell);
    virtual void spawn(Field* field, unsigned int x = 0, unsigned int y = 0);
};

#endif //OOP_GAME_CHARACTER_H
