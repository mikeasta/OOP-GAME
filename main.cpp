#include <iostream>
#include "source/GameComponents/Game/Game.h"
#include "client/FieldCLI/FieldCLI.h"
#include "source/FieldComponents/FieldGenerator/FieldGenerator.h"
#include "source/FieldComponents/Field/Field.h"
#include "source/InteractiveObjectComponents/Player/Player.h"

int main() {
    unsigned int field_rows = 5, field_cols = 7;
    FieldGenerator generator = FieldGenerator();
    Cell*** cells = generator.generateField(field_rows, field_cols);
    Field new_field = Field(cells, field_rows, field_cols);
    Player new_player = Player(10, 10, 10);
    std::cout <<"Spawn\n";
    new_player.spawn(&new_field);

    FieldCLI new_field_cli = FieldCLI(&new_field);

    std::cout << "Printed\n";
    new_field_cli.print();
    std::cout << "Printed";
}