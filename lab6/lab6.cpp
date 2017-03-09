#include "Sorter.h"
#include "Sorter.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <list>

using namespace std;

#define DEFAULT_NUMVALUES 25
#define MAX_NUMVALUES 1000

int main () {
    srand(time(NULL));

    cerr << "\n\tTEST #1: Test creation and basic operations on empty Sorter" << endl;

    Sorter<vector<int> > my_vector_sorter;
    Sorter<list<int> > my_list_sorter;

    my_vector_sorter.clear();
    my_list_sorter.clear();
    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #2: Test insertion and shuffle of a single value Sorter Object" << endl;

    my_vector_sorter.insert(5);
    my_list_sorter.insert(5);
    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.clear();
    my_list_sorter.clear();
    assert(my_vector_sorter.size() == 0);
    assert(my_list_sorter.size() == 0);

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #3: Test insertion and shuffle of a multiple values" << endl;

    for(int i = 0; i < DEFAULT_NUMVALUES; i++){
        my_vector_sorter.insert(i);
        my_list_sorter.insert(i);
    }
    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    assert(my_vector_sorter.size() == DEFAULT_NUMVALUES);
    assert(my_list_sorter.size() == DEFAULT_NUMVALUES);
    int allowances = DEFAULT_NUMVALUES;
    for(int i = 0; i < DEFAULT_NUMVALUES; i++){
        if(i != 0 && *(my_list_sorter[i-1]) == *(my_list_sorter[i]--))
            allowances--;
        if(*(my_vector_sorter[i]) == *(my_list_sorter[i]))
            allowances--;
        assert(allowances > 0);
    }
    my_vector_sorter.clear();
    my_list_sorter.clear();
    assert(my_vector_sorter.size() == 0);
    assert(my_list_sorter.size() == 0);

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #4: Test bubble sort of a multiple values" << endl;

    for(int i = 0; i < DEFAULT_NUMVALUES; i++){
        my_vector_sorter.insert(i);
        my_list_sorter.insert(i);
    }

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.bubbleSort();
    my_list_sorter.bubbleSort();
    for(int i = 1; i < DEFAULT_NUMVALUES; i++){
        assert(*(my_list_sorter[i-1]) == *(my_list_sorter[i])-1);
        assert(*(my_vector_sorter[i-1]) == *(my_vector_sorter[i])-1);
    }
    assert(my_vector_sorter.size() == DEFAULT_NUMVALUES);
    assert(my_list_sorter.size() == DEFAULT_NUMVALUES);

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #5: Test selection sort of a multiple values" << endl;

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.selectionSort();
    my_list_sorter.selectionSort();
    for(int i = 1; i < DEFAULT_NUMVALUES; i++){
        assert(*(my_list_sorter[i-1]) == *(my_list_sorter[i])-1);
        assert(*(my_vector_sorter[i-1]) == *(my_vector_sorter[i])-1);
    }
    assert(my_vector_sorter.size() == DEFAULT_NUMVALUES);
    assert(my_list_sorter.size() == DEFAULT_NUMVALUES);

    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #6: Test insertion sort of a multiple values" << endl;

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.insertionSort();
    my_list_sorter.insertionSort();
    for(int i = 1; i < DEFAULT_NUMVALUES; i++){
        assert(*(my_list_sorter[i-1]) == *(my_list_sorter[i])-1);
        assert(*(my_vector_sorter[i-1]) == *(my_vector_sorter[i])-1);
    }
    assert(my_vector_sorter.size() == DEFAULT_NUMVALUES);
    assert(my_list_sorter.size() == DEFAULT_NUMVALUES);
    my_vector_sorter.clear();
    my_list_sorter.clear();
    cerr << "\n\t========================PASS========================\n" << endl;

    cerr << "\n\tTEST #7: Test multiple sorts of a lot of random values" << endl;

    for(int i = 0; i < MAX_NUMVALUES; i++){
        int rnum = rand()%MAX_NUMVALUES + 1;
        my_vector_sorter.insert(rnum);
        rnum = rand()%MAX_NUMVALUES + 1;
        my_list_sorter.insert(i);
    }

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.insertionSort();
    my_list_sorter.insertionSort();
    int vector_prev = *(my_vector_sorter[0]);
    int list_prev = *(my_list_sorter[0]);
    for(int i = 1; i < MAX_NUMVALUES; i++){
        assert(vector_prev <= *(my_vector_sorter[i]));
        assert(list_prev <= *(my_list_sorter[i]));
    }
    assert(my_vector_sorter.size() == MAX_NUMVALUES);
    assert(my_list_sorter.size() == MAX_NUMVALUES);

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.selectionSort();
    my_list_sorter.selectionSort();
    vector_prev = *(my_vector_sorter[0]);
    list_prev = *(my_list_sorter[0]);
    for(int i = 1; i < MAX_NUMVALUES; i++){
        assert(vector_prev <= *(my_vector_sorter[i]));
        assert(list_prev <= *(my_list_sorter[i]));
    }
    assert(my_vector_sorter.size() == MAX_NUMVALUES);
    assert(my_list_sorter.size() == MAX_NUMVALUES);

    my_vector_sorter.shuffle();
    my_list_sorter.shuffle();
    my_vector_sorter.bubbleSort();
    my_list_sorter.bubbleSort();
    vector_prev = *(my_vector_sorter[0]);
    list_prev = *(my_list_sorter[0]);
    for(int i = 1; i < MAX_NUMVALUES; i++){
        assert(vector_prev <= *(my_vector_sorter[i]));
        assert(list_prev <= *(my_list_sorter[i]));
    }
    assert(my_vector_sorter.size() == MAX_NUMVALUES);
    assert(my_list_sorter.size() == MAX_NUMVALUES);
    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;

    return 0;
}
