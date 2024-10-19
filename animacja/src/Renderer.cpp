#include <iostream>

#include "Renderer.hpp"

ani::Renderer::Renderer(Vector frame_size)
    : frame_size(frame_size) {}

void ani::Renderer::render(const Frame& frame) const {
    for (int y = 0; y < frame_size.second; y++) {
        for (int x = 0; x < frame_size.first; x++) {
            // TODO: colors
            std::cout << frame.get_char({ x, y });
        }
        std::cout << '\n';
    }
}
