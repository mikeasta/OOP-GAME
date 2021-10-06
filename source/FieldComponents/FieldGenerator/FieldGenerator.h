// Данный класс генерирует двумерный массив клеток
#pragma once

#include "../../CellComponents/Cell/Cell.h"
#include "../../CellComponents/CellEntrance/CellEntrance.h"
#include "../../CellComponents/CellExit/CellExit.h"
#include "../../CellComponents/CellFloor/CellFloor.h"
#include "../../CellComponents/CellWall/CellWall.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"

class FieldGenerator {
private:
    unsigned int tmp_rows;
    unsigned int tmp_cols;
public:
    FieldGenerator(unsigned int rows = 0, unsigned int cols = 0):
        tmp_rows(rows + 2),
        tmp_cols(cols + 2) {};

    ~FieldGenerator() = default;
    Cell*** generateStandartField(unsigned int rows = 0, unsigned int cols = 0);

    void setTmpRows(unsigned int rows) { tmp_rows = rows; }
    void setTmpCols(unsigned int cols) { tmp_cols = cols; }

    unsigned int getTmpRows() { return tmp_rows; }
    unsigned int getTmpCols() { return tmp_cols; }
};

