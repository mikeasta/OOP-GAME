#include <iostream>
#include <map>
#include <string>
#include "../../source/FieldIterator/FieldIterator.h"
// #include "../../source/Field/Field.h"
// #include "../../source/Cell/Cell.h"
// #include "../../source/CellWall/CellWall.h"
// #include "../../source/CellFloor/CellFloor.h"
// #include "../../source/CellLava/CellLava.h"
// #include "../../source/CellEntrance/CellEntrance.h"
// #include "../../source/CellExit/CellExit.h"

class FieldView {
private:
    Field field;
    typedef std::map<std::type_info, std::string> mp;
public:
    FieldView(Field field):field(field) {};

    void drawField() {
        std::cout << "Field View\n";
        Cell** cells = field.getField();
        int rows     = field.getRows();
        int cols     = field.getCols();

        // Отрисовка с помощью итератора
        FieldIterator iterator(&field);
        Cell* curr = iterator.getCurrent();
        while (curr) {
            if (typeid(curr) == typeid(CellEntrance)) {
                std::cout << "E";
            } else if (typeid(curr) == typeid(CellExit)){
                std::cout << "X";
            } else if (typeid(curr) == typeid(CellFloor)){
                std::cout << "O";
            } else if (typeid(curr) == typeid(CellWall)){
                std::cout << "W";
            } else if (typeid(curr) == typeid(CellLava)){
                std::cout << "L";
            }

            if (iterator.isLastInARow(curr)) {
                std::cout << std::endl;
            }

            curr = iterator.next();
        }
    }
};