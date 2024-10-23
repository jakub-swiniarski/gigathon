#include "App.hpp"
#include "Animation.hpp"

void ani::App::run(void) {
    Animation animation("animacja.txt");
    
    while (true)
        animation.play();
}

ani::App::App(void) {
    run();
}
