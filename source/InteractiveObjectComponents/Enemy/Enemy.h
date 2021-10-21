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
private:
    bool alive = true;
public:
    // Constructors
    explicit Enemy(int damage = 0, int stamina = 0, int defence = 0);
    ~Enemy() override = default;

    InteractiveObject* clone() final;

    Enemy* create(std::map<std::string, std::vector<int>>);
    bool getState() const;
    void die();
};

#endif //OOP_GAME_ENEMY_H
