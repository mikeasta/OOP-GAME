#include <iostream>
#include "../InteractiveObjects/InteractiveObject.h"

class Cell {
protected:
    unsigned int coord_x;
    unsigned int coord_y;
    InteractiveObject* inner_object;
    bool is_empty;

public:
    Cell(unsigned int coord_x, unsigned int coord_y) {};
    virtual ~Cell() = default;  
    virtual Cell* cloneCell();
};