//
// Created by mikeasta on 16.10.2021.
//

#include "Enemy.h"

Enemy::Enemy(std::string enemy_type, int damage, int stamina, int defence):
    Character(damage, stamina, defence) {
    enemy_id = s_id++;
    this->enemy_type = enemy_type;
}

InteractiveObject* Enemy::clone() {
    return new Enemy(enemy_type, damage, stamina, defence);
}

Enemy* Enemy::create(std::map<std::string, std::vector<int>> enemy_voc) {
    RandomNumberGenerator randomizer;
    auto curr = enemy_voc.begin();

    std::advance(curr, randomizer.generate(0, 2));
    return new Enemy(
            curr->first,
            curr->second[0],
            curr->second[1],
            curr->second[2]);
}

void Enemy::die() {
    alive = false;
}

bool Enemy::getState() const {
    return alive;
}

unsigned int Enemy::getID() const {
    return enemy_id;
}

std::string Enemy::getType() const {
    return enemy_type;
}

std::ostream& operator<< (std::ostream& out, const Enemy &enemy) {
    out << "\nEnemy #" << enemy.getID() << ": ";
    out << "\nHealth: " << enemy.getStamina();
    out << "\nDamage: " << enemy.getDamage();
    out << "\nDefence: " << enemy.getDefence();

    return out;
}
