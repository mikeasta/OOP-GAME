#pragma once

#include "../CLI/CLI.h"
#include "../../source/FieldComponents/Field/Field.h"
#include "../../source/FieldComponents/FieldIterator/FieldIterator.h"

class FieldCLI: public CLI {
protected:
    Field* field;
public:
    FieldCLI(Field* field):field(field) {}
    void print() override;
};
