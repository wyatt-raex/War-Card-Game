#pragma once

#include <algorithm> // std::shuffle
#include <chrono>    // std::chrono::system_clock
#include <iostream>  // std::count
#include <random>    // std::default_random_engine
#include <stack>
#include <vector>

#include "card.hpp"

#define NUM_SUITS 4
#define NUM_CARDS 52
#define CARD_ENUM_START 2
#define CARD_ENUM_END 15

class Deck {
    public:
    
    private:
        std::vector<Card*> cards;
        std::stack<Card*> deck;

    // Methods
    public:
        Deck();
        ~Deck();
        bool is_empty();
        void shuffle();
        Card* draw(); // Change to return a Card* to the top of the card drawn deck
        void print();
    
    private:
        void reset_deck();
};