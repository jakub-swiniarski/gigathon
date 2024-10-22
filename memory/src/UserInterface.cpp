#include <iostream>
#include <limits>

#include "UserInterface.hpp"
#include "Board.hpp"

bool mg::UserInterface::input_choice(std::string question) const {
    std::string input;
    int         choice = -1;
    
    while (choice == -1) {
        std::cout << question << " (T/N): ";
        std::cin >> input;
        if (input[0] == 'T'
         || input[0] == 't')
            choice = 1;
        else if (input[0] == 'N'
              || input[0] == 'n')
            choice = 0;
        else {
            std::cout << "Nieprawidlowy wybor. ";
            choice = -1;
        }
    }

    return choice;
}

bool mg::UserInterface::input_load_game(void) const {
    return input_choice("Czy chcesz wczytac ostatnia gre?");
}

bool mg::UserInterface::input_save_game(void) const {
    return input_choice("Czy chcesz zapisac stan gry?");
}

mg::Board mg::UserInterface::input_board(void) {
    int width, height;

    while (true) {
        std::cout << "Wprowadz rozmiar planszy (2 liczby oddzielone spacja): ";
        std::cin >> width >> height;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Niepoprawne dane. ";
            continue;
        }

        if (width <= 0 || height <= 0) {
            std::cout << "Liczby powinny byc dodatnie. ";
            continue;
        }

        if ((width * height) % 2 != 0) {
            std::cout << "Laczna liczba pol powinna byc parzysta. ";
            continue;
        }
        
        if (width * height > Board::max_card_count) {
            std::cout << "Plansza jest zbyt wielka. ";
            continue;
        }

        break;
    }

    std::cout << "Utworzono plansze o rozmiarze " << width << " x " << height << "!\n\n";

    return Board({ width, height }, true);
}

std::pair<int, int> mg::UserInterface::input_card_position(const Board& board) const {
    int x, y;

    while (true) {
        std::cout << "Wprowadz pozycje karty (x, y): ";
        std::cin >> x >> y;    
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Niepoprawne dane. ";
            continue;
        }

        if (x < 0 || y < 0
         || x >= board.get_size().first || y >= board.get_size().second) {
            std::cout << "Wspolrzedne nie moga wykraczac poza plansze. ";
            continue;
        }

        if (board.get_mask({ x, y })) {
            std::cout << "Karta zostala juz dopasowana.  ";
            continue;
        }

        break;
    }

    return { x, y };
}

void mg::UserInterface::print_board(const Board& board) const {
    for (int y = 0; y < board.get_size().second; y++) {
        for (int x = 0; x < board.get_size().first; x++) {
            if (board.get_mask({ x, y }))
                std::cout << board.get_card({ x, y });
            else
                std::cout << '#';
        }
        std::cout << '\n';
    }
}

void mg::UserInterface::print_equal_position_warning(void) const {
    std::cout << "Wprowadzono takie same pozycje. ";
}

void mg::UserInterface::print_points(const Player* players) const {
    for (int i = 0; i < 2; i++)
        std::cout << "Punkty gracza nr " << i << ": " << players[i].get_score() << '\n';
}

void mg::UserInterface::print_whose_turn(int index) const {
    std::cout << "Teraz kolej gracza nr " << index << ".\n";
}

void mg::UserInterface::print_summary(const Player* players) const {
    if (players[0].get_score() == players[1].get_score())
        std::cout << "Remis!\n";
    else if (players[0].get_score() > players[1].get_score())
        std::cout << "Wygral gracz nr 0.\n";
    else
        std::cout << "Wygral gracz nr 1.\n";
    print_points(players);
}

void mg::UserInterface::wait_for_input(void) const {
    std::cout << "Wcisnij dowolny przycisk, aby kontynuowac...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
