#include <csignal>

#include "App.hpp"
#include "Animation.hpp"
#include "Renderer.hpp"

void ani::App::quit(int signum) {
    ani::Renderer::cmd_clear();
    exit(signum);
}

void ani::App::run(void) {
    Animation animation("animacja.txt");
    
    while (true)
        animation.play();
}

ani::App::App(void) {
    std::signal(SIGINT, quit);

    run();
}
