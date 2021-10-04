#include <iostream>
#include "Field.cpp"
#include "Cell.cpp"

class FieldIterator {
private:
    const Field* field;
    int curr_row = 0;
    int curr_col = 0;
public:
    FieldIterator(const Field* field):field(field) {}

    Cell* next() {
        
    }
};