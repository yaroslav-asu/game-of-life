#include "AliveCell.h"

AliveCell::AliveCell(CellConfig *config, game::Game *game, sf::Vector2u coords) : Cell(config, game, coords) {
    this->energy = config->defaultEnergy;
}

sf::Color AliveCell::color() {
    return this->game->colorSchemes[this->game->currentColorScheme]->color(energy);
}

void AliveCell::reproduce() {

}
