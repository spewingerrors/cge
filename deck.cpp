#include <iostream>
#include "deck.hpp"

Deck::Deck(int suits, int jokers, int cards_per_suit) {
    std::cout << "You created a new deck with " << suits << " suits and " << jokers << " jokers!" << "\n";
    this->suits = suits;
    this->jokers = jokers;

    // Using a loop to assign the cards to a vector based on function input.
    for (int i = 0; i < suits; i++) {
        for (int j = 0; j < cards_per_suit; j++) {
            Card newcard(i, j);
            this->deck.emplace_back(newcard);
        }
    }
    std::cout << "We exited the loop!" << "\n";
}

Deck::Deck(std::string name) {
    // This will refer to some typical decks of cards.
    // 'standard', 'pinochle', 'euchre' come to mind.
}

void Deck::Print() {
    // This loop generates a warning for comparing an int to 
    // a length of vector. Casts and checks may need to happen.
    // It works for now!!!!!!!!!
    for (int i = 0; i < this->deck.size(); i++) {
        std::cout << this->deck.at(i).card_name << "\n";
    }
}

void Deck::Shuffle() {
   // begin implementing shuffling routines.
   // multiple can be implemented - overhand, riffle, wash 
}