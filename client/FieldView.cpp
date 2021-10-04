#include <iostream>
#include <map>
#include <string>
#include "../source/Field.cpp"
#include "../source/Cell.cpp"
#include "../source/CellWall.cpp"
#include "../source/CellFloor.cpp"
#include "../source/CellLava.cpp"
#include "../source/CellEntrance.cpp"
#include "../source/CellExit.cpp"

class FieldView {
private:
    Field field;
    typedef std::map<std::type_info, std::string> mp;
public:
    FieldView(Field field):field(field) {
        // 
    };

    void drawField() {
        Cell** cells = field.getField();
        int rows     = field.getRows();
        int cols     = field.getCols();

        // Отрисовка с помощью итератора
    }
};