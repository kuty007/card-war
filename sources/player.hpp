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
        //getters and setters
        void setName(string name);
        string getName();
        int getNumOfWins();
        void setNumOfWins(int num);
        void setCardsWon(int num);
        int getCardsWon();
        void setCardsLeft(int num);
        int getCardsLeft();
        void setIsPlaying(bool isPlaying);
        bool getIsPlaying();
        void setCards(std::vector<Card> cards);






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
