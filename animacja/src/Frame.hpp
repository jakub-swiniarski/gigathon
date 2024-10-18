#ifndef FRAME_HPP
#define FRAME_HPP

#include <fstream>
#include <string>
#include <utility>
#include <vector>

namespace ani {
    using Vector      = std::pair<int, int>;
    using CharMatrix  = std::vector<std::string>;
    using ColorMatrix = std::vector<std::vector<int>>; 

    class Frame {
        CharMatrix  char_matrix;
        ColorMatrix color_matrix;

    public:
        Frame(Vector size, std::ifstream& file);

        char get_char(Vector position) const;
        int  get_color(Vector position) const;
    };
}

#endif // FRAME_HPP
