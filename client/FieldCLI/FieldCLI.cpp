#include "FieldCLI.h"

void FieldCLI::print() {
    std::cout << std::endl;
    FieldIterator iterator = FieldIterator(field);
    Cell* curr_item        = iterator.getCurrent();
    InteractiveObject* content;

    while(curr_item) {
        content = curr_item->getCellContent();

        // Check for any InteractiveObject in Cell
        if (content)
            std::cout << content_voc[typeid(*content).name()];
        else
            std::cout << cell_voc[typeid(*curr_item).name()];

        // New line after row
        if (iterator.isLastInARow())
            std::cout << "\n";

        curr_item = iterator.getNext();
    }
}