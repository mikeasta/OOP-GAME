#include <iostream>
#include "client/FieldCLI/FieldCLI.h"
#include "source/FieldComponents/FieldGenerator/FieldGenerator.h"
#include "source/FieldComponents/Field/Field.h"

int main() {
    FieldGenerator generator = FieldGenerator();

    // 1x1
    std::cout << "Field 1\n";
    Field field_1 = Field(generator, 1, 1);
    FieldCLI interface_1 = FieldCLI(&field_1);
    interface_1.print(); 

    // 5x5
    std::cout << "Field 2\n";
    Field field_2 = Field(generator, 5, 5);
    FieldCLI interface_2 = FieldCLI(&field_2);
    interface_2.print();

    // 10x70
    std::cout << "Field 3\n";
    Field field_3 = Field(generator, 10, 70);
    FieldCLI interface_3 = FieldCLI(&field_3);
    interface_3.print();

    // Copy constr 5x5
    std::cout << "Copy constr. \n";
    Field field_4(field_2);
    FieldCLI interface_4 = FieldCLI(&field_4);
    interface_4.print();

    // Copy operator 10x70
    std::cout << "Copy oper. \n";
    Field field_5 = field_3;
    FieldCLI interface_5 = FieldCLI(&field_5);
    interface_5.print();

    // Move constr 10x70
    std::cout << "Move constr. \n";
    Field field_6 = field_3;
    FieldCLI interface_6 = FieldCLI(&field_6);
    interface_6.print();
    interface_5.print();

    // Move operator 
    std::cout << "Move oper. \n";
    Field field_7(generator, 1, 1);
    FieldCLI interface_7 = FieldCLI(&field_7);
    interface_7.print();
    field_7 = Field(generator, 2, 2);
    interface_7.print();
}