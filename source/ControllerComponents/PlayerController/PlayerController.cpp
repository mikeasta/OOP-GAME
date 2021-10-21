//
// Created by mikeasta on 17.10.2021.
//

#include "PlayerController.h"

PlayerController::PlayerController(Player *player, Field *field):
    player(player),
    field(field) {
    FieldIterator iterator = FieldIterator(field);
    Cell* it_cell = iterator.getCurrent();
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

std::pair<std::string, Combat> PlayerController::move(char direction) {

    unsigned int x = curr_cell->getX(), y = curr_cell->getY();

    if (direction == directions["up"])
        y -= 1;
    else if (direction == directions["left"])
        x -= 1;
    else if (direction == directions["down"])
        y += 1;
    else if (direction == directions["right"])
        x += 1;

    Cell* to_move = field->getCell(x, y);

    std::pair<bool, std::string> response = to_move->stepEffect(player);
    if (typeid(*to_move) == typeid(CellFloor)) {

        // Check if something in cell
        bool is_content = to_move->isCellContentExist();
        if (is_content) {
            if (typeid(*to_move->getCellContent()) == typeid(Item)) {
                player->take(dynamic_cast<Item *>(to_move->getCellContent()));
            } else if (typeid(*to_move->getCellContent()) == typeid(Enemy)){
                auto* opponent = dynamic_cast<Character*>(to_move->getCellContent());
                std::pair<std::string, Combat> result = player->attack(opponent);

                if (result.first == "WIN") {
                    dynamic_cast<Enemy*>(opponent)->die();
                    curr_cell->clearCellContent();
                    curr_cell = to_move;
                    curr_cell->setCellContent(player);
                }

                return result;
            }
        }

        curr_cell->clearCellContent();
        curr_cell = to_move;
        curr_cell->setCellContent(player);
    }

    return std::make_pair(response.second, Combat());
}

