//
// Created by mikeasta on 17.10.2021.
//

#include "PlayerCLI.h"

PlayerCLI::PlayerCLI(Player *player):player(player) {}

void PlayerCLI::print() {
    std::cout << "\nPlayer: ";
    if (player->getFullStamina() - player->getStamina())
        std::cout << "\n- health: " << player->getStamina() << " + " << player->getFullStamina() - player->getStamina();
    else
        std::cout << "\n- health: " << player->getStamina();

    if (player->getFullDamage() - player->getDamage())
        std::cout << "\n- damage: " << player->getDamage() << " + " << player->getFullDamage() - player->getDamage();
    else
        std::cout << "\n- damage: " << player->getDamage();

    if (player->getFullDefence() - player->getDefence())
        std::cout << "\n- defence: " << player->getDefence() << " + " << player->getFullDefence() - player->getDefence();
    else
        std::cout << "\n- defence: " << player->getDefence();

    std::cout << std::endl;
}
