//
// Created by mikeasta on 12.10.2021.
//

#include "Character.h"

Character::Character(int damage, int stamina, int defence):
    damage(damage),
    stamina(stamina),
    defence(defence) {};

int Character::getDamage() const {
    return this->damage;
}

int Character::getStamina() const {
    return this->stamina;
}

int Character::getDefence() const {
    return this->defence;
}

Cell* Character::getCurrentCell() const {
    return this->curr_cell;
}

void Character::buffDamage(int val) {
    this->damage += val;
}

void Character::buffStamina(int val) {
    this->stamina += val;
}

void Character::buffDefence(int val) {
    this->defence += val;
    this->defence = this->defence > 100 ? 100 : this->defence;
}

void Character::setCurrentCell(Cell *new_curr_cell) {
    this->curr_cell = new_curr_cell;
}

void Character::stepOnCell(Cell *stepped_cell) {
    std::pair<bool, std::string> response = stepped_cell->stepEffect(this);

    if (response.first) {
        // Step done
        if (response.second == "FLOOR") {
            curr_cell->clearCellContent();
            this->setCurrentCell(stepped_cell);
        } else if (response.second == "WALL") {
            // Do nothing
        } else if (response.second == "EXIT") {
            // Exit Logic
        } else if (response.second == "COMBAT") {

        }
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
        } else {
            std::cout << "\nCharacter: Spawn denied. Something is already on the cell.\n";
        }
    }
}
