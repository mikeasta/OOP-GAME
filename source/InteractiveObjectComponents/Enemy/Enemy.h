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
#include <iostream>

class Enemy: public Character {
private:
    unsigned int enemy_id;
    bool alive = true;
    std::string enemy_type;
public:
    static unsigned int s_id;

    // Constructors
    explicit Enemy(std::string enemy_type="", int damage = 0, int stamina = 0, int defence = 0);
    ~Enemy() override = default;

    InteractiveObject* clone() final;

    Enemy* create(std::map<std::string, std::vector<int>> enemy_voc);
    bool getState() const;
    void die();
    unsigned int getID() const;
    std::string getType() const;

    friend std::ostream& operator<< (std::ostream& out, const Enemy &enemy);
};


#endif //OOP_GAME_ENEMY_H
