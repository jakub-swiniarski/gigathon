#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "Renderer.hpp"

ani::Renderer::Renderer(Vector frame_size)
    : frame_size(frame_size),
      color_prefix("\033["),
      color_suffix("m"),
      colors(n_colors) {
    colors[0] = "0";
    for (int i = 1; i < n_colors; i++)
        colors[i] = std::to_string(29 + i);
}

void ani::Renderer::render(const Frame& frame) const {
    cmd_clear();
    std::cout << '\a';
    for (int y = 0; y < frame_size.second; y++) {
        for (int x = 0; x < frame_size.first; x++) {
            print_color(frame.get_color({x, y}));
            std::cout << frame.get_char({ x, y });
        }
        std::cout << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    print_color(0);
}

void ani::Renderer::print_color(int index) const {
    std::cout << color_prefix << colors[index] << color_suffix;
}

void ani::Renderer::cmd_clear(void) const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif // _WIN32
}
