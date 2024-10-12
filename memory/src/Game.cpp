#include "Game.hpp"

void mg::Game::run(void) {
    Board board = user_interface.input_board();

    is_running = true;
    while (is_running) {
        quit();
    }
}

mg::Game::Game(void) {
    run();
    // TODO: display quit message
}

void mg::Game::quit(void) {
    is_running = false;
}
