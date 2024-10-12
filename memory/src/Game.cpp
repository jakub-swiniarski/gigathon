#include <cstdlib>

#include "Game.hpp"
#include "Player.hpp"

void mg::Game::run(void) {
    Board board = user_interface.input_board();
    Player players[2];
    user_interface.wait_for_input();

    is_running = true;
    while (is_running) {
        system("clear"); // TODO: check system, clear command in common.hpp
        user_interface.print_board(board);
        auto [x1, y1] = user_interface.input_card_position();
        auto [x2, y2] = user_interface.input_card_position();
        while (x1 == x2 && y1 == y2) {
            auto new_pair = user_interface.input_card_position();
            x2 = new_pair.first;
            y2 = new_pair.second;
        }
        board.unmask_card(x1, y1);
        board.unmask_card(x2, y2);
        user_interface.print_board(board);
        if (board.get_card(x1, y1) == board.get_card(x2, y2)) {
            players[0].update_score();
        } else {
            board.mask_card(x1, y1);
            board.mask_card(x2, y2);
        }
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
