#ifndef GAME_HPP
#define GAME_HPP

#include "UserInterface.hpp"

namespace mg {
    class Game {
        mg::UserInterface user_interface;
        const std::string filepath_game_state;
        bool              is_running = false;

        void run(void);
        void cmd_clear(void);
        void quit(void);

    public:
        Game(void);
    };
}

#endif // GAME_HPP
