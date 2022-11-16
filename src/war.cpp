#include "war.hpp"

/* ========== PUBLIC METHODS ========== */

War::War() {
    // If deck is already declared in the header file, do we really need to do anything in the constructor?
}

War::~War() {
    while (!this->player01_hand.empty()) {
        this->player01_hand.pop();
    }
    while (!this->player02_hand.empty()) {
        this->player02_hand.pop();
    }
    
    /*
    this->deck should be deleted automatically when this(war) object goes out of scope. 
    (It's destructor will be called)
    */
}

void War::play() {
    std::cout << "Welcome to CSC339 War!" << std::endl;
    
    print_dot_anim("Beginning game", DEFAULT_WAIT_TIME, NO_WHITESPACE);
    
    game_loop();
}

/* ========== PRIVATE METHODS =========== */

bool War::check_win() {
    return false;
}

void War::deal_hands() {
    print_dot_anim("Dealing cards", DEFAULT_WAIT_TIME, NO_WHITESPACE);
    std::cout << std::endl;
        
    while(!this->deck.is_empty()) {
        // Draw cards into each player's hands
        this->player01_hand.push(this->deck.draw());
        this->player02_hand.push(this->deck.draw());   
        
        //std::cout << "Player 1 drew: " << this->player01_hand.back()->print() << std::endl;
        //std::cout << "Player 2 drew: " << this->player02_hand.back()->print() << std::endl;
    }
}

void War::game_loop() {
    print_dot_anim("Shuffling", DEFAULT_WAIT_TIME, SMALL_WHITESPACE);    
    this->deck.shuffle();
    deal_hands();    
    
    bool quit = false;
    while (!quit) {
        
        // Display the amount of cards each player has
        sleep(SLEEP_TIME); // Sleep for dramatic effect    
        std::cout << "Player 1 has: " << this->player01_hand.size() << " cards." << std::endl;
        sleep(SLEEP_TIME); 
        std::cout << "Player 2 has: " << this->player02_hand.size() << " cards." << std::endl;
        sleep(SLEEP_TIME);
        std::cout << std::endl;
        
        // Check if someone won
        if (player01_hand.empty()) {
            std::cout << std::endl << "Player 2 has won the game!" << std::endl;
            return;
        }
        else if (player02_hand.empty()) {
            std::cout << std::endl << "Player 1 has won the game!" << std::endl;
            return;
        }
        
        // Play the cards
        this->cards_at_play.push(this->player01_hand.front());
        std::cout << "Player 1 played: " << this->cards_at_play.back()->print() << std::endl;
        sleep(SLEEP_TIME);
        
        this->cards_at_play.push(this->player02_hand.front());
        std::cout << "Player 2 played: " << this->cards_at_play.back()->print() << std::endl;
        sleep(SLEEP_TIME);
        
        // Compare the cards
        int comparison = this->player01_hand.front()->compare_value(this->player02_hand.front());
        
        // Remember to remove the cards from the player's hands afterwords
        this->player01_hand.pop();
        this->player02_hand.pop();
        
        if (comparison == 0) { // Cards are the same! This means WAR!
            bool war = true;
            while (war) {
                std::cout << std::endl << "The cards are the same!!!" << std::endl;
                print_dot_anim("This means War!", DEFAULT_WAIT_TIME, NO_WHITESPACE);
            
            
                // Ensure the player's hands are not empty
                if (player01_hand.empty() || player02_hand.empty()) { continue; }
            
                // Draw face down cards
                cards_at_play.push(this->player01_hand.front());
                cards_at_play.push(this->player02_hand.front());
                this->player01_hand.pop();
                this->player02_hand.pop();
            
                std::cout << "Player 1 draws a card and places it facedown." << std::endl;
                sleep(SLEEP_TIME);
                std::cout << "Player 2 draws a card and places it facedown." << std::endl;
                sleep(SLEEP_TIME);
                std::cout << std::endl;            

                // Once again ensure the player's hands are not empty
                if (player01_hand.empty() || player02_hand.empty()) { continue; }
                
                // Draw cards and determine if it's war again
                this->cards_at_play.push(this->player01_hand.front());
                std::cout << "Player 1 played: " << this->cards_at_play.back()->print() << std::endl;
                sleep(SLEEP_TIME);
        
                this->cards_at_play.push(this->player02_hand.front());
                std::cout << "Player 2 played: " << this->cards_at_play.back()->print() << std::endl;
                sleep(SLEEP_TIME);

                int war_comparison = player01_hand.front()->compare_value(player02_hand.front());
                this->player01_hand.pop();
                this->player02_hand.pop();
                
                // If the cards are not the same, end war
                if (war_comparison != 0) { 
                    war = false;
                    
                    // Give cards to the winner
                    if (war_comparison == 1) { give_cards(&war_comparison); } // Player 1 won
                    else { give_cards(&war_comparison); } // Player 2 won
                }
            }   
        }

        else if (comparison == 1) { give_cards(&comparison); } // Player 1 won
        else { give_cards(&comparison); } // Player 2 won

        // Check if player wants to quit the game
        std::cout << "Would you like to quit the game?" << std::endl;
        
        std::cout << "Enter \"quit\" to quit. Otherwise enter \"no\" to continue. ";
        std::string input;
        std::cin >> input;        
        std::cout << std::endl; // New-line for style/formatting

        if (!input.empty()) {
            // Make the string lowercase
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);
            
            if (input == "quit" || input == "q") {
                quit = true;
                continue;
            }
        }        
    }
    
    
    // Display the amount of cards each player has and tell players the winner
    sleep(SLEEP_TIME); // Sleep for dramatic effect    
    std::cout << "Player 1 has: " << this->player01_hand.size() << " cards." << std::endl;
    sleep(SLEEP_TIME); 
    std::cout << "Player 2 has: " << this->player02_hand.size() << " cards." << std::endl;
    sleep(SLEEP_TIME);
    std::cout << std::endl;
    
    if (player01_hand.size() > player02_hand.size()) {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else {
        std::cout << "Player 2 wins!" << std::endl;
    }
}

void War::give_cards(int *winner) {
    if (*winner == 1) { std::cout << std::endl << "Player 1 "; }
    else { std::cout << std::endl << "Player 2 "; }
    
    std::cout << "won " << this->cards_at_play.size() << " cards!" << std::endl << std::endl;
    
    while (!this->cards_at_play.empty()) {
        if (*winner == 1) { // Player 1 won
            this->player01_hand.push(this->cards_at_play.front());
        }
        else if (*winner == -1) { // Player 2 won
            this->player02_hand.push(this->cards_at_play.front());
        }
        
        this->cards_at_play.pop();
    }
}

void War::print_dot_anim(std::string msg, int wait_time_in_seconds, int vert_whitespace) {
    for (int i = 0; i < vert_whitespace; i++) { std::cout << std::endl; }

    std::cout << msg;
    
    for (int i = 0; i < wait_time_in_seconds; i++) {
        std::cout << ".";
        std::cout.flush();
        sleep(SLEEP_TIME);
    }
    std::cout << std::endl;

    for (int i = 0; i < vert_whitespace; i++) { std::cout << std::endl; }
}