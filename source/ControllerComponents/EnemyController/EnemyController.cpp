//
// Created by mikeasta on 17.10.2021.
//

#include "EnemyController.h"

EnemyController::EnemyController(Enemy *enemy, Field *field, Cell* curr_cell):
    enemy(enemy),
    field(field),
    curr_cell(curr_cell) {};


std::string EnemyController::move(std::string direction) {
    if (!enemy->getState())
        return "DIED";

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
    if (to_move->isCellContentExist())
        return "ENEMY_STOPPED";

    std::pair<bool, std::string> response = to_move->stepEffect(enemy);
    if (typeid(*to_move) == typeid(CellFloor)) {
        curr_cell->clearCellContent();
        curr_cell = to_move;
        curr_cell->setCellContent(enemy);
    }

    return "ENEMY_STEPPED";
}
