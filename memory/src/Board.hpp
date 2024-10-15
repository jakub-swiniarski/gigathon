#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

namespace mg {
    using CardType       = char;
    using CardMatrixType = std::vector<std::vector<CardType>>;
    using MaskMatrixType = std::vector<std::vector<bool>>;

    class Board {
        const int matrix_width;
        const int matrix_height;
        CardMatrixType card_matrix;
        MaskMatrixType mask_matrix;

    public:
        Board(int width, int height);

        CardMatrixType generate_card_matrix(int width, int height) const;
        CardType       get_card(int x, int y) const;
        bool           get_mask(int x, int y) const;
        int            get_card_count(void) const;
        void           unmask_card(int x, int y);
        void           mask_card(int x, int y);
    };
}

#endif // BOARD_HPP
