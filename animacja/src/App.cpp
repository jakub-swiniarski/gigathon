#include <csignal>

#include "App.hpp"
#include "Animation.hpp"
#include "Renderer.hpp"
#include "UserInterface.hpp"

void ani::App::quit(int signum) {
    ani::Renderer::cmd_clear();
    exit(signum);
}

void ani::App::run(void) {
    UserInterface user_interface;
    Animation     animation(user_interface.input_filepath());
    
    while (true)
        animation.play();
}

ani::App::App(void) {
    std::signal(SIGINT, quit);

    run();
}
