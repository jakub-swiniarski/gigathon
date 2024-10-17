#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

namespace mg {
    using CardMatrix = std::vector<std::string>;
    using MaskMatrix = std::vector<std::vector<bool>>;
    using Vector     = std::pair<int, int>;

    class Board {
        const int matrix_width;
        const int matrix_height;
        CardMatrix card_matrix;
        MaskMatrix mask_matrix;

    public:
        Board(Vector size);

        CardMatrix generate_card_matrix(Vector size) const;
        void       load_from_file(const std::string& filename);
        void       save_to_file(const std::string& filename);
        char       get_card(Vector position) const;
        bool       get_mask(Vector position) const;
        int        get_card_count(void) const;
        void       unmask_card(Vector position);
        void       mask_card(Vector position);
    };
}

#endif // BOARD_HPP
