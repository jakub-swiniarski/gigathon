#include <fstream>

#include "GameState.hpp"

void mg::GameState::save_board(Board& board) {
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

}

mg::GameState::GameState(std::string filepath)
    : filepath(filepath) {}

void mg::GameState::save(Board& board, Player* players, int whose_turn) {
    save_board(board);
} 
