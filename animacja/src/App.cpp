#include "App.hpp"
#include "Animation.hpp"

void ani::App::run(void) {
    Animation animation("animacja.txt");
    animation.play();
}

ani::App::App(void) {
    run();
}
