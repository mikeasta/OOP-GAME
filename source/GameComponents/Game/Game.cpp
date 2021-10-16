//
// Created by mikeasta on 16.10.2021.
//

#include "Game.h"

void Game::start() {
    if (!game_is_started) {
        game_is_started = true;
        unsigned int field_rows = 5, field_cols = 7;
        FieldGenerator generator = FieldGenerator();
        Cell*** cells = generator.generateField(field_rows, field_cols);
        Field new_field = Field(cells, field_rows, field_cols);
        Player new_player = Player(10, 10, 10);
        ItemPlacer item_placer;
        EnemyPlacer enemy_placer;
        FieldCLI new_field_cli = FieldCLI(&new_field);

        new_player.spawn(&new_field);
        item_placer.fillField(&new_field);
        enemy_placer.fillField(&new_field);

        new_field_cli.print();
    }
}
