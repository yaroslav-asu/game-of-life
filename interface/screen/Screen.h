#ifndef CELLS_LIVE_SCREEN_H
#define CELLS_LIVE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "../../internal/renderable/Renderable.h"

class Screen : public Renderable {
public:
    sf::RectangleShape background;

    virtual void render(sf::RenderTarget *window);

    virtual void update(sf::Event);
};


#endif //CELLS_LIVE_SCREEN_H
