#include <iostream>
#include <unordered_map>
#include "card.hpp"

std::string suits[] = {"Clubs", "Hearts", "Spades", "Diamonds"};
std::string cardvals[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

Card::Card(int suit, int value) {
	this->card_suit = suits[suit];
	this->card_value = cardvals[value];
	this->card_name = this->card_value + " of " + this->card_suit;
	//std::cout << "Created card " << this->card_name << "\n";
}
