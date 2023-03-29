//
// Created by asaf7 on 3/21/2023.
//

#include "player.hpp"

namespace ariel {

    Player::Player() {
    }

    Player::Player(string name) {
        _name = name;
        this->isPlaying = false;
        this->cardsLeft = 0;
        this->cardsWon = 0;
        this->numOfWins = 0;
        this->_cards = std::vector<Card>();
    }

    int Player::stacksize() {
        return 0;
    }

    int Player::cardesTaken() {
        return 0;
    }
    int Player::getNumOfWins() {
        return 0;
    }
    int Player::getCardsWon() {
        return 0;

    }
    int Player::getCardsLeft() {
        return 0;
    }
    bool Player::getIsPlaying() {
        return false;

    }
    string Player::getName() {
        return "";

    }
    void Player::setNumOfWins(int num) {

    }
    void Player::setCardsWon(int num) {

    }
    void Player::setCardsLeft(int num) {

    }
    void Player::setIsPlaying(bool isPlaying) {

    }
    void Player::setCards(std::vector<Card> cards) {

    }
    void Player::setName(string name) {

    }
    std::vector<Card> Player::getCards() {
        return std::vector<Card>();

    }
    void Player::addCard(Card card) {

    }
    void Player::removeCard() {

    }
    Card Player::getTopCard() {
        if (_cards.size() == 0) {
            throw "no cards left";
        }
        Card card = _cards.back();
        _cards.pop_back();
        return card;
    }



}
// ariel