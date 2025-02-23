#include <iostream>
#include <unordered_map>
#include <format>
#include "card.hpp"

std::string cardvals[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
std::string suits[] = {"Clubs", "Hearts", "Spades", "Diamonds"};
//std::string cardvals[] = {"0", "1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"11" ,"12"};
//std::string suits[] = {"0", "1", "2", "3"};

Card::Card(int value, int suit) {
	this->card_value = cardvals[value];
	this->card_suit = suits[suit];
	this->id = (suit * 13) + (value + 1);
	this->card_name = this->card_value + " of " + this->card_suit + "(" + std::to_string(this->id) + ")";
}
