#include <cstdlib>
#include <iostream>

#include "Game.hpp"

int main(void) {
    try {
        mg::Game game;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        throw std::runtime_error("Unknown error.");
    }

    return EXIT_SUCCESS;
}
