//
// Created by mikeasta on 20.10.2021.
//

#include "EquipmentCLI.h"

EquipmentCLI::EquipmentCLI(Player *player):
    player(player) {}

void EquipmentCLI::print() {
    std::map<std::string, int> item_vocab = player->getEquipmentLabels();

    bool printed = false;
    for (const auto& item : item_vocab) {
        if (!printed) {
            std::cout << "\nPlayer equipment:";
            printed = true;
        }

        std::cout << "\n- " << item.first << " x" << item.second;
    }

    std::cout << std::endl;
}