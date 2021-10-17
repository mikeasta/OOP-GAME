//
// Created by mikeasta on 17.10.2021.
//

#include "PlayerController.h"

PlayerController::PlayerController(Player *player, Field *field):
    player(player),
    field(field) {
    FieldIterator iterator = FieldIterator(field);
    Cell* it_cell          = iterator.getCurrent();
    InteractiveObject* content;
    while (it_cell != nullptr) {

        content = it_cell->getCellContent();
        std::cout << it_cell->getCellContent();
        if (content)
        {
            if (typeid(*content) == typeid(Player)) {
                curr_cell = it_cell;
                std::cout << "PlayerController: Player found at " << curr_cell->getX() << ";" <<curr_cell->getY() << "\n";
                break;
            }
        }

        it_cell = iterator.getNext();
    }
}

std::string PlayerController::move(std::string direction) {

    Cell* to_move;
    unsigned int x = curr_cell->getX();
    unsigned int y = curr_cell->getY();
    std::cout << x << " " << y << "\n";
    if (direction == "w") {
        y -= 1;
    } else if (direction == "a") {
        x -= 1;
    } else if (direction == "s") {
        y += 1;
    } else if (direction == "d") {
        x += 1;
    }


    to_move = field->getSpecificCell(x, y);

    std::pair<bool, std::string> response = to_move->stepEffect(player);
    if (typeid(*to_move) == typeid(CellFloor)) {
        curr_cell->clearCellContent();
        curr_cell = to_move;
    }

    return response.second;
}

