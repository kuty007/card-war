//
// Created by asaf7 on 3/23/2023.
//

//
// Created by asaf7 on 3/21/2023.
//
#include "player.hpp"
#ifndef CARDWAR_A_GAME_H
#define CARDWAR_A_GAME_H

namespace ariel {

    class Game {
    public:
        Game();
        Game(Player player1, Player player2);
        void play();
        void printLastTurn();
        void printWiner();
        void printLog();
        void playTurn();
        void playAll();
        void printStats();





    private:
        Player _player1;
        Player _player2;
    };

} // ariel

#endif //CARDWAR_A_GAME_H
