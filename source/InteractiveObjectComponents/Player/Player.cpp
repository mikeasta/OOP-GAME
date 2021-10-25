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

std::map<std::string, int> Player::getEquipmentLabels() {
    return equipment->getItemLabels();
}

void Player::take(Item* item) {
    if (item->getBonusStamina()) {
        buffStamina(item->getBonusStamina());
    } else {
        equipment->addItem(item);
    }
}

void Player::spawn(Field &field) {

    // If player is already spawned
    if (is_spawned) {
        return;
    }

    is_spawned = true;
    unsigned int rows = field.getRows();
    unsigned int cols = field.getCols();

    // Look for entrance
    FieldIterator iterator = FieldIterator(field);
    Cell* curr_item = iterator.getCurrent();
    while(curr_item != nullptr) {
        if (typeid(*curr_item) != typeid(CellEntrance)) {
            curr_item = iterator.getNext();
        } else {
            break;
        }
    }

    // Analyze cell position and get neighbour cell
    Cell* got = nullptr;
    unsigned int entrance_x = curr_item->getX();
    unsigned int entrance_y = curr_item->getY();

    // Taking cell, where player will
    // be spawned
    if (entrance_x == 0) {
        got = field.getCell(entrance_x + 1, entrance_y);
    } else if (entrance_x == cols - 1) {
        got = field.getCell(entrance_x - 1, entrance_y);
    } else if (entrance_y == 0) {
        got = field.getCell(entrance_x, entrance_y + 1);
    } else if (entrance_y == rows - 1) {
        got = field.getCell(entrance_x, entrance_y - 1);
    }

    if (got) {
        got->stepEffect(this);
    }
}

std::pair<std::string, Combat> Player::attack(Character *enemy) {

    // Generate player damage
    RandomNumberGenerator randomizer;
    CombatDetailsStruct details;

    int full_player_damage = getFullDamage();
    if (randomizer.simulate_chance(15)) {
        full_player_damage *= 2;
        details.is_player_critical = true;
    }

    details.player_damage_done = full_player_damage;
    enemy->get_combat_damage(full_player_damage);

    // Check if enemy died
    if (enemy->getStamina() > 0) {
        int full_opponent_damage = enemy->getDamage();
        if (randomizer.simulate_chance(5)) {
            full_opponent_damage *= 2;
            details.is_enemy_critical = true;
        }

        details.enemy_damage_done = full_opponent_damage;
        get_combat_damage(full_opponent_damage);

        Combat new_combat = Combat(details);

        // Check, if player died;
        if (getFullStamina() > 0) {
            return std::make_pair("DRAW", new_combat);
        } else {
            return std::make_pair("LOSS", new_combat);
        }

    } else {
        details.is_enemy_died = true;
        Combat new_combat = Combat(details);

        return std::make_pair("WIN", new_combat);
    }
}