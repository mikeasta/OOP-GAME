#include <iostream>
#include "./client/FieldView/FieldView.h"
#include "./source/Field/Field.h"

int main()
{
    Field field    = Field(10, 10);
    FieldView view = FieldView(field);
    view.drawField();
}