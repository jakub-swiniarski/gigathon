#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string>
#include <vector>

#include "Frame.hpp"

namespace ani {
    class Renderer {
        Vector                   frame_size;
        std::vector<std::string> colors;

    public:
        Renderer(Vector frame_size);

        void render(const Frame& frame) const;
        void wait(int n_seconds) const;
        void cmd_clear(void) const;
    };
}

#endif // RENDERER_HPP
