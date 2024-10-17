#include <fstream>

#include "GameStateManager.hpp"

void mg::GameStateManager::save_board(std::ofstream& file, Board& board) {
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
}

mg::GameStateManager::GameStateManager(std::string filepath)
    : filepath(filepath) {}

void mg::GameStateManager::load(Board& board, Player* players, int& whose_turn) {

}

void mg::GameStateManager::save(Board& board, Player* players, int whose_turn) {
    std::ofstream file(filepath);

    save_board(file, board);
    file << players[0].get_score() << ' ' << players[1].get_score() << '\n';
    file << whose_turn;
} 
