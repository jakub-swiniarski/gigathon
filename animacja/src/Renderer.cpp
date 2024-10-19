#include <chrono>
#include <iostream>
#include <thread>

#include "Renderer.hpp"

ani::Renderer::Renderer(Vector frame_size)
    : frame_size(frame_size),
      colors(9) {
    colors[0] = "\033[0m";
    colors[1] = "\033[30m";
    colors[2] = "\033[31m";
    colors[3] = "\033[32m";
    colors[4] = "\033[33m";
    colors[5] = "\033[34m";
    colors[6] = "\033[35m";
    colors[7] = "\033[36m";
    colors[8] = "\033[37m";
    // TODO: improve this, save suffix and prefx separately
}

void ani::Renderer::render(const Frame& frame) const {
    cmd_clear();
    for (int y = 0; y < frame_size.second; y++) {
        for (int x = 0; x < frame_size.first; x++) {
            std::cout << colors[frame.get_color({x, y})];
            std::cout << frame.get_char({ x, y });
        }
        std::cout << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << colors.front();
}

void ani::Renderer::cmd_clear(void) const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif // _WIN32
}