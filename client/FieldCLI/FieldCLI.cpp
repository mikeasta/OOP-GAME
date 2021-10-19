#include "FieldCLI.h"
#define CLEAR "\x1B[2J\x1B[H"

// Content chars vocabulary
std::map<std::string, std::string> content_voc {
    { typeid(Player).name(), "P" },
    { typeid(Item).name(),   "I" },
    { typeid(Enemy).name(),  "E"},
};

// Cell chars vocabulary
std::map<std::string, std::string> cell_voc {
        { typeid(Cell).name(),         " " },
        { typeid(CellWall).name(),     "W" },
        { typeid(CellExit).name(),     "X" },
        { typeid(CellEntrance).name(), "N" },
        { typeid(CellFloor).name(),    "." },
};

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