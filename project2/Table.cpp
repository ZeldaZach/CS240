#include "Table.h"
#include "Deck.h"

Table::Table(int seats, int ante) : tableSize(seats), ante(ante), pot(0)
{
}

bool Table::emptySeat()
{
	return (players.size() < tableSize);
}

std::vector<Player> Table::playRound()
{
	// Shuffle a deck of cards
	Deck d;
	d.shuffle();
	
	// Have each player ante up and then give them a card
	for (auto p = players.begin(); p != players.end(); p++)
	{
		// If they do not have enough money, they don't get a card
		if ((*p).bet(ante))
		{
			pot += ante;
			(*p).hand = d.draw();
		}
	}
	
	// Determine who the winner is
	std::vector<Player> losers;
	Player winner = *(players.begin());
	for (auto p = players.begin() + 1; p != players.end(); p++)
	{
		if ((*p).hand > winner.hand)
		{
			losers.push_back(winner);
			winner = *p;
		}
	}
	
	// Give winner his/her winnings
	winner.collectWinnings(pot);
	
	// Eject all the losers from the Table
	players.clear();
	players.push_back(winner);
	
	// Proclaim who our winner is to the world
	printWinner();

	// Return a list of the losers
	return losers;
}

std::vector<Player> Table::getPlayers()
{
	return players;
}

void Table::addPlayer(Player p)
{
	players.push_back(p);
}

Player Table::getWinner()
{
	if (players.size() > 0)
		return players.at(0);

	return Player();
}
void Table::printWinner()
{
	if (players.size() > 1)
		std::cout << "The Winner was " << players.at(0).getName() << std::endl;
}