#include <cstdlib>
#include <iostream>

#include "Game.hpp"
#include "Board.hpp"
#include "GameState.hpp"
#include "Player.hpp"

void mg::Game::run(void) {
    GameState game_state("stan_gry.txt");

    if (user_interface.input_load_game()) {
        std::cout << "ZALADOWANO GRE!\n";
    }
    Board board = user_interface.input_board();
    Player players[2];
    user_interface.wait_for_input();

    is_running = true;
    while (is_running) {
        for (int i = 0; i < 2; i++) {
            cmd_clear();
            
            if (user_interface.input_save_game()) {
                game_state.save(board, players, i);
            }
            
            user_interface.print_points(players);
            user_interface.print_whose_turn(i);
            user_interface.print_board(board);

            mg::Vector positions[2];
            for (int i = 0; i < 2; i++)
                positions[i] = user_interface.input_card_position(board);
            while (positions[0] == positions[1]) {
                user_interface.print_equal_position_warning();
                positions[1] = user_interface.input_card_position(board);
            }
            
            for (int i = 0; i < 2; i++)
                board.unmask_card(positions[i]);
            user_interface.print_board(board);
            
            if (board.get_card(positions[0]) == board.get_card(positions[1]))
                players[i].update_score();
            else {
                for (int i = 0; i < 2; i++)
                    board.mask_card(positions[i]);
            }

            if (players[0].get_score() * 2 + players[1].get_score() * 2 >= board.get_card_count()) {
                quit();
                cmd_clear();
                user_interface.print_summary(players);
                break;
            } else
                user_interface.wait_for_input();
        }
    }
}

mg::Game::Game(void) {
    run();
    // TODO: display quit message
}

void mg::Game::cmd_clear(void) {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif // _WIN32
}

void mg::Game::quit(void) {
    is_running = false;
}
