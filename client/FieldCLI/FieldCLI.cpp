#include "FieldCLI.h"
#include <iostream>

void FieldCLI::print() {
    FieldIterator iterator = FieldIterator(field);
    const Cell* curr_item = iterator.getCurrent();
    while(curr_item != nullptr){
        if (typeid(*curr_item) == typeid(Cell))
        {
            std::cout << " ";
        }
        else if (typeid(*curr_item) == typeid(CellWall))
        {
            std::cout << "X";
        }
        else if (typeid(*curr_item) == typeid(CellExit))
        {
            std::cout << "S";
        }
        else if (typeid(*curr_item) == typeid(CellEntrance))
        {
            std::cout << "E";
        }
        if (iterator.isLastInARow())
        {
            std::cout << "\n";
        }
        curr_item = iterator.getNext();
    }
}