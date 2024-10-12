#include <iostream>

#include "Game.hpp"

void mg::Game::run(void) {
    Board board = user_interface.input_board();
    user_interface.start_game();

    is_running = true;
    while (is_running) {
        std::cout << "Zaczynamy!\n";
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
