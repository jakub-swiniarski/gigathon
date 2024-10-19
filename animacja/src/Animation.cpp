#include <fstream>

#include "Animation.hpp"
#include "Renderer.hpp"

ani::Animation::Animation(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    int n_frames;
    file >> frame_size.first >> frame_size.second >> n_frames;
    getline(file, line);

    for (int i = 0; i < n_frames; i++)
        frames.emplace_back(frame_size, file);
}

void ani::Animation::play(void) const {
    // TODO: invoke renderer
    
    Renderer renderer(frame_size);

    renderer.render(frames[0]);
}
