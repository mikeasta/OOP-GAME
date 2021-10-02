#include <iostream>
#include <string>
#include "Game_Object.cpp"

class Cell {
private:
    Game_Object* cell_content;
    int coord_x;
    int coord_y;
    std::string state;
public:
    // Constructors
    Cell(int cootd_x = 0, int coord_y = 0, std::string state = "safe", Game_Object* cell_content = nullptr) 
        :coord_x(coord_x), coord_y(coord_y), state(state), cell_content(cell_content) {}

    // Destructor
    ~Cell() {
        delete cell_content;
        delete this;
    }

    // Copy constructor
    Cell (const Cell& other)
        :coord_x(other.coord_x), coord_y(other.coord_y), state(other.state), cell_content(other.cell_content) {}

    // Copy operator
    Cell& operator=(const Cell& other)
    {
        if (this != &other)
        {
            coord_x      = other.coord_x;
            coord_y      = other.coord_y;
            state        = other.state;
            cell_content = other.cell_content;
        }

        return *this;
    }

    // Move constructor
    Cell (Cell&& other) {
        std::swap(coord_x, other.coord_x);
        std::swap(coord_y, other.coord_y);
        std::swap(state, other.state);
        std::swap(cell_content, other.cell_content);
    }

    // Move operator 
    Cell& operator=(Cell&& other) {
        if (this != &other) {
            std::swap(coord_x, other.coord_x);
            std::swap(coord_y, other.coord_y);
            std::swap(state, other.state);
            std::swap(cell_content, other.cell_content);
        }

        return *this;
    }
};