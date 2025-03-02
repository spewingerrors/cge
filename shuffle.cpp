#include <iostream>
#include <random>
#include "shuffle.hpp"


int randomNumber(int low, int high) {
    if (low > high) {
        return -1;
    }
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> range(low, high);
    return range(gen);
}

std::vector<std::shared_ptr<Card>> Riffle(std::vector<std::shared_ptr<Card>> input) {
    // RIFFLE SHUFFLE:
    // 0 == 22 for standard deck of cards
    // 8 == 30 for standard deck of cards
    int cutpos;
    if (cutpos = randomNumber(0, 8) + ((input.size()/2) - randomNumber(2, 5)); (cutpos < 0)) {
    }

    std::vector<std::shared_ptr<Card>> temp1;
    std::vector<std::shared_ptr<Card>> temp2;
    // split the deck into 2 halves at the 'cutpos'.
    for (int i = 0; i < cutpos; i++) {
        auto pos1 = temp1.begin();
        temp1.insert(pos1, input.back());
        input.pop_back();
    }
    // We copy the remainder of the deck to temp2
    // and clear this->deck.
    temp2 = input;
    input.clear();

    //
    bool merging = 1;
    std::cout << "Entering merge loop.\n";
    while (merging) {
        int randNum = randomNumber(0, 1);
        // FUNCTIONAL ALERT!
        // For whatever reason, the RNG sometimes spits out 
        // long strings of '1' or '0'. Maybe go back and program
        // some consistency.
        std::cout << randNum << "; ";
        if (randNum == 1 && temp1.size() > 0) {
            auto pos = input.begin();
            input.insert(pos, temp1.back());
            temp1.pop_back();
            std::cout << "Added " << input.at(0)->card_name << " to the deck.\n";
        }
        else if (randNum == 0 && temp2.size() > 0) {
            auto pos = input.begin();
            input.insert(pos, temp2.back());
            temp2.pop_back();
            std::cout << "Added " << input.at(0)->card_name << "temp2 to deck." << "\n";
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

    return input;
}