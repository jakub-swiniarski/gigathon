#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <utility>

#include "Board.hpp"

namespace mg {
    class UserInterface {
        int board_width;
        int board_height;
        
    public:
        Board                input_board(void);
        void                 wait_for_input(void) const;
        std::pair<int, int>  input_card_position(void) const;
    };
}

#endif // USERINTERFACE_HPP
