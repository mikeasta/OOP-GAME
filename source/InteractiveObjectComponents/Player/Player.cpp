//
// Created by mikeasta on 13.10.2021.
//

#include "Player.h"

Player::Player(int damage, int stamina, int defence):
        Character(damage, stamina, defence) {
    *equipment = {};
}

Player::~Player() {
    delete equipment;
    curr_cell->clearCellContent();
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

void Player::take(Cell* cell_with_item) {
    equipment->addItem(dynamic_cast<Item *>(cell_with_item->getCellContent()));
    cell_with_item->clearCellContent();
}