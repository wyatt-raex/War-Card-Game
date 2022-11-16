#include "deck.hpp"

/* ========== PUBLIC METHODS ========== */

Deck::Deck() {
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int value = CARD_ENUM_START; value < CARD_ENUM_END; value++) {
            Card::Suit suit_enum = static_cast<Card::Suit>(suit);
            Card::Value val_enum = static_cast<Card::Value>(value);
            Card *card = new Card(suit_enum, val_enum);

            cards.push_back(card);
            deck.push(card);
        }
    }
}

Deck::~Deck() {
    reset_deck();
    for (Card *card : cards) {
        delete card;
    }
}

bool Deck::is_empty() {
    return this->deck.empty();
}

void Deck::shuffle() {
    reset_deck(); // Ensure empty deck
    
    // Obtain random seed based on time (from c++ documentation: https://cplusplus.com/algorithm/shuffle/)
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    
    for (Card* card : cards) { deck.push(card); }
}

// Change to return a Card* to the card on the top of the drawn card deck
Card* Deck::draw() {
        //std::cout << deck.top()->print() << std::endl;
        Card* ret = deck.top();
        deck.pop();
    
    return ret; 
}

void Deck::print() {
    for (Card* card : cards) {
        std::cout << card->print() << std::endl;
    }
}

/* ========== PRIVATE METHODS ========== */
void Deck::reset_deck() {
    while (!deck.empty()) { deck.pop(); }
}