#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "card.hpp"
#include "deck.hpp"

int main(int argc, char **argv)
{
	Deck pile(4, 0, 13);
	std::cout << "The number of suits in this deck is " << pile.suits << "\n";
	return 0;
}
