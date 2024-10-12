#include "Player.hpp"

mg::Player::Player(void)
    : score(0) {}

mg::UI mg::Player::get_score(void) const {
    return score;
}

void mg::Player::update_score(void) {
    score++;
}
