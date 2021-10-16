#pragma once

#include <iostream>
#include <map>
#include <string>
#include "../CLI/CLI.h"
#include "../../source/FieldComponents/Field/Field.h"
#include "../../source/FieldComponents/FieldIterator/FieldIterator.h"
#include "../../source/InteractiveObjectComponents/Player/Player.h"
#include "../../source/InteractiveObjectComponents/Item/Item.h"

class FieldCLI: public CLI {
protected:
    Field* field;
public:
    FieldCLI(Field* field):field(field) {}
    void print() override;
};
