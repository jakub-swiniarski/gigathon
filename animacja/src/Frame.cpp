#include <fstream>
#include <stdexcept>

#include "Frame.hpp"

ani::Frame::Frame(Vector size, std::string filename) 
    : char_matrix(size.second, std::string(size.first, 0)),
      color_matrix(size.second, std::vector<int>(size.first, 0)) {
    std::ifstream file(filename);
    std::string   line;

    if (!file.is_open())
        throw std::runtime_error("Nie udalo sie otworzyc pliku klatki.");

    for (int y = 0; y < size.second; y++) {
        getline(file, line);

        if (line.size() != static_cast<size_t>(size.second))
            throw std::runtime_error("Nieprawidlowy opis klatki.");

        char_matrix[y] = line;
    }

    for (int y = 0; y < size.second; y++) {
        getline(file, line);

        if (line.size() != static_cast<size_t>(size.second))
            throw std::runtime_error("Nieprawidlowy opis klatki.");

        for (int x = 0; x < size.first; x++)
            color_matrix[y][x] = line[x] - '0';
    }
}

char ani::Frame::get_char(Vector position) const {
    return char_matrix[position.second][position.first];
}

int ani::Frame::get_color(Vector position) const {
    return color_matrix[position.second][position.first];
}
