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
//    Game::Game(): _player1(defaultPlayer), _player2(defaultPlayer) {}

    Game::Game(Player &player1, Player &player2) : _player1(player1), _player2(player2) {

    }


    void ariel::Game::printLastTurn() {

    }

    void ariel::Game::printWiner() {

    }


    void ariel::Game::printLog() {

    }

    void ariel::Game::playTurn() {

    }

    std::string ariel::Game::drewTurn(int totalCards, string log) {
        return "";
    }

    void ariel::Game::playAll() {

    }

    void ariel::Game::printStats() {


    }

    void ariel::Game::createCards() {


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