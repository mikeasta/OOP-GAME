#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Cell.cpp"
#include "CellWall.cpp"
#include "CellEntrance.cpp"
#include "CellExit.cpp"
#include "CellFloor.cpp"
#include "CellLava.cpp"

// Класс, генерирующий последовательность клеток
// в двумерном массиве
class CellSequenceGenerator {
public:
    CellSequenceGenerator() {};
    Cell** generate_field(int rows = 0, int cols = 0, int lava_cells_percent = 0) {

        Cell** cell_sequence;

        // If there is field 0x0
        if (!rows & !cols) {
            return;
        }

        // Create field structure
        cell_sequence = new Cell*[rows+2];
        for (int i = 0; i < rows+2; i++) 
            cell_sequence[i] = new Cell[cols+2];


        // Fill field
        for (int i = 0; i < rows+2; i++) 
            for (int j = 0; i < cols+2; j++)
            {
                if ((i == 0 || i == rows+1) || (j == 0 || j == cols+1))
                    cell_sequence[i][j] = static_cast<Cell>(*(new CellWall()));
                else 
                    cell_sequence[i][j] = static_cast<Cell>(*(new CellFloor()));
            }

        
        double exit_border_option = rand() % 2;

        // Exit in vertical col
        if (exit_border_option < 0.5) {
            double vertical_col = rand() % 2;
            int row_idx         = rand() % rows;
            if (vertical_col < 0.5)
            {
                cell_sequence[row_idx + 1][1]      = static_cast<Cell>(*(new CellExit()));
                cell_sequence[row_idx + 1][cols+1] = static_cast<Cell>(*(new CellEntrance()));
            } else {
                cell_sequence[row_idx + 1][1]      = static_cast<Cell>(*(new CellEntrance()));
                cell_sequence[row_idx + 1][cols+1] = static_cast<Cell>(*(new CellExit()));
            }
        } else {
            double horizontal_row = rand() % 2;
            int col_idx           = rand() % cols;
            if (horizontal_row < 0.5)
            {
                cell_sequence[1][col_idx + 1]      = static_cast<Cell>(*(new CellExit()));
                cell_sequence[rows+1][col_idx + 1] = static_cast<Cell>(*(new CellEntrance()));
            } else {
                cell_sequence[1][col_idx + 1]      = static_cast<Cell>(*(new CellEntrance()));
                cell_sequence[rows+1][col_idx + 1] = static_cast<Cell>(*(new CellExit()));
            }
        }


        // Fill with Lava
        int cell_amount = rows * cols;
        int lava_amount = round(cell_amount * lava_cells_percent / 100);
        for (int i = lava_amount; i > 0; i--) {
            int lava_row = rand() % rows;
            int lava_col = rand() % cols;

            if (typeid(cell_sequence[lava_row][lava_col]) == typeid(CellLava)) {
                i++;
            } else {
                delete &cell_sequence[lava_row][lava_col];
                cell_sequence[lava_row][lava_col] = static_cast<Cell>(*(new CellLava()));
            }
        }

        return cell_sequence;
    }
};
