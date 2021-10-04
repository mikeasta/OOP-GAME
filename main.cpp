#include <iostream>
#include "./client/FieldView/FieldView.h"
//#include "./source/Field/Field.h"

int main()
{
    Field field = Field(10, 10, 0);

    std::cout << "Test 2";
    FieldView view = FieldView(field);

    std::cout << "Test1";
    view.drawField();
}