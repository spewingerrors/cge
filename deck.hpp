#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include "logger.hpp"
#include <vector>
#include <memory>
#include <string>

enum ShuffleType {
    RIFFLE,
    OVERHAND,
    WASH
};

struct Deck {
    int suits;
    int jokers;
    int cards_per_suit;
    Logger logger;
    std::vector<std::shared_ptr<Card>> deck;

    Deck(int suits, int jokers, int cards_per_suit);
    Deck(std::string name);
    void Print();
    void Shuffle();
    std::shared_ptr<Card> DealFromTop();
};

#endif
