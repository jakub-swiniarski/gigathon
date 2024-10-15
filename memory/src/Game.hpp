#ifndef GAME_HPP
#define GAME_HPP

#include "UserInterface.hpp"

namespace mg {
    class Game {
        mg::UserInterface user_interface;
        bool is_running                = false;

        static constexpr int n_players = 2;

        void run(void);

    public:
        Game(void);
        
        void cmd_clear(void);
        void quit(void);
    };
}

#endif // GAME_HPP
