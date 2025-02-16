#include <iostream>
#include <string>
#include <unordered_map>
#include "card.hpp"

std::string suits[] = {"C", "H", "S", "D"};
std::string cardvals[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

Card::Card(std::string name) {
	this->card_name = name;
	std::cout << "You created " << name << ", an object." << "\n";
}

Card::Card(int value, int suit) {
	this->card_suit = suits[suit];
	this->card_value = cardvals[value];
	this->card_name = this->card_value + " of " + this->card_suit;
	std::cout << "Created card " << this->card_name << "\n";
}
