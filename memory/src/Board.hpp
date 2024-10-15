#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

namespace mg {
    using CardMatrix = std::vector<std::string>;
    using MaskMatrix = std::vector<std::vector<bool>>;

    class Board {
        const int matrix_width;
        const int matrix_height;
        CardMatrix card_matrix;
        MaskMatrix mask_matrix;

    public:
        Board(int width, int height);

        CardMatrix generate_card_matrix(int width, int height) const;
        char       get_card(int x, int y) const;
        bool       get_mask(int x, int y) const;
        int        get_card_count(void) const;
        void       unmask_card(int x, int y);
        void       mask_card(int x, int y);
    };
}

#endif // BOARD_HPP
