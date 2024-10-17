#include <fstream>
#include <iostream>
#include <stdexcept>

#include "GameStateManager.hpp"

mg::GameStateManager::GameStateManager(std::string filepath)
    : filepath(std::move(filepath)) {}
    
void mg::GameStateManager::load(Board& board, Player* players, int& whose_turn) const {
    std::ifstream file(filepath);

    if (!file.is_open())
        throw std::runtime_error("Nie udalo sie otworzyc pliku stanu gry.");

    int width, height;
    if (!(file >> width >> height))
        throw std::runtime_error("Nie udalo sie odczytac wymiarow planszy.");
    board.resize({ width, height });

    std::string line;
    std::getline(file, line);
    for (int y = 0; y < height; y++) {
        std::getline(file, line);
        
        if (line.size() != static_cast<size_t>(width))
            throw std::runtime_error("Nieprawidlowy opis planszy.");

        board.card_matrix[y] = line;
    }

    for (int y = 0; y < height; y++) {
        std::getline(file, line);
        
        if (line.size() != static_cast<size_t>(width))
            throw std::runtime_error("Nieprawidlowy opis planszy.");

        for (int x = 0; x < width; x++)
            board.mask_matrix[y][x] = (line[x] == '1');
    }

    if (!(file >> players[0].score >> players[1].score))
        throw std::runtime_error("Nie udalo sie odczytac punktow graczy.");

    if (!(file >> whose_turn))
        throw std::runtime_error("Nie udalo sie odczytac, czyja kolej");
}

void mg::GameStateManager::save(Board& board, Player* players, int whose_turn) const {
    std::ofstream file(filepath);

    if (!file.is_open())
        throw std::runtime_error("Nie udalo sie otworzyc pliku do zapisu stanu gry.");

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
