#include <iostream>
#include <string>
#include "../GameObject/GameObject.h"


class Cell {
protected:
    GameObject* cell_content;
    int coord_x;
    int coord_y;
    std::string state;
public:
    // Constructors
    Cell(int cootd_x = 0, int coord_y = 0, std::string state = "safe", GameObject* cell_content = nullptr) 
        :coord_x(coord_x), coord_y(coord_y), state(state), cell_content(cell_content) {}

    // Destructor
    ~Cell() {
        delete cell_content;
        delete this;
    }

    // Copy constructor
    Cell (const Cell& other):
        coord_x(other.coord_x), 
        coord_y(other.coord_y), 
        state(other.state), 
        cell_content(other.cell_content) {}

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

    // Getters
    int getXCoord() {
        return coord_x;
    }

    int getYCoord() {
        return coord_y;
    }

    GameObject* getGameObject() {
        return cell_content;
    }

    std::string getState() {
        return state;
    } 

    // Setters
    void setXCoord(int new_coord_x = 0) {
        coord_x = new_coord_x;
    }

    void setYCoord(int new_coord_y = 0) {
        coord_y = new_coord_y;
    }

    void setState(std::string new_state = "safe") {
        state = new_state;
    }

    void setCellContent(GameObject* new_cell_content = nullptr) {
        cell_content = new_cell_content;
    }

    // Activates when we step on this cell
    virtual void step() {};
};