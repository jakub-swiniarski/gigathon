#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Frame.hpp"

namespace ani {
    class Renderer {
        Vector frame_size;

    public:
        Renderer(Vector frame_size);

        void render(const Frame& frame) const;
    };
}

#endif // RENDERER_HPP
