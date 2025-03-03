#include <iostream>
#include <random>
#include "shuffle.hpp"
#include "deck.hpp"


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

std::vector<std::shared_ptr<Card>> Hindu(std::vector<std::shared_ptr<Card>> input) {
    std::vector<std::shared_ptr<Card>> original = input;
    std::vector<std::shared_ptr<Card>> tempStack;
    input.clear();
    std::cout << "Okay, we reached the inside of the function. About to 'while'.\n";
    std::cout << "original:\n";
    Print(original);
    //Print(temp2);
    std::cout << "input:\n";
    Print(input);

    
    while (!original.empty()) {
        tempStack.clear();
        // take a chunk from the top
        int rn = randomNumber(3, 7);
        std::cout << "---------------------------------------------------------------------" << "\n";
        std::cout << "Reached RNG. Your number is " << rn << ".\n";
        for (int i = 0; i < rn; i++ ) {
            //std::cout << "Not yet! 00\n";
            if (original.size() == 0) {
                std::cout << "\nNo more cards =(\n";
                break;
            }
            // move chunk to a temp 'deck'
            // temp2.push_back(temp1.at(0));
            //std::cout << "Not yet! " + original.front()->card_name + "\n";
            tempStack.insert(tempStack.end(), original.front());
            //std::cout << "Not yet! 1\n";
            original.erase(original.begin());
            //std::cout << "Not yet! 2\n";
        }

        //std::cout << "Reached end of 1st inner loop.\n";
        //std::cout << "original:\n";
        //Print(original);
        //std::cout << "tempStack:\n";
        //Print(tempStack);
        //std::cout << "input:\n";
        //Print(input);

        /*
        std::vector<std::shared_ptr<Card>> reverseTempStack;
        //int tempsize = tempStack.size();
        for (int i = 0; i < rn; i++) {
            reverseTempStack.insert(reverseTempStack.begin(), tempStack.front());
            tempStack.erase(tempStack.begin());
        }
        std::cout << "tempStack:\n";
        Print(tempStack);
        std::cout << "reverseTempStack:\n";
        Print(reverseTempStack);
        tempStack.clear();
        tempStack = reverseTempStack;
*/
        int loopcount = input.size();
        for (int i = 0; i < loopcount; i++) {
            if (input.size() == 0) {
                break;
            }
            tempStack.insert(tempStack.end(), input.front());
            input.erase(input.begin());
            //std::cout << "Reached end of 2nd inner loop.\n";
            //std::cout << "original:\n";
            //Print(original);
            //std::cout << "tempstack:\n";
            //Print(tempStack);
            //std::cout << "input:\n";
            //Print(input);
        }

        input = tempStack;
        
        std::cout << "Reached end of outer loop.\n";
        std::cout << "original:\n";
        Print(original);
        std::cout << "tempStack:\n";
        Print(tempStack);
        std::cout << "input:\n";
        Print(input);
    }
    //input = temp1;
    return input;
}