#include <iostream>

#include "App.hpp"

void ani::App::run(void) {
    is_running = true;
    while (is_running) {
        std::cout << "TEST!\n";
        quit();
    }
}

void ani::App::quit(void) {
    is_running = false;
}

ani::App::App(void) {
    run();
}
