#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include "FieldConfig.h"

FieldConfig::FieldConfig() : FieldConfig(sf::Vector2u(100, 100), CellConfig().size) {}

FieldConfig::FieldConfig(sf::Vector2u pixelSize, unsigned int cellSize) {
    this->size = pixelSize;
    this->rowCount = static_cast<unsigned int>(pixelSize.y / cellSize);
    this->columnCount = static_cast<unsigned int>(pixelSize.x / cellSize);
    this->backgroundColor = sf::Color(150, 150, 150);
}

