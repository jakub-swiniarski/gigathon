#include <fstream>
#include <stdexcept>

#include "Animation.hpp"
#include "Renderer.hpp"

ani::Animation::Animation(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    int n_frames;
    if (!(file >> frame_size.first >> frame_size.second >> n_frames))
        throw std::runtime_error("Nieprawidlowy opis animacji.");
    getline(file, line);

    for (int i = 0; i < n_frames; i++)
        frames.emplace_back(frame_size, file);
}

void ani::Animation::play(void) const {
    Renderer renderer(frame_size);

    for (const auto& i : frames)
        renderer.render(i);
}
