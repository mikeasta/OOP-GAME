//
// Created by mikeasta on 13.10.2021.
//

#include "Player.h"

Player::Player(int damage, int stamina, int defence):
        Character(damage, stamina, defence) {
    equipment = new Equipment;
}

int Player::getFullDamage() const {
    return damage + equipment->getAttackBuff();
}

int Player::getFullStamina() const {
    return stamina + equipment->getStaminaBuff();
}

int Player::getFullDefence() const {
    return defence + equipment->getDefenceBuff();
}

void Player::take(Item* item) {
    equipment->addItem(item);
}

void Player::spawn(Field* field, unsigned int x, unsigned int y) {

    // If player is already spawned
    if (is_spawned) { return; }

    is_spawned = true;
    std::cout << "Player: Spawn process began\n";
    unsigned int rows = field->getRows();
    unsigned int cols = field->getCols();

    std::cout <<"Player: Condition started\n";
    if (x == 0 || y == 0 || x >= cols || y >= rows) {

        std::cout << "Player: Field cols - " << cols << "; Field rows - " << rows << "\n";

        // Look for entrance
        FieldIterator iterator = FieldIterator(field);
        Cell* curr_item = iterator.getCurrent();
        while(curr_item != nullptr) {
            if (typeid(*curr_item) == typeid(CellEntrance)) {
                break;
            } else {
                curr_item = iterator.getNext();
            }
        }
        std::cout << "Player: Entrance found: [" << curr_item->getX() << "; " << curr_item->getY() << "]\n";

        // Analyze cell position and get neighbour cell
        Cell* got;
        unsigned int entrance_x = curr_item->getX();
        unsigned int entrance_y = curr_item->getY();
        if (entrance_x == 0)
        {
            // Left border
            got = field->getSpecificCell(entrance_x + 1, entrance_y);
        } else if (entrance_x == cols - 1)
        {
            // Right border
            got = field->getSpecificCell(entrance_x - 1, entrance_y);
        } else if (entrance_y == 0)
        {
            // Upper border
            got = field->getSpecificCell(entrance_x, entrance_y + 1);
        } else if (entrance_y == rows - 1)
        {
            // Upper border
            got = field->getSpecificCell(entrance_x, entrance_y - 1);
        }

        std::cout << "Player: Got found: [" << got->getX() << "; " << got->getY() << "]\n";
        got->stepEffect(this);
    } else {
        Cell* cell = field->getSpecificCell(x, y);
        if (!cell->isCellContentExist()) {
            stepOnCell(cell);
        } else {
            std::cout << "\nPlayer: Spawn denied. Something is already on the cell.\n";
        }
    }
    std::cout << "Player: Spawn process ended\n";
}
