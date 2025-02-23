#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include <vector>
#include <memory>
#include <string>

struct Deck {
    int suits;
    int jokers;
    int cards_per_suit;
    std::vector<std::shared_ptr<Card>> deck;

    Deck(int suits, int jokers, int cards_per_suit);
    Deck(std::string name);
    void Print();
    void Shuffle();
    std::shared_ptr<Card> DealFromTop();
};

#endif
