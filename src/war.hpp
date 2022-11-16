#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unistd.h>

#include "deck.hpp"

/*
Rules of War:

THE DEAL

The deck is divided evenly, with each player receiving 26 cards, dealt one at a time, face down. Anyone
may deal first. Each player places their stack of cards face down, in front of them.

THE PLAY

Each player turns up a card at the same time and the player with the higher card takes both cards and
puts them, face down, on the bottom of his stack.

If the cards are the same rank, it is War. Each player turns up one card face down and one card face up.
The player with the higher cards takes both piles (six cards). If the turned-up cards are again the same
rank, each player places another card face down and turns another card face up. The player with the 
higher card takes all 10 cards, and so on.

After each round, the program should ask the user if they want to continue or forfeit. If they forfeit
the program should print the number of cards eacher player has and quit.

HOW TO KEEP SCORE

The game ends when one player has won all the cards.
*/

#define DEFAULT_WAIT_TIME 3

#define NO_WHITESPACE 0
#define SMALL_WHITESPACE 1
#define MID_WHITESPACE 2
#define LARGE_WHITESPACE 3

#define SLEEP_TIME 1

class War {
    public:
    
    private:
        Deck deck;
        std::queue<Card*> cards_at_play;
        std::queue<Card*> player01_hand;
        std::queue<Card*> player02_hand;    

    // Methods
    public:
        War();
        ~War();
        void play();
    
    private:
        bool check_win();
        void deal_hands();
        void game_loop();
        void give_cards(int *winner);
        void print_dot_anim(std::string msg, int wait_time_in_seconds, int vert_whitespace);
};