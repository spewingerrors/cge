#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "logger.hpp"

void helper(int input) {
	std::cout << input << "\n";
}

int main(int argc, char **argv) {
	// initialize logger
	Logger logger("debug.log");
	// Initialize all the players
	int total_players = 4;
	logger.WriteToLogger("Total number of players is " + total_players);
	// for now, we're hard-coding 4.
	std::vector<Player> players;
	Player newplayer1("Player 1");
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
	pile.Print();
	pile.Shuffle();
	pile.Shuffle();
	pile.Shuffle();

	std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	std::cout << "Dealing cards.\n";
	int total_cards = 7;

	for (int i = 0; i < total_cards; i++) {
		for (long unsigned int j = 0; j < players.size(); j++) {
			players.at(j).AddCardToHand(pile.DealFromTop());
		}
	}
	std::cout << "---------------------------------------------\n";
	for (long unsigned int j = 0; j < players.size(); j++) {
		players.at(j).PrintHand();
	}
	std::cout << std::endl;

	return 0;
}
