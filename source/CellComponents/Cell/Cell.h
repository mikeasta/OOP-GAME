#pragma once

#include <tuple>
#include <string>
#include "../../GameComponents/Response/Response.h"
#include "../../InteractiveObjectComponents/InteractiveObject/InteractiveObject.h"

class Cell {
protected:
    unsigned int coord_x;
    unsigned int coord_y;
    InteractiveObject *cell_content = nullptr;
public:
    // Constructor
    Cell(unsigned int coord_x, unsigned int coord_y);
    virtual ~Cell() = default;

    // Getters
    bool isCellContentExist();
    unsigned int getX() const;
    unsigned int getY() const;
    InteractiveObject* getCellContent();

    // Setters
    void setCellContent(InteractiveObject *object);
    void clearCellContent();

    // Pattern "Prototype"
    virtual Cell* clone();
    virtual std::string stepEffect(InteractiveObject* object);
};
