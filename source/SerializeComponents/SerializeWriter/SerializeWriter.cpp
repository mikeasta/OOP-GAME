//
// Created by mikeasta on 21.12.2021.
//

#include "SerializeWriter.h"

void SerializeWriter::write(Field& field, Player& player) {
    json game_saving;

    // 1. Process Player
    game_saving["player"]["damage"]    = player.getDamage();
    game_saving["player"]["stamina"]   = player.getStamina();
    game_saving["player"]["defence"]   = player.getDefence();
    game_saving["player"]["equipment"] = player.getEquipmentLabels();

    // 2. Process Field
    auto cells = field.getCells();
    unsigned int rows = sizeof(cells), cols = sizeof(cells[0]);
    unsigned int i, j;

    auto iterator = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();

    while(curr_cell) {
        i = curr_cell->getX();
        j = curr_cell->getY();


        game_saving["field"][i][j]["cell_type"] = typeid(*curr_cell).name();

        InteractiveObject* content = curr_cell->getCellContent();

        if (content != nullptr) {
            game_saving["field"][i][j]["cell_content_type"] = typeid(*content).name();
            if (typeid(*content).name() == typeid(Enemy).name()) {
                auto enemy = dynamic_cast<Enemy*>(content);
                game_saving["field"][i][j]["cell_content_name"] = enemy->getType();
                game_saving["field"][i][j]["damage"] = enemy->getDamage();
                game_saving["field"][i][j]["stamina"] = enemy->getStamina();
                game_saving["field"][i][j]["defence"] = enemy->getDefence();

            } else if (typeid(*content).name() == typeid(Item).name()) {
                game_saving["field"][i][j]["cell_content_name"] = dynamic_cast<Item*>(content)->getName();
            }
        }

        curr_cell = iterator->getNext();
    }

    std::ofstream saving_file(path_to_saving_file);
    saving_file << game_saving;
    saving_file.close();
}