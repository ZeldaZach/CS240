#include "AntHill.h"
#include "AntHill.h"
#include "Ant.h"
#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define END_SIM 100
int main(){
	srand(time(NULL));

	cerr << "\n\tTEST #1: Run AntFarm Simulation" << endl;
	AntHill * farm = new AntHill();
	while(farm->getCurrentNumAnts() > 0 && farm->getCurrentNumAnts() < END_SIM){
		farm->turn();
	}
	delete farm;
	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;

	return 0;
}
