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
        static constexpr int delay_ms = 500;

    public:
        Renderer(void);

        void        render(const Frame& frame) const;
        void        print_color(int index) const;
        static void cmd_clear(void);
        void        set_frame_size(Vector size);
    };
}

#endif // RENDERER_HPP
