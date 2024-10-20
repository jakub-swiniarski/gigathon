#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string>
#include <vector>

#include "Frame.hpp"

namespace ani {
    class Renderer {
        Vector                   frame_size;
        std::string              color_prefix;
        std::string              color_suffix;
        std::vector<std::string> colors;

        static constexpr int n_colors = 9;

    public:
        Renderer(Vector frame_size);

        void render(const Frame& frame) const;
        void print_color(int index) const;
        void cmd_clear(void) const;
    };
}

#endif // RENDERER_HPP
