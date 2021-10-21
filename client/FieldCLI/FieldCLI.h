#pragma once

#include <iostream>
#include <map>
#include <string>
#include "../CLI/CLI.h"
#include "../../source/FieldComponents/Field/Field.h"
#include "../../source/FieldComponents/FieldIterator/FieldIterator.h"
#include "../../source/InteractiveObjectComponents/Player/Player.h"
#include "../../source/InteractiveObjectComponents/Item/Item.h"
#include "../../source/InteractiveObjectComponents/Enemy/Enemy.h"

class FieldCLI: public CLI {
private:
    std::map<std::string, std::string> content_voc {
            { typeid(Player).name(), "P" },
            { typeid(Item).name(),   "I" },
            { typeid(Enemy).name(),  "E"},
    };

    std::map<std::string, std::string> cell_voc {
            { typeid(Cell).name(),         " " },
            { typeid(CellWall).name(),     "W" },
            { typeid(CellExit).name(),     "X" },
            { typeid(CellEntrance).name(), "N" },
            { typeid(CellFloor).name(),    "." },
    };
protected:
    Field* field;
public:
    explicit FieldCLI(Field* field):field(field) {}
    void print() override;
};
