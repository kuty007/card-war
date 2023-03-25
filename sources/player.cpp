//
// Created by asaf7 on 3/21/2023.
//

#include "player.hpp"

namespace ariel {

    Player::Player() {
    }

    Player::Player(string name) {
        _name = name;
    }

    int Player::stacksize() {
        return _cards.size();
    }

    int Player::cardesTaken() {
        return cardsWon;
    }

    void setIsPlaying(bool isPlaying) {
       isPlaying = isPlaying;
    }
}
// ariel