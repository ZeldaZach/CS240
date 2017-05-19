#include "Hash.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main(){

    cerr << "\n\tTEST #1: Create a hash of the correct size" << endl;

    Hash passwords(10);
    assert(passwords.size() == 10);

    string name,      // user-supplied name
           pass;      // user-supplied password
	//*********************************************************
	// Step 1: Read in the password file
	//*********************************************************
    ifstream pass_file( "password.txt" );

    if (!pass_file){
        cout << "Unable to open 'password.txt'!" << endl;
        return 1;
    }

    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tTEST #2: Insert values into the Hash" << endl;

    while (pass_file >> name >> pass){
        if(name != "quit"){
			std::cout << "Inserting " << name << std::endl;
            assert(passwords.insert(name, pass));
        }
    }

	passwords.printHash();

    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tTEST #3: Verify invalid password doesn't work" << endl;

    string stored_pass = passwords.find("This shouldn't exists in your hash");
    assert(stored_pass.empty());


    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tTEST #4: Verify valid passwords are retrievable" << endl;
    pass_file.clear();
    pass_file.seekg(0, ios::beg);
    pass_file >> name;
    while (name != "quit"){
        pass_file >> pass;

        stored_pass = passwords.find(name);
        assert(pass == stored_pass);
        pass_file >> name;
    }

    passwords.printHash();

    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tTEST #5: Remove entries from the hash" << endl;
    pass_file.clear();
    pass_file.seekg(0, ios::beg);
    while (!passwords.empty()){
        pass_file >> name >> pass;
        stored_pass = passwords.find(name);
        if(pass == stored_pass){
            passwords.remove(name);
            assert(passwords.size() == 10);
            assert(passwords.find(name) == "");
        }else{
            assert(false);
        }
    }

    pass_file.close();
    cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit to Blackboard!\n" << endl;

	return 0;

}
