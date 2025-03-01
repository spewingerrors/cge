#include <iostream>
#include <memory>
#include "player.hpp"

Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
}

void Player::AddCardToHand(std::shared_ptr<Card> card) {
    this->hand.emplace_back(card);
}

void Player::PrintHand() {
    std::cout << "Cards in hand of " << this->name << ": ";
    for (long unsigned int i = 0; i < this->hand.size(); i++) {
        std::cout << this->hand.at(i)->card_name << ", ";
    }
    std::cout << "\b\b." << "\n";
}
