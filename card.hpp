#ifndef CARD_H
#define CARD_H


class Card
{
public:
	std::string card_suit;
	std::string card_value;
	std::string card_name;

	Card(int suit, int value);
	Card(std::string name);
};

#endif
