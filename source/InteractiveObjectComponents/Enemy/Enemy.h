//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_ENEMY_H
#define OOP_GAME_ENEMY_H
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include "../Character/Character.h"
#include <vector>
#include <map>
#include <string>

class Enemy: public Character {
public:
    // Constructors
    Enemy(int damage = 0, int stamina = 0, int defence = 0);
    ~Enemy() = default;

    virtual InteractiveObject* clone() final;

    Enemy* create();
    Enemy* create(std::string enemy_type);
};

#endif //OOP_GAME_ENEMY_H
