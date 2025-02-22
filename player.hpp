#include <iostream>
#include <vector>
#include "card.hpp"

struct Player {
    // a player can have...

    // a name
    std::string name;

    // a hand
    std::vector<Card> hand;

    // a score
    int score;

    Player(std::string name);
};