#include <cstdlib>

#include "Game.hpp"
#include "Board.hpp"
#include "GameStateManager.hpp"
#include "Player.hpp"

void mg::Game::run(void) {
    GameStateManager game_state_manager("stan_gry.txt");
    Board            board({ 0, 0 }, false);
    Player           players[2];
    int              whose_turn = 0;

    if (user_interface.input_load_game())
        game_state_manager.load(board, players, whose_turn);
    else
        board = user_interface.input_board();

    user_interface.wait_for_input();

    is_running = true;
    while (is_running) {
        cmd_clear();
     
        user_interface.print_points(players);
        user_interface.print_whose_turn(whose_turn);
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
            players[whose_turn].update_score();
        else {
            for (int i = 0; i < 2; i++)
                board.mask_card(positions[i]);
            whose_turn = (whose_turn + 1) % 2;
        }

        if (players[0].get_score() + players[1].get_score() >= board.get_card_count() / 2) {
            quit();
            cmd_clear();
            user_interface.print_summary(players);
            break;
        }

        if (user_interface.input_save_game())
            game_state_manager.save(board, players, whose_turn);
    }
}

mg::Game::Game(void) {
    run();
}

void mg::Game::quit(void) {
    is_running = false;
}

void mg::Game::cmd_clear(void) const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif // _WIN32
}
