//
// Created by mikeasta on 16.10.2021.
//

#include "Enemy.h"

std::map<std::string, std::vector<int>> enemy_voc = {
        { "enemy_1", {5, 30, 5} },
        { "enemy_2", {5, 50, 40} },
        { "enemy_3", {5, 100, 15} },
};

Enemy::Enemy(int damage, int stamina, int defence):
    Character(damage, stamina, defence) {}

InteractiveObject* Enemy::clone() {
    return new Enemy(damage, stamina, defence);
}

Enemy* Enemy::create(std::string enemy_type) {
    auto curr = enemy_voc.begin();

    // Search for correct pair
    curr = enemy_voc.find(enemy_type);
    return new Enemy(curr->second[0], curr->second[1], curr->second[2]);
}

Enemy* Enemy::create() {
    RandomNumberGenerator randomizer;
    auto curr = enemy_voc.begin();

    std::advance(curr, randomizer.generate(0, 2));
    return new Enemy(curr->second[0], curr->second[1], curr->second[2]);
}

void Enemy::die() { alive = false; }

bool Enemy::getState() { return alive; }