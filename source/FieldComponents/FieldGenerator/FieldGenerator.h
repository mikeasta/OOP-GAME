// Данный класс генерирует двумерный массив клеток
#ifndef OOP_GAME_FIELD_GENERATOR_HEADLINE
#define OOP_GAME_FIELD_GENERATOR_HEADLINE

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
    Cell*** generateStandartField(unsigned int rows = 0, unsigned int cols = 0);
};

#endif