#include "Menu.h"
#include "../../game/Game.h"
#include "../components/button/template/ButtonTemplate.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <functional>

Menu::Menu(game::Game *game) {}

Menu::Menu(game::Game *game, std::vector<ButtonTemplate *> &buttonsTemplate) {
    this->background.setFillColor(sf::Color::White);
    this->background.setSize(sf::Vector2f(game->window->getSize()));
    this->game = game;

    sf::Vector2f buttonSize(120, 60);
    typedef void (game::Game::*gameMethod)();
    int buttonsGap = 10;
    sf::Vector2i startButtonsPos(
            game->window->getSize().x / 2. - buttonSize.x / 2.,
            game->window->getSize().y / 2. -
            (buttonsTemplate.size() * buttonSize.y + (buttonsTemplate.size() - 1) * buttonsGap) / 2.
    );

    for (int i = 0; i < buttonsTemplate.size(); i++) {
        this->buttons.push_back(
                new Button(
                        startButtonsPos.x,
                        startButtonsPos.y + buttonSize.y * i + buttonsGap * i,
                        buttonSize,
                        buttonsTemplate[i]->title,
                        game,
                        buttonsTemplate[i]->callback
                )
        );
    }
}

void Menu::render(sf::RenderTarget *target) {
    target->draw(this->background);
    for (Button *button: buttons) {
        button->render(*game->window);
    }
}

void Menu::update(sf::Event event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    for (Button *button: buttons) {
        button->update(mousePos, event);
    }
}
