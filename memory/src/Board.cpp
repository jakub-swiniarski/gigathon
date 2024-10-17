#include <algorithm>
#include <fstream>
#include <random>

#include "Board.hpp"

mg::Board::Board(Vector size) 
    : matrix_width(size.first),
      matrix_height(size.second),
      mask_matrix(size.second, std::vector<bool>(size.first, false)) {
    card_matrix = generate_card_matrix(size);
}

mg::CardMatrix mg::Board::generate_card_matrix(Vector size) const {
    auto        [width, height] = size;
    char        cur_card        = 'A';
    CardMatrix  matrix(height, std::string(width, 0));
    std::string flat_matrix(height * width, 0);

    for (int x = 0; x < (int)flat_matrix.size(); x++) {
        flat_matrix[x] = cur_card;
        if (x % 2 != 0)
            cur_card++;
    }

    std::random_device rd;
    std::mt19937       eng(rd());
    
    std::shuffle(flat_matrix.begin(), flat_matrix.end(), eng);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            matrix[y][x] = flat_matrix[x * width + y];

    return matrix;
}

void mg::Board::load_from_file(std::string filename) {
// TODO
}

void mg::Board::save_to_file(std::string filename) {
    std::ofstream file(filename);

    file << matrix_width << ' ' << matrix_height << '\n';
    for (int y = 0; y < matrix_height; y++) {
        file << card_matrix[y];
        file << '\n';
    }
    for (int y = 0; y < matrix_height; y++) {
        for (int x = 0; x < matrix_width; x++) 
            file << mask_matrix[y][x];
        file << '\n';
    }
}

char mg::Board::get_card(Vector position) const {
    return card_matrix[position.second][position.first];
}

bool mg::Board::get_mask(Vector position) const {
    return mask_matrix[position.second][position.first];
}

int mg::Board::get_card_count(void) const {
    return matrix_width * matrix_height;
}

void mg::Board::unmask_card(Vector position) {
    mask_matrix[position.second][position.first] = true;
}

void mg::Board::mask_card(Vector position) {
    mask_matrix[position.second][position.first] = false;
}
