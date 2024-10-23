#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Animation.hpp"
#include "Renderer.hpp"

ani::Animation::Animation(std::string filename) {
    std::ifstream file(filename);
    std::string   frame_dir;
    Vector        frame_size;
    int           n_frames;
    
    if (!file.is_open())
        throw std::runtime_error("Nie udalo sie otworzyc pliku animacji.");

    if (!(file >> frame_size.first >> frame_size.second >> n_frames))
        throw std::runtime_error("Nieprawidlowy opis animacji.");
    std::getline(file, frame_dir);
    std::getline(file, frame_dir);

    if (frame_dir.empty())
        throw std::runtime_error("Nie udalo sie odczytac nazwy katalogu klatek.");

    frames.reserve(n_frames);
    for (int i = 0; i < n_frames; i++) {
        std::ostringstream oss;
        oss << frame_dir << "/" << i << ".txt";
        frames.emplace_back(frame_size, oss.str());
    }

    renderer.set_frame_size(frame_size);
}

void ani::Animation::play(void) const {
    for (const auto& i : frames)
        renderer.render(i);
}
