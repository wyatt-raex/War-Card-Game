#pragma once

#include <iostream>
#include <string>

class Card {
  public:
    enum Value {
      TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE 
    }; 
    enum Suit { CLUB, DIAMOND, HEART, SPADE };
       
  protected:
    uint16_t suit;
    uint16_t value;
  
  public:  
    Card(Suit suit, Value value);
    ~Card();
    bool is_equal(Card* card);
    bool is_equal_suit(Card* card);
    int compare_value(Card* card); 
    std::string print();  

 };