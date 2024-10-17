#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

namespace mg {
    class GameStateManager;

    using CardMatrix = std::vector<std::string>;
    using MaskMatrix = std::vector<std::vector<bool>>;
    using Vector     = std::pair<int, int>;

    class Board {
        friend class mg::GameStateManager;

        const int matrix_width;
        const int matrix_height;
        CardMatrix card_matrix;
        MaskMatrix mask_matrix;

        CardMatrix generate_card_matrix(Vector size) const;

    public:
        Board(Vector size, bool make_random);

        char get_card(Vector position) const;
        bool get_mask(Vector position) const;
        int  get_card_count(void) const;
        void unmask_card(Vector position);
        void mask_card(Vector position);
    };
}

#endif // BOARD_HPP
