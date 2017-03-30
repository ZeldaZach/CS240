#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <climits>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Heap.h"
#include "Table.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Heap.h"
#include "Table.h"
using namespace std;

bool verifyHeap(Heap heap){
	int value = 1000;
	while(heap.size() > INT_MAX){
		Player p = heap.getPlayer();
		int next_value = p.getBudget();
		if(next_value > value)
			return false;
		else
			value = next_value;
	}
	return true;
}

// Returns true if arr[i..n-1] represents a max-heap
bool isHeap(vector<Player> arr, int i){
	if(arr.size() <= 1 || i >= (arr.size() - 2)/2)
       return true;
   if (arr.at(i).getBudget() >= arr.at((2*i) + 1).getBudget()  &&
   		arr.at(i).getBudget() >= arr.at((2*i) + 2).getBudget() &&
       	isHeap(arr, 2*i + 1) && isHeap(arr, 2*i + 2))
       return true;

   return false;
}

int main(){
	std::srand ( unsigned ( std::time(0) ) );

	cerr << "\n\tTEST #0: Missing file handled" << endl;
	Heap test1("empty.txt");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #1: Create Players and store them in a heap" << endl;
	Heap tourney("players.txt");
	assert(isHeap(tourney.getArray(), 0));
	assert(tourney.size() == 17);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Players stored in correct order when removed from the heap" << endl;

	Player 	p = tourney.getPlayer();
	assert(p.getBudget()==200);
	p = tourney.getPlayer();
	assert(p.getBudget()==150);
	p = tourney.getPlayer();
	assert(p.getBudget()==150);
	p = tourney.getPlayer();
	assert(p.getBudget()==150);
	p = tourney.getPlayer();
	assert(p.getBudget()==100);
	p = tourney.getPlayer();
	assert(p.getBudget()==80);
	p = tourney.getPlayer();
	assert(p.getBudget()==70);
	p = tourney.getPlayer();
	assert(p.getBudget()==60);
	p = tourney.getPlayer();
	assert(p.getBudget()==55);
	p = tourney.getPlayer();
	assert(p.getBudget()==50);
	p = tourney.getPlayer();
	assert(p.getBudget()==45);
	p = tourney.getPlayer();
	assert(p.getBudget()==38);
	p = tourney.getPlayer();
	assert(p.getBudget()==33);
	p = tourney.getPlayer();
	assert(p.getBudget()==30);
	p = tourney.getPlayer();
	assert(p.getBudget()==20);
	p = tourney.getPlayer();
	assert(p.getBudget()==15);
	p = tourney.getPlayer();
	assert(p.getBudget()==10);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Heap is empty" << endl;
	assert(tourney.empty());
	cerr << "\n\t========================PASS========================\n" << endl;


	cerr << "\n\tTEST #4: Can add individual players to the heap" << endl;
	Heap heap_test("players.txt");
	while(!heap_test.empty()){
		tourney.addPlayer(heap_test.getPlayer());
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
	}

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Play 1 round of highcard" << endl;
	int ante = 5;
	Table highcardTable(5, ante);
	while(highcardTable.emptySeat()){
		highcardTable.addPlayer(tourney.getPlayer());
	}
	assert(verifyHeap(tourney));
	assert(isHeap(tourney.getArray(), 0));
	vector<Player> losers = highcardTable.playRound();
	for(auto p: losers)
		tourney.addPlayer(p);
	assert(verifyHeap(tourney));
	assert(isHeap(tourney.getArray(), 0));
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Play highcard tournament" << endl;
	while(!tourney.empty()){
		while(!tourney.empty() && highcardTable.emptySeat()){
			highcardTable.addPlayer(tourney.getPlayer());
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
		vector<Player> loser = highcardTable.playRound();
		for(auto p: loser){
			if(p.getBudget() > ante){
				tourney.addPlayer(p);
			}
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
	}

	highcardTable.printWinner();

	cerr << "\n\t========================PASS========================\n" << endl;

	Heap tourney2("players2.txt");
	Table highcardTable2(5, ante);
	cerr << "\n\tTEST #7: Play highcard tournament with equal starting budgets" << endl;
	while(!tourney2.empty()){
		while(!tourney2.empty() && highcardTable2.emptySeat()){
			highcardTable2.addPlayer(tourney2.getPlayer());
		}
		assert(verifyHeap(tourney2));
		assert(isHeap(tourney2.getArray(), 0));
		vector<Player> loser = highcardTable2.playRound();
		for(auto p: loser){
			if(p.getBudget() > ante){
				tourney2.addPlayer(p);
			}
		}
		assert(verifyHeap(tourney2));
		assert(isHeap(tourney2.getArray(), 0));
	}
	highcardTable2.printWinner();
	cerr << "\n\t========================PASS========================\n" << endl;

	Heap tourney3;
	int num = 1;
	for(int i = 0; i < 25; i++){
		string name = "Player" + to_string(num++);
		int budget = rand() % 100 + 1;
		tourney3.addPlayer(Player(name, budget));
		assert(verifyHeap(tourney3));
		assert(isHeap(tourney3.getArray(), 0));
	}
	Table highcardTable3(5, ante);
	cerr << "\n\tTEST #8: Play highcard tournament with random starting budgets" << endl;
	while(!tourney3.empty()){
		while(!tourney3.empty() && highcardTable3.emptySeat()){
			highcardTable3.addPlayer(tourney3.getPlayer());
		}
		assert(verifyHeap(tourney3));
		assert(isHeap(tourney3.getArray(), 0));
		vector<Player> loser = highcardTable3.playRound();
		for(auto p: loser){
			if(p.getBudget() > ante){
				tourney3.addPlayer(p);
			}
		}
		assert(verifyHeap(tourney3));
		assert(isHeap(tourney3.getArray(), 0));
	}
	highcardTable3.printWinner();
	cerr << "\n\t========================PASS========================\n" << endl;

	//####################Your Tests#####################//
	//cerr << "\n\tTEST #9: Two tests of your own" << endl;

	return 0;
}
