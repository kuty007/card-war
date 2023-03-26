//
// Created by asaf7 on 3/25/2023.
//
#include "doctest.h"
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <iostream>
//test for player
TEST_CASE("player") {
    ariel::Player p1("asaf");
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.getName() == "asaf");
    CHECK(p1.getNumOfWins() == 0);
    CHECK(p1.getCardsWon() == 0);
    CHECK(p1.getCardsLeft() == 0);
    CHECK(p1.getIsPlaying() == false);
    CHECK_NOTHROW(p1.setNumOfWins(1));
    CHECK_NOTHROW(p1.setCardsWon(1));
    CHECK_NOTHROW(p1.setCardsLeft(1));

}

TEST_CASE("create player") {
    CHECK_NOTHROW(ariel::Player p1("asaf"));
    CHECK_NOTHROW(ariel::Player p2("Alice"));
    CHECK_NOTHROW(ariel::Player p3("Bob"));

}
//test for game
TEST_CASE("game") {
    ariel::Player p1("asaf");
    ariel::Player p2("Alice");
    ariel::Player p3("Bob");
    ariel::Game g1(p1, p2);
    CHECK_THROWS(ariel::Game(p3, p3));// should throw an error when same player object is used twice
    CHECK(p1.getIsPlaying() == true);
    CHECK(p2.getIsPlaying() == true);
    CHECK_NOTHROW(g1.play());
    CHECK_THROWS(ariel::Game(p1, p3));// should throw an error when same player object is used twice after game started
//    CHECK((p1.stacksize() == 25) || (p1.stacksize() == 23));
    CHECK_NOTHROW(g1.printLastTurn());
    CHECK_NOTHROW(g1.printWiner());
    CHECK_NOTHROW(g1.printLog());
    CHECK_NOTHROW(g1.playTurn());
    CHECK_NOTHROW(g1.playAll());
    CHECK(p1.stacksize()== 0);
    CHECK(p2.stacksize() == 0);
    CHECK_NOTHROW(g1.printStats());
}
//test for card

TEST_CASE("card") {
    ariel::Card c1(TWO, SPADES);
    ariel::Card c2(TWO, SPADES);
    CHECK_NOTHROW(ariel::Card c1(TWO, SPADES));

    CHECK(c1.get_suit() == SPADES);
    CHECK(c1.get_value() == TWO);
    CHECK_NOTHROW(c1.set_suit(HEARTS));
    CHECK_NOTHROW(c1.set_value(ACE));
    CHECK(c1.get_suit() == HEARTS);
    CHECK(c1.get_value() == ACE);
    CHECK(c1.compare(c1) == 0);
    CHECK(c1.compare(c2) == -1);


}

