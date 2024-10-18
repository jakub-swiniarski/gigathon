#include <cstdlib>
#include <iostream>

#include "App.hpp"

int main(void) {
    try {
        ani::App app;
    } catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        throw std::runtime_error("Nieznany blad.");
    }

    return EXIT_SUCCESS;
}
