#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "card.hpp"
#include "deck.hpp"

void helper(int input) {
	std::cout << input << "\n";
}

int main(int argc, char **argv) {
	Deck pile(4, 0, 13);
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	helper(pile.Shuffle());
	return 0;
}
