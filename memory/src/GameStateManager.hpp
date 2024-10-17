#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include "Board.hpp"
#include "Player.hpp"

namespace mg {
    class GameStateManager {
        const std::string filepath;

    public:
        GameStateManager(std::string filepath);
        
        void save(Board& board, Player* players, int whose_turn) const;
    };
}

#endif // GAMESTATEMANAGER_HPP
