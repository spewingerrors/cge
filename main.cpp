#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

void helper(int input) {
	std::cout << input << "\n";
}

int main(int argc, char **argv) {
	// Initialize all the players
	int total_players = 4;
	// for now, we're hard-coding 4.
	std::vector<Player> players;
	std::string player1 = "Player 1";
	Player newplayer1(player1);
	players.emplace_back(newplayer1);
	Player newplayer2("Player 2");
	players.emplace_back(newplayer2);
	Player newplayer3("Player 3");
	players.emplace_back(newplayer3);
	Player newplayer4("Player 4");
	players.emplace_back(newplayer4);

	for (int i = 0; i < total_players; i++ ) {
		std::cout << players.at(i).name << ", ";
	}
	std::cout << std::endl;


	Deck pile(4, 0, 13);
	pile.Shuffle();
	pile.Shuffle();
	pile.Shuffle();




	return 0;
}
