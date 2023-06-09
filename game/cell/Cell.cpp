#include "Cell.h"

Cell::Cell(game::Game *game) : Cell(new CellConfig(), game) {}

Cell::Cell(CellConfig *config, game::Game *game) {
    this->game = game;
    this->size = config->size;
    this->shape = sf::RectangleShape(sf::Vector2f((float) config->size, (float) config->size));
}

Cell::Cell(CellConfig *config, game::Game *game, sf::Vector2u coords) : Cell(config, game) {
    this->coords = coords;
    this->shape.setPosition((float) coords.x, (float) coords.y);
}


void Cell::render(sf::RenderTarget* target) {
    this->shape.setFillColor(sf::Color::Black);
    target->draw(this->shape);
}

void Cell::update() {

}

sf::Color Cell::color() {
    return {};
}
