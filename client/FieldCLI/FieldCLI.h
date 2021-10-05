#ifndef OOP_GAME_CLIENT_FIELD_CLI_HEADLINE
#define OOP_GAME_CLIENT_FIELD_CLI_HEADLINE
#include "../CLI/CLI.h"
#include "../../source/FieldComponents/Field/Field.h"
#include "../../source/FieldComponents/FieldIterator/FieldIterator.h"

class FieldCLI: CLI {
protected:
    Field* field;
public:
    FieldCLI(Field* field):field(field) {}
    void print() override;
};

#endif