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
    while (it_cell) {
        content = it_cell->getCellContent();
        if (content)
        {
            if (typeid(*content) == typeid(Player)) {
                curr_cell = it_cell;
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
    if (direction == "w")
        y -= 1;
    else if (direction == "a")
        x -= 1;
    else if (direction == "s")
        y += 1;
    else if (direction == "d")
        x += 1;

    to_move = field->getSpecificCell(x, y);

    std::pair<bool, std::string> response = to_move->stepEffect(player);
    if (typeid(*to_move) == typeid(CellFloor)) {

        // Check if something in cell
        bool is_content = to_move->isCellContentExist();
        if (is_content) {
            if (typeid(*to_move->getCellContent()) == typeid(Item)) {
                player->take(dynamic_cast<Item *>(to_move->getCellContent()));
            } else if (typeid(*to_move->getCellContent()) == typeid(Enemy)){
                Character* opponent =  dynamic_cast<Character*>(to_move->getCellContent());
                std::cout << "\nCOMBAT:";
                std::string result = player->attack(opponent);

                if (result == "LOSS")
                    return "LOSS";
                else if (result == "DRAW")
                    return "DRAW";
                else if (result == "WIN") {
                    dynamic_cast<Enemy*>(opponent)->die();
                }
            }
        }

        curr_cell->clearCellContent();
        curr_cell = to_move;
        curr_cell->setCellContent(player);
    }

    return response.second;
}

