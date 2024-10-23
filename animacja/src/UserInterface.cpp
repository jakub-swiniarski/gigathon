#include <iostream>

#include "UserInterface.hpp"

std::string ani::UserInterface::input_filename(void) const {
    std::string filename;
    std::cout << "Wprowadz nazwe pliku animacji: ";
    std::cin >> filename;

    return filename;
}
