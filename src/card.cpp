#include "card.hpp"

Card::Card(Suit suit, Value value) {  
  this->suit = suit;
  this->value = value;
}

Card::~Card() {}

bool Card::is_equal(Card* card) { return (this->suit == card->suit) && (this->value == card->value); }

bool Card::is_equal_suit(Card* card) { return this->suit == card->suit; }

/*
Returns 0 if values/types are the same
Returns 1 if this card has a higher value/type than the card passed in
Returns -1 if this card has a lower value/type than the card passed in
*/
int Card::compare_value(Card* card) {
  if (this->value == card->value) { return 0; }
  else if (this->value > card->value) { return 1; }
  else { return -1; }
  
  /*
  Could also do return this->type - card->type;
  
  But probably better to only have 3 possible integers to return, rather than a range of them.
  */
}

// Take a look at this:
// https://stackoverflow.com/questions/11623608/passing-enum-to-a-constructor
std::string Card::print() {
  std::string suits[4] = {"Club", "Diamond", "Heart", "Spade"};
  std::string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
  
  // CardTypes Enum starts at 2, so we subtract to not get a segfault during possible edge case
  int idx_values = value - 2;

  // Example output:
  // [Ace of Spades]  
  return ("[" + values[idx_values] + " of " + suits[this->suit] + "s]");
}