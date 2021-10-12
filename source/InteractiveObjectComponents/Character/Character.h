//
// Created by mikeasta on 12.10.2021.
//

#ifndef OOP_GAME_CHARACTER_H
#define OOP_GAME_CHARACTER_H

#include "../../CellComponents/Cell/Cell.h"
#include "../InteractiveObject/InteractiveObject.h"
#include <tuple>
#include <string>

class Character: public InteractiveObject {
private:
    int damage;
    int stamina;
    int defence;
    Cell* curr_cell = nullptr;
public:
    // Constructors
    Character(int damage = 0, int stamina = 0, int defence = 0);
    virtual ~Character();

    // Getters
    int getDamage();
    int getStamina();
    int getDefence();
    Cell* getCurrentCell() const;

    // Setters
    void setDamage(int val);
    void buffDamage(int val);
    void setStamina(int val);
    void buffStamina(int val);
    void setDefence(int val);
    void buffDefence(int val);
    void setCurrentCell(Cell* new_curr_cell);
    virtual void placeOntoCell(Cell* cell);
};

#endif //OOP_GAME_CHARACTER_H
