#include <fstream>

#include "Animation.hpp"

ani::Animation::Animation(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    int n_frames;
    file >> size.first >> size.second >> n_frames;
    getline(file, line);

    for (int i = 0; i < n_frames; i++)
        frames.emplace_back(size, file);
}

void ani::Animation::play(void) const {
    // TODO: invoke renderer
}
