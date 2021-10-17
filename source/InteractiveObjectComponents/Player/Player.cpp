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
    unsigned int rows = field->getRows();
    unsigned int cols = field->getCols();

    if (x == 0 || y == 0 || x >= cols || y >= rows) {

        // Look for entrance
        FieldIterator iterator = FieldIterator(field);
        Cell* curr_item = iterator.getCurrent();
        while(curr_item != nullptr) {
            if (typeid(*curr_item) == typeid(CellEntrance))
                break;
            else
                curr_item = iterator.getNext();
        }

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

        got->stepEffect(this);
    } else {
        Cell* cell = field->getSpecificCell(x, y);
        if (!cell->isCellContentExist()) {
            stepOnCell(cell);
        } else {
            std::cout << "\nPlayer: Spawn denied. Something is already on the cell.\n";
        }
    }
}

std::string Player::attack(Character *opponent) {

    // Generate player damage
    RandomNumberGenerator randomizer;
    float full_player_damage = getFullDamage() * 1.0;
    if (randomizer.simulate_chance(15))
        full_player_damage *= 2;
    std::cout <<"\n -Player damage - " << full_player_damage;

    opponent->get_combat_damage(full_player_damage);
    std::cout << "\n -Opponent health - " << opponent->getStamina() << "\n";
    if (opponent->getStamina() > 0) {
        float full_opponent_damage = opponent->getDamage() * 1.0;
        if (randomizer.simulate_chance(5))
            full_opponent_damage *= 2;

        get_combat_damage(full_opponent_damage);
        if (getStamina() > 0) {
            return "DRAW";
        } else {
            return "LOSS";
        }
    } else {
        return "WIN";
    }
}