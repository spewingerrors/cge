#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include "deck.hpp"
#include "logger.hpp"
#include "shuffle.hpp"

// Constructor for a deck of cards
Deck::Deck(int suits, int jokers, int cards_per_suit) {
    std::cout << "You created a new deck with " << suits << " suits and " << jokers << " jokers!" << "\n";
    this->suits = suits;
    this->jokers = jokers;

    // Using a loop to assign the cards to a vector based on function input.
    for (int j = 0; j < suits; j++) {
        for (int i = 0; i < cards_per_suit; i++) {
            this->deck.emplace_back(std::shared_ptr<Card>(new Card(i, j)));
        }
    }
    this->logger.Branch("deck.log");
}

// This may be better suited for some config file that defines any specific game.
// e.g. maybe it's an ini file where the [DECK] header would have these options.
Deck::Deck(std::string name) {
    // This will refer to some typical decks of cards.
    // 'standard', 'pinochle', 'euchre' come to mind.
}

void Deck::Shuffle() {
    //this->deck = Riffle(this->deck);
    this->deck = Overhand(this->deck);
    this->logger.Write("Alright, we shuffled!");
    Print(this->deck);
}

std::shared_ptr<Card> Deck::DealFromTop() {
    // erase and return the top card.
    auto retval = this->deck.at(0);
    this->deck.erase(this->deck.begin());
    return retval;
}

// for debug purposes
void Print(std::vector<std::shared_ptr<Card>> input) {
    // This loop generates a warning for comparing an int to 
    // a length of vector. Casts and checks may need to happen.
    // It works for now!!!!!!!!!
    for (std::vector<Card>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i)->card_name << "\n";
    }
    std::cout << "\n";
    //this->logger.Write("Printed the deck successfully!");
    //Logger::
}
