#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <utility>

#include "Board.hpp"
#include "Player.hpp"

namespace mg {
    class UserInterface {
        bool                input_choice(std::string question) const;

    public:
        bool                input_load_game(void) const;
        bool                input_save_game(void) const;
        Board               input_board(void) const;
        std::pair<int, int> input_card_position(const Board& board) const;
        void                print_board(const Board& board) const;
        void                print_equal_position_warning(void) const;
        void                print_points(const Player* players) const;
        void                print_whose_turn(int index) const;
        void                print_summary(const Player* players) const ;
        void                wait_for_input(void) const;
    };
}

#endif // USERINTERFACE_HPP
