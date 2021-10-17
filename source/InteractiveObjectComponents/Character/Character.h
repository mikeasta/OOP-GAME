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
public:
    // Constructors
    Character(int damage = 0, int stamina = 0, int defence = 0);
    ~Character() = default;

    // Getters
    int getDamage() const;
    int getStamina() const;
    int getDefence() const;

    // Setters
    void buffDamage(int val);
    void buffStamina(int val);
    void buffDefence(int val);

    void get_combat_damage(int val);


    virtual void stepOnCell(Cell* cell);
    virtual void spawn(Field* field, unsigned int x = 0, unsigned int y = 0);

    // Pattern: Prototype
    virtual InteractiveObject* clone();
};

#endif //OOP_GAME_CHARACTER_H
