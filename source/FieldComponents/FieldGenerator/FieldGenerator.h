// Данный класс генерирует двумерный массив клеток
#pragma once

#include "../../CellComponents/Cell/Cell.h"
#include "../../CellComponents/CellEntrance/CellEntrance.h"
#include "../../CellComponents/CellExit/CellExit.h"
#include "../../CellComponents/CellFloor/CellFloor.h"
#include "../../CellComponents/CellWall/CellWall.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"

class FieldGenerator {
public:
    FieldGenerator() {};

    ~FieldGenerator() = default;

    // Generates room
    Cell*** generateField(unsigned int rows = 0, unsigned int cols = 0);
};

