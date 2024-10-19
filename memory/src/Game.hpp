#ifndef GAME_HPP
#define GAME_HPP

#include "UserInterface.hpp"

namespace mg {
    class Game {
        mg::UserInterface user_interface;
        bool              is_running = false;

        void run(void);
        void quit(void);
        void cmd_clear(void) const;

    public:
        Game(void);
    };
}

#endif // GAME_HPP
