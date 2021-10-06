#include <iostream>
#include "client/FieldCLI/FieldCLI.h"
#include "source/FieldComponents/FieldGenerator/FieldGenerator.h"
#include "source/FieldComponents/Field/Field.h"

int main() {
    FieldGenerator generator = FieldGenerator();
    Field field = Field(generator.generateStandartField(5, 5));
    FieldCLI interface = FieldCLI(&field);
    interface.print(); 
}