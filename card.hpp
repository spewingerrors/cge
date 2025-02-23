#ifndef CARD_H
#define CARD_H


struct Card {
	std::string card_suit;
	std::string card_value;
	std::string card_name;
	int id;

	Card(int suit, int value);
};

#endif
