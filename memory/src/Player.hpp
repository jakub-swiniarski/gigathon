#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "common.hpp"

namespace mg {
    class Player {
        UI score;

    public:
        Player(void);

        UI   get_score(void) const;
        void update_score(void);
    };
}

#endif // PLAYER_HPP
