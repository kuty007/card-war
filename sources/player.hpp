//
// Created by asaf7 on 3/21/2023.
//
#include <string>
#include "card.hpp"
#include <vector>
using namespace std;
#ifndef CARDWAR_A_PLAYER_H
#define CARDWAR_A_PLAYER_H

namespace ariel {
    class Player {
    public:
        Player();

        Player(string name);

        int stacksize();

        int cardesTaken();

    private:
        string _name;
        bool isPlaying;
        int cardsLeft;
        int cardsWon;
        int numOfWins;
        std::vector <Card> _cards;
    };

}
#endif //CARDWAR_A_PLAYER_H
