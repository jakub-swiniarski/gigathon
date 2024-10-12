#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#include "common.hpp"

namespace mg {
    using CardType       = char;
    using CardMatrixType = std::vector<std::vector<CardType>>;
    using MaskMatrixType = std::vector<std::vector<bool>>;

    class Board {
        const UI matrix_width;
        const UI matrix_height;
        CardMatrixType card_matrix;
        MaskMatrixType mask_matrix;

    public:
        static constexpr CardType error_card = -1;

        Board(UI width, UI height);

        CardMatrixType generate_card_matrix(UI width, UI height) const;
        CardType       get_card(UI x, UI y) const;
        void           unmask_card(UI x, UI y);
    };
}

#endif // BOARD_HPP
