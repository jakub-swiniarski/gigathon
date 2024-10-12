#include "Game.hpp"
#include "Player.hpp"

void mg::Game::run(void) {
    Board board = user_interface.input_board();
    Player players[2];
    user_interface.wait_for_input();

    is_running = true;
    while (is_running) {
        user_interface.print_board(board);
        auto [x1, y1] = user_interface.input_card_position();
        auto [x2, y2] = user_interface.input_card_position();
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
