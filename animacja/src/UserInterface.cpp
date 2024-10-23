#include <iostream>

#include "UserInterface.hpp"

std::string ani::UserInterface::input_filepath(void) const {
    std::string filepath;
    std::cout << "Wprowadz ścieżkę do pliku animacji: ";
    std::cin >> filepath;

    return filepath;
}
