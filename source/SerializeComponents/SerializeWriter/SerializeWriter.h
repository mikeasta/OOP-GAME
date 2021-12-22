//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_SERIALIZEWRITER_H
#define OOP_GAME_SERIALIZEWRITER_H
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include "../../../utils/JSON_Extension/json.hpp"
using json = nlohmann::json;


class SerializeWriter {
private:
    std::string path_to_saving_file = "/home/mikeasta/Programming/OOP-GAME/source/GameComponents/Game/field.json";
public:
    void write(Field& field, Player& player);
};
#endif //OOP_GAME_SERIALIZEWRITER_H
