#include <fstream>
#include <iostream>

#include "GameStateManager.hpp"

mg::GameStateManager::GameStateManager(std::string filepath)
    : filepath(filepath) {}
    
void mg::GameStateManager::load(Board& board, Player* players, int& whose_turn) const {
    std::ifstream file(filepath);

    int width, height;
    file >> width >> height;
    board.resize({ width, height });

    std::string line;
    std::getline(file, line);
    for (int y = 0; y < height; y++) {
        std::getline(file, line);
        board.card_matrix[y] = line;
    }

    for (int y = 0; y < height; y++) {
        std::getline(file, line);
        for (int x = 0; x < width; x++)
            board.mask_matrix[y][x] = (line[x] == '1');
    }

    file >> players[0].score >> players[1].score;

    file >> whose_turn;
}

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
