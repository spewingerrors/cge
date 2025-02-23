#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include "deck.hpp"

// Constructor for a deck of cards
Deck::Deck(int suits, int jokers, int cards_per_suit) {
    std::cout << "You created a new deck with " << suits << " suits and " << jokers << " jokers!" << "\n";
    this->suits = suits;
    this->jokers = jokers;

    // Using a loop to assign the cards to a vector based on function input.
    for (int j = 0; j < suits; j++) {
        for (int i = 0; i < cards_per_suit; i++) {
            //Card newcard(i, j);
            //this->deck.emplace_back(newcard);
            //std::shared_ptr<Card>(new Card(i, j));// = std::make_shared<Card>();
            this->deck.emplace_back(std::shared_ptr<Card>(new Card(i, j)));
        }
    }
}

// This may be better suited for some config file that defines any specific game.
// e.g. maybe it's an ini file where the [DECK] header would have these options.
Deck::Deck(std::string name) {
    // This will refer to some typical decks of cards.
    // 'standard', 'pinochle', 'euchre' come to mind.
}

// for debug purposes
void Deck::Print() {
    // This loop generates a warning for comparing an int to 
    // a length of vector. Casts and checks may need to happen.
    // It works for now!!!!!!!!!
    for (std::vector<Card>::size_type i = 0; i < this->deck.size(); i++) {
        std::cout << this->deck.at(i).get()->card_name << "\n";
    }
}

int randomNumber(int low, int high) {
    if (low > high) {
        return -1;
    }
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> range(low, high);
    return range(gen);
}

void Deck::Shuffle() {
    // begin implementing shuffling routines.
    // multiple can be implemented - overhand, riffle, wash 

    // RIFFLE SHUFFLE:
    // 0 == 22 for standard deck of cards
    // 8 == 30 for standard deck of cards
    int cutpos = randomNumber(0, 8) + ((this->deck.size()/2) - this->suits);

    std::vector<std::shared_ptr<Card>> temp1;
    std::vector<std::shared_ptr<Card>> temp2;
    // split the deck into 2 halves at the 'cutpos'.
    for (int i = 0; i < cutpos; i++) {
        auto pos1 = temp1.begin();
        temp1.insert(pos1, this->deck.back());
        this->deck.pop_back();
    }
    // We copy the remainder of the deck to temp2
    // and clear this->deck.
    temp2 = this->deck;
    this->deck.clear();
    //std::cout << "TEMP 1: ";
    //for (std::vector<Card>::size_type i = 0; i < temp1.size(); i++) {
    //     std::cout << temp1.at(i).card_name << ", ";
    //}
    //
    int merging = 1;
    std::cout << "Entering merge loop.\n";
    while (merging == 1) {
        int randNum = randomNumber(0, 1);
        std::cout << "I got a random number: " << randNum << ";";
        if (randNum == 1 && temp1.size() > 0) {
            auto pos = this->deck.begin();
            this->deck.insert(pos, temp1.back());
            temp1.pop_back();
            std::cout << "Added from temp1 to deck." << "\n";
        }
        else if (temp2.size() > 0) {
            auto pos = this->deck.begin();
            this->deck.insert(pos, temp2.back());
            temp2.pop_back();
            std::cout << "Added from temp2 to deck." << "\n";
        }
        else if (temp1.size() == 0 && temp2.size() == 0) {
            merging = 0;
            std::cout << "Deck empty.\n";
        }
        else if (randNum == 1 && temp1.size() == 0) {
            std::cout << "Wanted to pull from temp1 but it's empty.\n";
        }
        else if (randNum == 0 && temp2.size() == 0) {
            std::cout << "Wanted to pull from temp2 but it's empty.\n";
        }
    }
    this->Print();
}

//void Deck::Clean() {
//    while (this->deck.size() > 0) {
//        std::cout << "Deleting card!" << "\n";
//        delete this->deck.back();
//    }
//}

std::shared_ptr<Card> Deck::DealFromTop() {
    // erase and return the top card.
    auto retval = this->deck.at(0);
    this->deck.erase(this->deck.begin());
    return retval;
}