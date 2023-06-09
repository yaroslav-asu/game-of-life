#ifndef CELLS_LIVE_GAME_H
#define CELLS_LIVE_GAME_H


#include <SFML/System.hpp>
#include "../interface/screen/Screen.h"

enum {
    MAIN_MENU_SCREEN, GAME_FIELD_SCREEN, GAME_MENU_SCREEN
};

namespace game {
    class Game {
    private:
        int updateDelay;
    public:
        sf::RenderWindow *window;
        unsigned short currentScreenId = MAIN_MENU_SCREEN;
        bool running = true;
        bool paused = false;
        std::vector<Screen *> screens;

        explicit Game(sf::Vector2i size);

        void run();

        void render();

        void exit();

        void openGameMenu();

        void startGame();

        void togglePause();

        void continueGame();

    private:
        Screen *currentScreen();

        void update(sf::Event event);
    };
}

#endif //CELLS_LIVE_GAME_H
