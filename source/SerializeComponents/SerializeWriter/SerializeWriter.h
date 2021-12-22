//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_SERIALIZEWRITER_H
#define OOP_GAME_SERIALIZEWRITER_H
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include <string>


class SerializeWriter {
private:
    std::string path_to_saving_file = "/home/mikeasta/Programming/OOP-GAME/source/GameComponents/Game/field.json";
public:
    void write(Field& field, Player& player);
};
#endif //OOP_GAME_SERIALIZEWRITER_H
