#include <algorithm>
#include <random>

#include "Board.hpp"

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

void mg::Board::resize(Vector size) {
    matrix_width  = size.first;
    matrix_height = size.second;

    card_matrix.resize(matrix_height);
    mask_matrix.resize(matrix_height);

    for (auto& row : card_matrix)
        row.resize(matrix_width);
    for (auto& row : mask_matrix)
        row.resize(matrix_width);
}

mg::Board::Board(Vector size, bool make_random) 
    : matrix_width(size.first),
      matrix_height(size.second),
      card_matrix(size.second, std::string(size.first, 0)),
      mask_matrix(size.second, std::vector<bool>(size.first, false)) {
    if (make_random)
        card_matrix = generate_card_matrix(size);
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

mg::Vector mg::Board::get_size(void) const {
    return { matrix_width, matrix_height };
}

void mg::Board::unmask_card(Vector position) {
    mask_matrix[position.second][position.first] = true;
}

void mg::Board::mask_card(Vector position) {
    mask_matrix[position.second][position.first] = false;
}
