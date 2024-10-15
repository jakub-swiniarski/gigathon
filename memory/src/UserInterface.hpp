#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <utility>

#include "Board.hpp"
#include "Player.hpp"

namespace mg {
    class UserInterface {
        int board_width;
        int board_height;
        
    public:
        Board                input_board(void);
        std::pair<int, int>  input_card_position(const Board& board) const;
        void                 wait_for_input(void) const;
        void                 print_board(const Board& board) const;
        void                 print_equal_position_warning(void) const;
        void                 print_whose_turn(int index) const;
        void                 print_summary(const Player* players) const ;
    };
}

#endif // USERINTERFACE_HPP
