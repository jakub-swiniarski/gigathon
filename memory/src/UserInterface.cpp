#include <iostream>

#include "UserInterface.hpp"
#include "Board.hpp"

mg::Board mg::UserInterface::input_board(void) {
    std::cout << "Wprowadz rozmiar planszy (2 liczby oddzielone spacja): ";
    std::cin >> board_width >> board_height;

    while (board_width <= 0 || board_height <= 0) {
        std::cout << "Liczby powinny byc dodatnie. Wprowadz rozmiar jeszcze raz: ";
        std::cin >> board_width >> board_height;
    }

    while ((board_width * board_height) % 2 != 0) {
        std::cout << "Liczba pol powinna byc liczba parzysta. Wprowadz rozmiar jeszcze raz: ";
        std::cin >> board_width >> board_height;
    }

    std::cout << "Utworzono plansze o rozmiarze " << board_width << " x " << board_height << "!\n\n";

    return Board(board_width, board_height);
}

void mg::UserInterface::wait_for_input(void) const {
    std::cout << "Wcisnij dowolny przycisk, aby kontynuowac...\n";
    std::cin.get();
    std::cin.get();
}

std::pair<int, int> mg::UserInterface::input_card_position(void) const {
    int x, y;
    std::cout << "Wprowadz pozycje karty (x, y): ";
    std::cin >> x >> y;    

    while (x < 0 || y < 0) {
        std::cout << "Wspolrzedne nie moga byc ujemne. Wprowadz pozycje jeszcze raz: ";
        std::cin >> x >> y;
    }

    while (x >= board_width || y >= board_height) {
        std::cout << "Wspolrzedne nie moga wykraczac poza plansze. Wprowadz pozycje jeszcze raz: ";
        std::cin >> x >> y;
    }


    return { x, y };
}
