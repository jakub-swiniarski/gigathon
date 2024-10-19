#include <iostream>

#include "App.hpp"
#include "Animation.hpp"

void ani::App::run(void) {
    Animation animation("animacja.txt");

    is_running = true;
    while (is_running) {
        animation.play();
        quit();
    }
}

void ani::App::quit(void) {
    is_running = false;
}

ani::App::App(void) {
    run();
}
