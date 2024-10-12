#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Board.hpp"

namespace mg {
    class UserInterface {
        
    public:
        Board input_board(void) const;
        void  start_game(void) const;
    };
}

#endif // USERINTERFACE_HPP
