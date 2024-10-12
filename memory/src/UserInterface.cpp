#include <iostream>

#include "UserInterface.hpp"
#include "Board.hpp"

mg::Board mg::UserInterface::input_board(void) {
    int width, height;
    std::cout << "Wprowadz rozmiar planszy (2 liczby oddzielone spacja): ";
    std::cin >> width >> height;

    while (width <= 0 || height <= 0) {
        std::cout << "Liczby powinny byc dodatnie. Wprowadz rozmiar jeszcze raz: ";
        std::cin >> width >> height;
    }

    while ((width * height) % 2 != 0) {
        std::cout << "Liczba pol powinna byc liczba parzysta. Wprowadz rozmiar jeszcze raz: ";
        std::cin >> width >> height;
    }

    std::cout << "Utworzono plansze o rozmiarze " << width << " x " << height << "!\n\n";

    return Board(width, height);
}
