#include <cstdlib>

#include "Game.hpp"
#include "Player.hpp"

void mg::Game::run(void) {
    Board board = user_interface.input_board();
    Player players[n_players];
    user_interface.wait_for_input();

    is_running = true;
    while (is_running) {
        for (int i = 0; i < n_players; i++) {
            system("clear"); // TODO: check system, const cmd_clear
            user_interface.print_whose_turn(i);
            user_interface.print_board(board);
            auto [x1, y1] = user_interface.input_card_position();
            auto [x2, y2] = user_interface.input_card_position();
            // TODO: check if card is not alr unmasked
            while (x1 == x2 && y1 == y2) {
                user_interface.print_equal_position_warning();
                auto new_pair = user_interface.input_card_position();
                x2 = new_pair.first;
                y2 = new_pair.second;
            }
            board.unmask_card(x1, y1);
            board.unmask_card(x2, y2);
            user_interface.print_board(board);
            if (board.get_card(x1, y1) == board.get_card(x2, y2)) {
                players[i].update_score();
            } else {
                board.mask_card(x1, y1);
                board.mask_card(x2, y2);
            }
            user_interface.wait_for_input();
        }
    }
}

mg::Game::Game(void) {
    run();
    // TODO: display quit message
}

void mg::Game::quit(void) {
    is_running = false;
}
