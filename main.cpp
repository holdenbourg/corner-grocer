#include <iostream>
#include <fstream>

#include "Store.h"

using namespace std;

int main() {
    ifstream inFS;

    //Open the input frequency file and make sure it opens
    inFS.open("item-frequency-list.txt");

    if(!inFS.is_open()) {
        cout << "Could not open file." << endl;

        return 1;
    }

    //while the input !fail() add each element to a vector for later use
    string input;
    vector<string> frequencyList;
    while(!inFS.fail())  {
        inFS >> input;
        frequencyList.push_back(input);
    }

    //indiciate a error if the input fails before reachingthe end of the file
    if(!inFS.eof()) {
        cout << "Input failed before reaching the end of the file." << endl;
    }

    //create a store object for use of its member functions, then set it's frequency list
    Store store;
    store.SetFrequencyList(frequencyList);

    int response;

    //while the users input is anything less than 4, execute the order, if it is 4 or more exit the program
    while(response < 4) {
        store.PrintMenu();

        cin >> response;

        switch(response) {
            case 1:
                store.OptionOne();
                break;
            case 2: 
                store.OptionTwo();
                break;
            case 3:
                store.OptionThree();
                break;
        }
    }

    //indicate the program exit and write the data to a backup file
    cout << "Exiting Program" << endl;
    store.WriteData();

    return 0;
}