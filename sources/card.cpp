//
// Created by asaf7 on 3/21/2023.
//

#include "card.hpp"
#include <string>

namespace ariel {
//implement the card class

    Card::Card() {
    }

    Card::Card(Value value, Suit suit) {
        _suit = suit;
        _value = value;
    }

    void ariel::Card::set_suit(Suit suit) {

    }

    void ariel::Card::set_value(Value value) {
    }


    Suit ariel::Card::get_suit() {
        return _suit;
    }

    Value ariel::Card::get_value() {
        return _value;
    }

    int ariel::Card::compare(Card card) {
        return 0;
    }

    //tosring
    std::string ariel::Card::toString() {
        return "";
    }


}



// ariel