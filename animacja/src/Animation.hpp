#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>

#include "Frame.hpp"

namespace ani {
    class Animation {
        Vector             size;
        std::vector<Frame> frames;

    public:
        Animation(std::string filename);

        void play(void) const;
    };
}

#endif // ANIMATION_HPP
