#include "FieldCLI.h"

// Content chars vocabulary
std::map<std::string, std::string> content_voc {
    { typeid(Player).name(), "P" },
    { typeid(Item).name(), "I" }
};

// Cell chars vocabulary
std::map<std::string, std::string> cell_voc {
        { typeid(Cell).name(), " " },
        { typeid(CellWall).name(), "W" },
        { typeid(CellExit).name(), "X" },
        { typeid(CellEntrance).name(), "N" },
        { typeid(CellFloor).name(), "." },
};

void FieldCLI::print() {
    std::cout << "Print Started\n";
    FieldIterator iterator = FieldIterator(field);
    Cell* curr_item = iterator.getCurrent();
    InteractiveObject* content;
    while(curr_item != nullptr) {
        content = curr_item->getCellContent();
        if (content) {
            std::cout << content_voc[typeid(*content).name()];
        } else {
            std::cout << cell_voc[typeid(*curr_item).name()];
        }

        if (iterator.isLastInARow()) {
            std::cout << "\n";
        }
        curr_item = iterator.getNext();
    }
    std::cout << "Print finished\n";
}