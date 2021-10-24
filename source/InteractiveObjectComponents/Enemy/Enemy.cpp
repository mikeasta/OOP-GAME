//
// Created by mikeasta on 16.10.2021.
//

#include "Enemy.h"

Enemy::Enemy(int damage, int stamina, int defence):
    Character(damage, stamina, defence) {}

InteractiveObject* Enemy::clone() {
    return new Enemy(damage, stamina, defence);
}

Enemy* Enemy::create(std::map<std::string, std::vector<int>> enemy_voc) {
    RandomNumberGenerator randomizer;
    auto curr = enemy_voc.begin();

    std::advance(curr, randomizer.generate(0, 2));
    return new Enemy(curr->second[0], curr->second[1], curr->second[2]);
}

void Enemy::die() {
    alive = false;
}

bool Enemy::getState() {
    std::cout << std::endl << bool(alive);
    return alive;
}