#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#include "Store.h"

//print the user options
void PrintMenu() {
    cout << "Choose and option from the following:" << endl;
    cout << "1) Search frequency for an item" << endl;
    cout << "2) Print frequency for each item" << endl;
    cout << "3) Print frequency histogram for the items" << endl;
    cout << "4) Exit Program" << endl;
}

//take in user input and print how many times it shows up
void Store::OptionOne() {
    string userInput;

    cout << "What item are you looking for?" << endl;
    cin >> userInput;

    int counter = 0;

    for(int i = 0; i < frequencyList.size(); i++) {
        if(frequencyList.at(i) == userInput) counter++;
    }

    cout << userInput << " showed up " << counter << " times." << endl;
}

//print each item alongside how many times it shows up (ex. Beets 3)
void Store::OptionTwo() {
    unordered_map<string, int> frequencyMap;

    for(int i = 0; i < frequencyList.size(); i++) {
        if(frequencyMap.count(frequencyList.at(i)) > 0) {
            string item = frequencyList.at(i);
            int count = frequencyMap[item] + 1;

            frequencyMap.erase(item);
            frequencyMap.insert(make_pair(item, count));
        } else {
            frequencyMap.insert(make_pair(frequencyList.at(i), 1));
        }
    }
    
    for(const auto& pair : frequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

//print each item alongside how many times it shows up in asterisks (ex. Beets ***)
void OptionThree(vector<string> frequencyList) {
    unordered_map<string, int> frequencyMap;

    for(int i = 0; i < frequencyList.size(); i++) {
        if(frequencyMap.count(frequencyList.at(i)) > 0) {
            string item = frequencyList.at(i);
            int count = frequencyMap[item] + 1;

            frequencyMap.erase(item);
            frequencyMap.insert(make_pair(item, count));
        } else {
            frequencyMap.insert(make_pair(frequencyList.at(i), 1));
        }
    }

    for(const auto& pair : frequencyMap) {
        string element = pair.first + " ";

        for(int i = 0; i < pair.second; i++) {
            element = element + "*";
        }

        cout << element << endl;
    }
}

//write the data to a backup file
void Store::WriteData() {
    unordered_map<string, int> frequencyMap;
    ofstream outFS("frequency.dat");

    if(!outFS.is_open()) {
        cout << "Could not open file." << endl;
    }

    for(int i = 0; i < frequencyList.size(); i++) {
        if(frequencyMap.count(frequencyList.at(i)) > 0) {
            string item = frequencyList.at(i);
            int count = frequencyMap[item] + 1;

            frequencyMap.erase(item);
            frequencyMap.insert(make_pair(item, count));
        } else {
            frequencyMap.insert(make_pair(frequencyList.at(i), 1));
        }
    }

    for(const auto& pair : frequencyMap) {
        outFS << pair.first << " " << pair.second << endl;
    }
}

//get the frequency list
vector<string> Store::GetFrequencyList() {
    return frequencyList;
}

//set the frequency list
void SetFrequencyList(vector<string> frequencyList) {
    frequencyList = frequencyList;
}