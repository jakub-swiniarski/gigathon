#include <fstream>

#include "GameStateManager.hpp"

mg::GameStateManager::GameStateManager(std::string filepath)
    : filepath(filepath) {}

void mg::GameStateManager::save(Board& board, Player* players, int whose_turn) const {
    std::ofstream file(filepath);

    file << board.matrix_width << ' ' << board.matrix_height << '\n';
    for (int y = 0; y < board.matrix_height; y++) {
        file << board.card_matrix[y];
        file << '\n';
    }
    for (int y = 0; y < board.matrix_height; y++) {
        for (int x = 0; x < board.matrix_width; x++) 
            file << board.mask_matrix[y][x];
        file << '\n';
    }

    file << players[0].get_score() << ' ' << players[1].get_score() << '\n';

    file << whose_turn;
} 
