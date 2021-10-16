//
// Created by mikeasta on 12.10.2021.
//

#include "Character.h"

Character::Character(int damage, int stamina, int defence):
    damage(damage),
    stamina(stamina),
    defence(defence) {};

int Character::getDamage() const { return damage; }

int Character::getStamina() const { return stamina; }

int Character::getDefence() const { return this->defence; }

void Character::buffDamage(int val) { damage += val; }

void Character::buffStamina(int val) { stamina += val; }

void Character::buffDefence(int val) {
    defence = defence + val > 100 ? 100 : defence + val;
}

void Character::stepOnCell(Cell *stepped_cell) {
    std::pair<bool, std::string> response = stepped_cell->stepEffect(this);

    if (response.first) {
        // Step done
    } else {
        // Something went wrong
        // Step rejected
    }
}

void Character::spawn(Field* field, unsigned int x, unsigned int y) {
    if (x == 0 || y == 0 || x >= field->getCols() || y >= field->getRows()) {
        bool placed = false;
        RandomNumberGenerator random_generator = RandomNumberGenerator();
        while(!placed) {
            unsigned int random_row = random_generator.generate(1, field->getRows() - 2);
            unsigned int random_col = random_generator.generate(1, field->getCols() - 2);
            Cell* cell = field->getSpecificCell(random_col, random_row);
            if (!cell->isCellContentExist()) {
                stepOnCell(cell);
                placed = true;
            }
        }
    } else {
        Cell* cell = field->getSpecificCell(x, y);
        if (!cell->isCellContentExist()) {
            stepOnCell(cell);
        }
    }
}

InteractiveObject* Character::clone() {
    return new Character(damage, stamina, defence);
}