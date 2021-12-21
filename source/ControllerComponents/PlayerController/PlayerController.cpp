//
// Created by mikeasta on 17.10.2021.
//

#include "PlayerController.h"

PlayerController::PlayerController(Player &player, Field &field):
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

void PlayerController::enableLeaving() {
    is_able_to_exit = true;
}

std::pair<std::string, Combat> PlayerController::move(std::string direction) {

    auto response_lib = Response().getResponseLib();

    // Check, if there is no command to move
    if (directions.count(direction) == 0) {
        auto null_combat = Combat();
        auto null_string = response_lib["not_found"];

        return {null_string, null_combat};
    }

    // Get coordinates and move it
    unsigned int x = curr_cell->getX() + directions[direction].first;
    unsigned int y = curr_cell->getY() + directions[direction].second;

    Cell* to_move = field.getCell(x, y);
    std::string response = to_move->stepEffect(&player);

    // Check, if player can finish level
    if ((response == response_lib["exit"]) & (!is_able_to_exit)) {
        response = response_lib["wall"];
    }


    // Check, if player stepped on floor cell
    if (response == response_lib["floor"]) {

        // Check if something in cell
        bool is_content = to_move->isCellContentExist();
        if (is_content) {
            if (typeid(*to_move->getCellContent()) == typeid(Item)) {
                Item* found_item = dynamic_cast<Item *>(to_move->getCellContent());
                player.take(found_item);
                update("Player taken \"" + found_item->getName() + "\"");
            } else if (typeid(*to_move->getCellContent()) == typeid(Enemy)){

                auto* opponent = dynamic_cast<Character*>(to_move->getCellContent());
                std::pair<std::string, Combat> result = player.attack(opponent);

                update(result.second.getCombatDetailsToString());

                if (result.first == response_lib["win"]) {
                    dynamic_cast<Enemy*>(opponent)->die();

                    update("Player stepped on cell (" + std::to_string(to_move->getX()) + ", " + std::to_string(to_move->getY()) + ")");
                    curr_cell->clearCellContent();
                    curr_cell = to_move;
                    curr_cell->setCellContent(&player);
                }

                return result;
            }
        }

        update("Player stepped on cell (" + std::to_string(to_move->getX()) + ", " + std::to_string(to_move->getY()) + ")");
        curr_cell->clearCellContent();
        curr_cell = to_move;
        curr_cell->setCellContent(&player);
    }

    return {response, Combat()};
}
