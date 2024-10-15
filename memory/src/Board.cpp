#include <algorithm>
#include <random>

#include "Board.hpp"

mg::Board::Board(int width, int height) 
    : matrix_width(width),
      matrix_height(height),
      mask_matrix(height, std::vector<bool>(width, false)) {
    card_matrix = generate_card_matrix(width, height);
}

mg::CardMatrixType mg::Board::generate_card_matrix(int width, int height) const {
    CardType              cur_card = 'A';
    CardMatrixType        matrix(height, std::vector<CardType>(width));
    std::vector<CardType> flat_matrix(height * width);

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

mg::CardType mg::Board::get_card(int x, int y) const {
    return card_matrix[y][x];
}

bool mg::Board::get_mask(int x, int y) const {
    return mask_matrix[y][x];
}

int mg::Board::get_card_count(void) const {
    return matrix_width * matrix_height;
}

void mg::Board::unmask_card(int x, int y) {
    mask_matrix[y][x] = true;
}

void mg::Board::mask_card(int x, int y) {
    mask_matrix[y][x] = false;
}
