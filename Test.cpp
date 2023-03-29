//
// Created by asaf7 on 3/25/2023.
//
#include <sstream>
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
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p1.stacksize());
    ariel::Card c1(TWO, SPADES);
    p1.addCard(c1);
    CHECK(p1.stacksize() == 1);
    CHECK(p1.getTopCard().compare(c1) == 0);
    CHECK(p1.stacksize() == 0);
}

TEST_CASE("create player") {
    CHECK_NOTHROW(ariel::Player p1("asaf"));
    CHECK_NOTHROW(ariel::Player p2("Alice"));
    CHECK_NOTHROW(ariel::Player p3("Bob"));
    CHECK_NOTHROW(ariel::Player p4("asaf"));//should not throw an error when same name is used twice

}
//test for game
TEST_CASE("game") {
    ariel::Player p1("asaf");
    ariel::Player p2("Alice");
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Player p5("asaf");
    ariel::Player p6("Alice");
    ariel::Game g1(p1, p2);
    CHECK_THROWS(ariel::Game(p1, p3));// should throw an error when same player object is used twice after game started
    CHECK_THROWS(ariel::Game(p3, p3));// should throw an error when same player object is used twice
    CHECK_NOTHROW(
            ariel::Game(p2, p6));//should not throw an error when same name is used twice in different player objects
//    CHECK(p1.getIsPlaying() == true);
//    CHECK(p2.getIsPlaying() == true);
    ariel::Card c1(TWO, SPADES);
    ariel::Card c2(ACE, HEARTS);
    ariel::Card c3(KING, HEARTS);
    ariel::Card c4(ACE, SPADES);
    ariel::Card c5(TWO, HEARTS);
    ariel::Card c6(TWO, SPADES);
    ariel::Card c7(JACK, HEARTS);
    ariel::Card c8(NINE, SPADES);
    p1.setCards({c7, c1, c2, c3});
    p2.setCards({c8, c5, c4, c6});
    //check for print last turn
    std::stringstream output;
    std::streambuf *prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    g1.playTurn();
    g1.printLastTurn();
    std::cout.rdbuf(prevcoutbuf);
    std::string expected_output = "asaf won the turn with KING of HEARTS and Alice lost with TWO of SPADES\n";
    CHECK(output.str() == expected_output);
    //check for print last turn with draw
    std::stringstream output2;
    std::streambuf *prevcoutbuf2 = std::cout.rdbuf();
    std::cout.rdbuf(output2.rdbuf());
    g1.playTurn();
    g1.printLastTurn();
    std::cout.rdbuf(prevcoutbuf2);
    std::string expected_output2 = "asaf played ACE of HEARTS and Alice played ACE of SPADES Draw! asaf won the draw with JACK of HEARTS and Alice lost with NINE of SPADES\n";
    CHECK(output2.str() == expected_output2);
    CHECK_NOTHROW(g1.playAll());
    CHECK_THROWS(g1.playTurn());//should throw an error when game is over

    CHECK_NOTHROW(g1.printLastTurn());//should not throw an error when turns were already played
    CHECK_NOTHROW(g1.printWiner());//should not throw an error when turns were game is over and winner is declared
    CHECK_NOTHROW(g1.printLog());
    CHECK(p1.stacksize() == 0);//should be empty after game is over
    CHECK(p2.stacksize() == 0);//should be empty after game is over
}

TEST_CASE("game Print winner and cards taken") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g2(p3, p4);
    CHECK_NOTHROW(g2.playAll());
    int p3cards = p3.cardesTaken();
    int p4cards = p4.cardesTaken();
    CHECK(p3cards + p4cards == 52);//check if all cards are taken
    std::stringstream output3;
    std::streambuf *prevcoutbuf3 = std::cout.rdbuf();
    std::cout.rdbuf(output3.rdbuf());
    g2.printWiner();
    std::cout.rdbuf(prevcoutbuf3);
    if (p3cards > p4cards) {
        CHECK(output3.str() == "Bob won the game!\n");
    } else if (p3cards < p4cards) {
        CHECK(output3.str() == "p4 won the game!\n");
    } else {
        CHECK(output3.str() == "Draw!\n");
    }
}

TEST_CASE("empty log test ") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g2(p3, p4);
    std::stringstream output3;
    std::streambuf *prevcoutbuf3 = std::cout.rdbuf();
    std::cout.rdbuf(output3.rdbuf());
    g2.printLog();
    std::cout.rdbuf(prevcoutbuf3);
    CHECK(output3.str() == "No turns played yet\n");
}

TEST_CASE("log test of 3 turns ") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g2(p3, p4);
    ariel::Card c1(TWO, SPADES);
    ariel::Card c2(ACE, HEARTS);
    ariel::Card c3(KING, HEARTS);
    ariel::Card c4(ACE, SPADES);
    ariel::Card c5(JACK, HEARTS);
    ariel::Card c6(NINE, SPADES);
    p3.setCards({c1, c2, c3});
    p4.setCards({c4, c5, c6});
    std::stringstream output3;
    std::streambuf *prevcoutbuf3 = std::cout.rdbuf();
    std::cout.rdbuf(output3.rdbuf());
    g2.playAll();
    g2.printLog();
    std::cout.rdbuf(prevcoutbuf3);
    CHECK(output3.str() == "Bob won the turn with KING of HEARTS and p4 lost with NINE of SPADES\n"
                           "p4 won the turn with JACK of HEARTS and Bob lost with ACE of HEARTS\n"
                           "Bob won the turn with TWO of SPADES and p4 lost with ACE of SPADES\n");
}

TEST_CASE("print last turn") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g5(p3, p4);
    std::stringstream output3;
    std::streambuf *prevcoutbuf3 = std::cout.rdbuf();
    std::cout.rdbuf(output3.rdbuf());
    g5.printLastTurn();
    std::cout.rdbuf(prevcoutbuf3);
    CHECK(output3.str() == "No turns played yet\n");
    ariel::Card c1(TWO, SPADES);
    ariel::Card c2(ACE, HEARTS);
    p3.addCard(c1);
    p4.addCard(c2);
    std::stringstream output4;
    std::streambuf *prevcoutbuf4 = std::cout.rdbuf();
    std::cout.rdbuf(output4.rdbuf());
    g5.playTurn();
    g5.printLastTurn();
    std::cout.rdbuf(prevcoutbuf4);
    CHECK(output4.str() == "Bob won the turn with TWO of SPADES and p4 lost with ACE of HEARTS\n");
}

TEST_CASE("print stats") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g5(p3, p4);
    std::stringstream output3;
    std::streambuf *prevcoutbuf3 = std::cout.rdbuf();
    std::cout.rdbuf(output3.rdbuf());
    g5.printStats();
    std::cout.rdbuf(prevcoutbuf3);
    CHECK(output3.str() == "Total turns: 0\n"
                           "draws: 0 turns from 0 turns\n"
                           "Percent of draws:0%\n"
                           "Bob Wins: 0 turns from 0 turns\n"
                           "Bob Percent of wins:0%\n"
                           "p4 Wins: 0 turns from 0 turns\n"
                           "p4 Percent of wins:0%\n"
                           "Bob total cards Won: 0\n"
                           "p4 total cards Won: 0\n"
    );
    ariel::Card c1(TWO, SPADES);
    ariel::Card c2(ACE, HEARTS);
    p3.addCard(c1);
    p4.addCard(c2);
    std::stringstream output4;
    std::streambuf *prevcoutbuf4 = std::cout.rdbuf();
    std::cout.rdbuf(output4.rdbuf());
    g5.playTurn();
    g5.printStats();
    std::cout.rdbuf(prevcoutbuf4);
    CHECK(output4.str() == "Total turns: 1\n"
                           "Total draws: 0 turns from 1 turns\n"
                           "Percent of draws:0%\n"
                           "Bob Wins: 1 turns from 1 turns\n"
                           "Bob Percent of wins:100%\n"
                           "p4 Wins: 0 turns from 1 turns\n"
                           "p4 Percent of wins:0%\n"
                           "Bob total cards Won: 2\n"
                           "p4 total cards Won: 0\n"
    );
}

TEST_CASE("print game winner before game finished") {
    ariel::Player p3("Bob");
    ariel::Player p4("p4");
    ariel::Game g5(p3, p4);
    CHECK_THROWS(g5.printWiner());//game not finished
}
//
//test for card
//TEST_CASE("card") {
//    ariel::Card c1(TWO, SPADES);
//    ariel::Card c2(TWO, SPADES);
//    CHECK_NOTHROW(ariel::Card c1(TWO, SPADES));
//    CHECK(c1.get_suit() == SPADES);
//    CHECK(c1.get_value() == TWO);
//    CHECK_NOTHROW(c1.set_suit(HEARTS));
//    CHECK_NOTHROW(c1.set_value(ACE));
//    CHECK(c1.get_suit() == HEARTS);
//    CHECK(c1.get_value() == ACE);
//    CHECK(c1.compare(c1) == 0);
//    CHECK(c1.compare(c2) == -1);
//}

