#pragma once

#include <tuple>
#include <string>
#include "../../InteractiveObjectComponents/InteractiveObject/InteractiveObject.h"

class Cell {
protected:
    unsigned int coord_x;
    unsigned int coord_y;
    InteractiveObject* cell_content = nullptr;
public:
    Cell(unsigned int coord_x, unsigned int coord_y);
    bool isCellContentExist();
    void setCellContent(InteractiveObject* object);
    void clearCellContent();
    std::pair <unsigned int, unsigned int> getCoords();
    virtual ~Cell() = default;
    virtual Cell* cloneCell();
    virtual std::pair<bool, std::string> stepEffect(InteractiveObject* object);
};
