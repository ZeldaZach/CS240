#include "AntHill.h"
#include "AntHill.h"
#include "Ant.h"
#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define NUM_ANTS_TO_TEST 500
#define EXTRA_CREDIT true

int main(){
	srand(time(NULL));
	int all_ids[NUM_ANTS_TO_TEST] = {0};

	cerr << "\n\tTEST #1: Test Ant Hill Creation with 0 ants" << endl;
	AntHill * hill = new AntHill();
	assert(hill->getCurrentNumAnts() == 0);
	delete hill;
	hill = NULL;

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Test Add 1 Ant " << endl;

	hill = new AntHill();
	all_ids[0] = hill->addAnt();
	assert(hill->getCurrentNumAnts() == 1);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Add Many Ants" << endl;
	//add 499 more ants
	int last_id = -1;
	for(int i = 1; i < NUM_ANTS_TO_TEST; i++){
		all_ids[i] = hill->addAnt();
		assert(hill->getCurrentNumAnts() == i+1);
		assert(all_ids[i] != last_id);
		last_id = all_ids[i];
	}

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Delete Ants" << endl;
	//delete the first 10 ants in the hill
	for(int i = 0; i < 10; i++){
		assert(hill->getCurrentNumAnts() == (NUM_ANTS_TO_TEST-i));
		assert(hill->removeAnt(all_ids[i]) == true);
		all_ids[i] = -1;
		assert(hill->getCurrentNumAnts() == (NUM_ANTS_TO_TEST-i-1));
	}
	//delete 10 random ants in the hill
	for(int i = 0; i < 10; i++){
		int rand_id = (rand() % (NUM_ANTS_TO_TEST - 10)) + 10;
		int num_ants = hill->getCurrentNumAnts();
		if(hill->removeAnt(all_ids[rand_id]) == true){
			all_ids[rand_id] = -1;
			assert(hill->getCurrentNumAnts() == --num_ants);
		}else{
			assert(hill->getCurrentNumAnts() == num_ants);
		}
	}
	assert(hill->removeAnt(-1) == false);
	cerr << "\n\t========================PASS========================\n" << endl;


	cerr << "\n\tTEST #5: Move Ants Still Works" << endl;

	//After calling move the ants should move randomly by one unit up/down or left/right
	for(int i = 0; i < NUM_ANTS_TO_TEST; i++){
		bool different = false;
		Ant * temp = hill->getAnt(all_ids[i]);
		if(temp == NULL) continue;
		hill->move();
		for(int j = 0; j < NUM_ANTS_TO_TEST; j++){
			Ant * check = hill->getAnt(all_ids[j]);
			if(check == NULL) continue;
			if(check->getX() != temp->getX() || check->getY() != temp->getY()){
				different = true;
				break;
			}
		}
		assert(different);
	}

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Print Hill Information and Free Memory" << endl;

	hill->printHillInfo();
	delete hill;
	hill = NULL;

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;

#if EXTRA_CREDIT
	Ant * ant = new Ant(0);
	for(int i = 20; i > 0; i--)
	{
		Ant * challenger = new Ant(i);
		Ant * winner = ant->fight(challenger);
		if(winner == ant){
			delete challenger;
		}else{
			delete ant;
			ant = challenger;
		}
	}
	delete ant; // Added to prevent mem leaks
#endif
	return 0;
}
