//
// Created by mikeasta on 17.10.2021.
//

#include "EnemyController.h"

EnemyController::EnemyController(Enemy *enemy, Field &field, Cell* curr_cell):
    enemy(enemy),
    field(field),
    curr_cell(curr_cell) {}


std::string EnemyController::move(std::map<std::string, char> direction_voc, char direction) {

    if (!enemy->getState()) {
        return "DIED";
    }

    unsigned int x = curr_cell->getX();
    unsigned int y = curr_cell->getY();

    if (direction == direction_voc["up"]) {
        y -= 1;
    } else if (direction == direction_voc["down"]) {
        y += 1;
    } else if (direction == direction_voc["left"]) {
        x -= 1;
    } else if (direction == direction_voc["right"]) {
        x += 1;
    }

    Cell* to_move = field.getCell(x, y);
    if (to_move->isCellContentExist()) {
        return "ENEMY_STOPPED";
    }

    std::pair<bool, std::string> response = to_move->stepEffect(enemy);
    if (typeid(*to_move) == typeid(CellFloor)) {
        curr_cell->clearCellContent();
        curr_cell = to_move;
        curr_cell->setCellContent(enemy);
    }

    return "ENEMY_STEPPED";
}
