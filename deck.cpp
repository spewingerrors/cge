#include <iostream>
#include <random>
#include <vector>
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
    for (std::vector<Card>::size_type i = 0; i < this->deck.size(); i++) {
        std::cout << this->deck.at(i).card_name << "\n";
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
   // 0 == 22 for standard deck of cards
   // 8 == 30 for standard deck of cards
   int cutpos = randomNumber(0, 8) + ((this->deck.size()/2) - this->suits);

   std::vector<Card> temp1;
   std::vector<Card> temp2;
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

   std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
   // printing the vector that is temp1
   std::cout << "TEMP 1: ";
   for (std::vector<Card>::size_type i = 0; i < temp1.size(); i++) {
        std::cout << temp1.at(i).card_name << ", ";
   }
   std::cout << "\n\nTEMP 2: ";
   // also printing temp2
   for (std::vector<Card>::size_type i = 0; i < temp2.size(); i++) {
        std::cout << temp2.at(i).card_name << ", ";
   }
   std::cout << "\n";

   std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << "\n";
   std::cout << "this->deck size: " << this->deck.size();

  /* bool merging = 1;
   while (merging) {
        int randNum = randomNumber(0, 1);
        if (randNum || temp1.size() > 0) {
            auto pos = this->deck.begin();
            this->deck.insert(pos, temp1.back());
            temp1.pop_back();
        }
        else if (temp2.size() > 0) {
            auto pos = this->deck.begin();
            this->deck.insert(pos, temp2.back());
            temp2.pop_back();
        }
        else if (temp1.size() == 0 && temp2.size() == 0) {
            merging = 0;
        }
   }
*/
   std::cout << "\n" << cutpos << std::endl;
   this->Print();
}