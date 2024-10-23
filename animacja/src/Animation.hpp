#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>

#include "Frame.hpp"
#include "Renderer.hpp"

namespace ani {
    class Animation {
        std::vector<Frame> frames;
        Renderer           renderer;

    public:
        Animation(std::string filename);

        void play(void) const;
    };
}

#endif // ANIMATION_HPP
