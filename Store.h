#include <vector>
using namespace std;

#ifndef STORE_H
#define STORE_H

class Store {
    public:
        void PrintMenu() const;
        void OptionOne();
        void OptionTwo();
        void OptionThree();
        void WriteData();
        vector<string> GetFrequencyList();
        void SetFrequencyList(vector<string> frequencyList);
    private:
        vector<string> frequencyList;
};

#endif