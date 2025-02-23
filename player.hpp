#include <iostream>
#include <memory>
#include <vector>
#include "card.hpp"

struct Player {
    // a player can have...

    // a name
    std::string name;

    // a hand
    //std::vector<Card> hand;
    std::vector<std::shared_ptr<Card>> hand;
    // a score
    int score;

    Player(std::string name);
    void AddCardToHand(std::shared_ptr<Card> card);
    void PrintHand();
};
