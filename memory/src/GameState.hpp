#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <fstream>

namespace mg {
    class GameState {
        const std::string filepath;

        void save_board(std::ofstream& file, Board& board);

    public:
        GameState(std::string filepath);
        
        void save(Board& board, Player* players, int whose_turn);
    };
}

#endif // GAMESTATE_HPP
