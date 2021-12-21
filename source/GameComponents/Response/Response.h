//
// Created by mikeasta on 25.10.2021.
//

#ifndef OOP_GAME_RESPONSE_H
#define OOP_GAME_RESPONSE_H
#include <map>
#include <string>

class Response {
private:
    const std::map<std::string, std::string> response_lib = {
            // Combat responses
            { "win",  "WIN" },
            { "draw", "DRAW" },
            { "loss", "LOSS" },
            { "enemy_died", "ENEMY_DIED"},

            // Cell responses
            { "cell",     "CELL" },
            { "floor",    "FLOOR" },
            { "wall",     "WALL" },
            { "exit",     "EXIT" },
            { "entrance", "ENTRANCE" },

            // Error
            {"not_found", "NOT_FOUND"}
    };
public:
    const std::map<std::string, std::string> getResponseLib();
};

#endif //OOP_GAME_RESPONSE_H
