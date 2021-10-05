#ifndef OOP_GAME_CELL_HEADLINE
#define OOP_GAME_CELL_HEADLINE
#include "../../InteractiveObject/InteractiveObject.h"

class Cell {
protected:
    unsigned int coord_x;
    unsigned int coord_y;
    bool isEmpty;
    InteractiveObject* cell_content;
public:
    Cell(unsigned int coord_x, unsigned int coord_y) {};
    virtual ~Cell() = default;
    virtual Cell* cloneCell();
    virtual void stepOnCell();
};

#endif