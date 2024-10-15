#ifndef GAME_HPP
#define GAME_HPP

#include "UserInterface.hpp"

namespace mg {
    class Game {
        mg::UserInterface user_interface;
        bool is_running = false;

        void run(void);

    public:
        Game(void);
        
        void cmd_clear(void);
        void quit(void);
        // TODO: saving and loading game
    };
}

#endif // GAME_HPP
