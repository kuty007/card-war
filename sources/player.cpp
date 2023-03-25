//
// Created by asaf7 on 3/21/2023.
//

#include "player.hpp"

namespace ariel {

    Player::Player() {
    }

    Player::Player(string name) {
        _name = name;
        isPlaying = false;
        cardsLeft = 0;
        cardsWon = 0;
        numOfWins = 0;

    }

    int Player::stacksize() {
        return _cards.size();
    }

    int Player::cardesTaken() {
        return cardsWon;
    }
    int Player::getNumOfWins() {
        return numOfWins;
    }
    int Player::getCardsWon() {
        return cardsWon;
    }
    int Player::getCardsLeft() {
        return cardsLeft;
    }
    bool Player::getIsPlaying() {
        return isPlaying;
    }
    string Player::getName() {
        return _name;
    }
    void Player::setNumOfWins(int num) {
        numOfWins = num;
    }
    void Player::setCardsWon(int num) {
        cardsWon = num;
    }
    void Player::setCardsLeft(int num) {
        cardsLeft = num;
    }
    void Player::setIsPlaying(bool isPlaying) {
        this->isPlaying = isPlaying;
    }
    void Player::setCards(std::vector<Card> cards) {
        _cards = cards;
    }
    void Player::setName(string name) {
        _name = name;
    }



}
// ariel