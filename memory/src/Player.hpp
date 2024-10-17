#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace mg {
    class GameStateManager;

    class Player {
        friend GameStateManager;

        int score;

    public:
        Player(void);

        int  get_score(void) const;
        void update_score(void);
    };
}

#endif // PLAYER_HPP
