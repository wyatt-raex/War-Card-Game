#include "main.hpp"

int main(int argc, char** argv) {  
  War war;
  war.play();
  /*Deck deck;
  std::cout << "Pre-shuffle" << std::endl;
  deck.draw();
  
  std::cout << std::endl << "Post-shuffle 1" << std::endl;
  deck.shuffle();
  deck.draw();

  std::cout << std::endl << "Post-shuffle 2" << std::endl;
  deck.shuffle();
  deck.draw();*/
    
  return 0;
}

void compare_card(Card* base, Card* compare) {
  std::cout << "Is the " << base->print() << " the same as " << compare->print() << "? ";  
  if (compare->is_equal(base)) { std::cout << "True" << std::endl; }
  else { std::cout << "False" << std::endl; }
 
  std::cout << "Are the suits equal? ";
  if (compare->is_equal_suit(base)) { std::cout << "True" << std::endl; }
  else { std::cout << "False" << std::endl; }
  
  //compare_value() returns 1 for greater than, 0 for same, -1 for less than
  std::cout << "How do the values compare? ";

  std::cout << base->print();
  if (base->compare_value(compare) == 0) { std::cout << " has the same value as "; }
  else if (base->compare_value(compare) == 1) { std::cout << " value is greater value than "; }
  else { std::cout << " value is less than "; }  
  std::cout << compare->print() << std::endl;
}