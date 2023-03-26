//
// Created by asaf7 on 3/23/2023.
//

#include "game.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
namespace ariel {
    Game::Game() {}

    Game::Game(Player player1, Player player2) {
        _player1 = player1;
        _player2 = player2;
        createCards();
    }

    void ariel::Game::play() {
    }

    void ariel::Game::printLastTurn() {
        // print the last turn
    }

    void ariel::Game::printWiner() {
    }

    void ariel::Game::printLog() {

    }

    void ariel::Game::playTurn() {

    }

    void ariel::Game::playAll() {
        while (_player1.stacksize() > 0 && _player2.stacksize() > 0) {
            playTurn();
        }
    }

    void ariel::Game::printStats() {
        cout << "Turns: " << _turns << endl;
        cout << "Drews: " << drews << endl;
        cout << "Player 1 Wins: " << _player1Wins << endl;
        cout << "Player 2 Wins: " << _player2Wins << endl;
        cout << "Player 1 Cards Won: " << _player1CardsWon << endl;
        cout << "Player 2 Cards Won: " << _player2CardsWon << endl;

    }

    void ariel::Game::createCards() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                Card card = Card(i, j);
                _cards.push_back(card);
            }
        }
        unsigned seed = std::chrono::system_clock::now()
                .time_since_epoch()
                .count();
        shuffle (_cards.begin(), _cards.end(), std::default_random_engine(seed));
        for (int i = 0; i < 26; i++) {
            Card card = _cards.back();
            _player1.addCard(card);
            _cards.pop_back();
            card = _cards.back();
            _player2.addCard(card);
            _cards.pop_back();

        }
    }
    int ariel::Game::getTurns() {
        return _turns;
    }
    int ariel::Game::getDrews() {
        return drews;
    }
    int ariel::Game::getPlayer1Wins() {
        return _player1Wins;
    }
    int ariel::Game::getPlayer2Wins() {
        return _player2Wins;
    }
    int ariel::Game::getPlayer1CardsWon() {
        return _player1CardsWon;
    }
    int ariel::Game::getPlayer2CardsWon() {
        return _player2CardsWon;
    }


}


// ariel