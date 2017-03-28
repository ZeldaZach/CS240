#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <vector>
#include "BSTree.h"
#include "BSTree.h"
using namespace std;

#define NUM_VALUES 12

void testList(vector<int> &list, vector<int> &compare){
	assert(list.size() == compare.size());
	for(unsigned int i = 0; i < list.size(); i++){
		cerr << " [" << list[i] << "] ";
		assert(list.at(i) == compare.at(i));
	}
	cerr << endl;
}

int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Create an empty tree" << endl;
  	BSTree tree;
  	assert(tree.empty());

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #2: Insert values into the Tree" << endl;

  	int array[] = {5,3,10,8,2,1,7,9,6,12,11,13};
  	for(int i = 0; i < NUM_VALUES; i++){
  		tree.insert(array[i]);
      assert(!tree.empty());
  	}

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #3: Cannot insert duplicate values into the Tree" << endl;

  	for(int i = 0; i < NUM_VALUES; i++){
  		assert(!tree.insert(array[i]));
  	}

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #4: Insert 1000 Values into the Tree" << endl;

  	BSTree tree2;
  	for(int i = 0; i < 1000; i++){
  		int value = rand() % 10000;
  		tree2.insert(value);
  	}

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #5: Find values in the tree" << endl;

  	for(int i = 1; i <= NUM_VALUES; i++){
  		if(i != 4)
  			assert(tree.find(i));
  		else
  			assert(!tree.find(i));
  	}

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #6: Find doesn't segfault on empty tree" << endl;

  	BSTree tree3;
  	assert(!tree3.find(1));

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #7: Cannot remove node that is not in the tree" << endl;

	assert(!tree.remove(25));
	vector<int> test;
	tree.sortedArray(test);
	vector<int> compare = {1,2,3,5,6,7,8,9,10,11,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #8: Remove a leaf node" << endl;

	assert(tree.remove(1));
	tree.sortedArray(test);
	compare = {2,3,5,6,7,8,9,10,11,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #9: Remove single branch using the Short Circuit algorithm" << endl;

	assert(tree.remove(7));
	tree.sortedArray(test);
	compare = {2,3,5,6,8,9,10,11,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTest #10: Remove two branch node promoting a leaf node" << endl;

	assert(tree.remove(10));
	tree.sortedArray(test);
	compare = {2,3,5,6,8,9,11,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #11: Remove two branch node promoting a 1 branch node using Short Circuit" << endl;

	assert(tree.remove(11));
	tree.sortedArray(test);
	compare = {2,3,5,6,8,9,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #12: Remove root with two branches" << endl;

	assert(tree.remove(5));
	tree.sortedArray(test);
	compare = {2,3,6,8,9,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #13: Remove root with one branch" << endl;

	assert(tree.remove(3));
	assert(tree.remove(2));
	assert(tree.remove(6));
	tree.sortedArray(test);
	compare = {8,9,12,13};
	testList(test, compare);
	test.clear();

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #14: Remove root as leaf" << endl;

	assert(tree.remove(9));
	assert(tree.remove(8));
	assert(tree.remove(13));
	assert(tree.remove(12));
	tree.sortedArray(test);
	assert(test.size() == 0);

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #15: Deep copy for a tree of 100 random values" << endl;

	for(int i = 0; i < 100; i++){
		int value = rand() % 1000;
		tree.insert(value);
	}

	BSTree * copyTree = new BSTree(tree);
	vector<int> testCopy;
	tree.sortedArray(test);
	copyTree->sortedArray(testCopy);
	assert(testCopy == test);

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #16: Test deletion and Destructor" << endl;

	for(int i = 0; i < 1000; i++){
		tree.remove(i);
	}
	assert(tree.empty());
	delete copyTree;

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;

	return 0;
}
