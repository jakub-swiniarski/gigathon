#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <fstream>

namespace mg {
    class GameStateManager {
        const std::string filepath;

        void save_board(std::ofstream& file, Board& board);

    public:
        GameStateManager(std::string filepath);
        
        void save(Board& board, Player* players, int whose_turn);
    };
}

#endif // GAMESTATEMANAGER_HPP
