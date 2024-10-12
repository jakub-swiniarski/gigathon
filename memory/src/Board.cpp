#include <algorithm>
#include <random>

#include "Board.hpp"

mg::Board::Board(UI width, UI height) 
    : matrix_width(width),
      matrix_height(height),
      mask_matrix(height, std::vector<bool>(width, false)) {
    card_matrix = generate_card_matrix(width, height);
}

mg::CardMatrixType mg::Board::generate_card_matrix(UI width, UI height) const {
    CardType              cur_card = 'A';
    CardMatrixType        matrix(height, std::vector<CardType>(width));
    std::vector<CardType> flat_matrix(height * width);

    for (UI x = 0; x < flat_matrix.size(); x++) {
        flat_matrix[x] = cur_card;
        if (x % 2 != 0)
            cur_card++;
    }

    std::random_device rd;
    std::mt19937       eng(rd());
    
    std::shuffle(flat_matrix.begin(), flat_matrix.end(), eng);

    for (UI y = 0; y < height; y++)
        for (UI x = 0; x < width; x++)
            matrix[y][x] = flat_matrix[x * width + y];

    return matrix;
}

mg::CardType mg::Board::get_card(UI x, UI y) const {
    return card_matrix[y][x];
}

bool mg::Board::get_mask(UI x, UI y) const {
    return mask_matrix[y][x];
}

void mg::Board::unmask_card(UI x, UI y) {
    mask_matrix[y][x] = true;
}

void mg::Board::mask_card(UI x, UI y) {
    mask_matrix[y][x] = false;
}
