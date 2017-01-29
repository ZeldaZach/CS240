#include "AntHill.h"
#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define NUM_ANTS_TO_TEST 5

int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Test Ant Hill Creation with 0 ants" << endl;

	AntHill hill(0);
	assert(hill.getCurrentNumAnts() == 0);
	assert(hill.getMaxAnts() == 0);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Test Change Max" << endl;
	//Change the maximum number fo ants to 5
	hill.changeMax(NUM_ANTS_TO_TEST);
	assert(hill.getCurrentNumAnts() == 0);
	assert(hill.getMaxAnts() == NUM_ANTS_TO_TEST);
	//change max should ignore negative values
	hill.changeMax(-1);
	assert(hill.getCurrentNumAnts() == 0);
	assert(hill.getMaxAnts() == NUM_ANTS_TO_TEST);

	//change max should not allow more than 100 ants
	hill.changeMax(200);
	assert(hill.getCurrentNumAnts() == 0);
	assert(hill.getMaxAnts() == NUM_ANTS_TO_TEST);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Add Ants" << endl;

	//Add up to the maximum number of ants
	int last_id = -1;
	for(int i = 0; i < NUM_ANTS_TO_TEST; i++){
		hill.addAnt();
		assert(hill.getCurrentNumAnts() == i+1);
		assert(hill.getMaxAnts() == NUM_ANTS_TO_TEST);
		Ant temp = hill.getAnt(i);
		assert(temp.getID() != last_id);
		last_id = temp.getID();
	}
	//attempting to add beyond maximum should return false
	assert(hill.addAnt() == false);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Move Ants" << endl;

	//After calling move the ants should move randomly by one unit up/down or left/right
	for(int i = 0; i < NUM_ANTS_TO_TEST; i++){
		Ant temp = hill.getAnt(i);
		hill.move();
		bool different = false;
		for(int j = 0; j < NUM_ANTS_TO_TEST; j++){
			Ant check = hill.getAnt(j);
			if(check.getX() != temp.getX() || check.getY() != temp.getY()){
				different = true;
			}
		}
		assert(different);
	}

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Print Hill Information" << endl;

	hill.printHillInfo();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tAll Tests Passed.\nDont forget to run with Valgrind and submit to Blackboard!\n" << endl;
	return 0;
}
