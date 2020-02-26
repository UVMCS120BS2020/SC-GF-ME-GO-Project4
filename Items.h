// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#ifndef PROJECT4_ITEMS_H
#define PROJECT4_ITEMS_H

#include <vector>
#include <iostream>

using namespace std;
template <typename Object>

/********** Items Class **********/

class Items {
public:
    // Constructor
    // Requires: a vector
    // Modifies: fList
    // Effects: initializes fList field with given specified data
    Items(vector<Object> list) : fList(list) {}

    // Getters
    // Requires: nothing
    // Modifies: nothing
    // Effects: returns value of field requested
    vector<Object> getList() {
        return fList;
    }

    // Requires: nothing
    // Modifies: fList
    // Effects: sorts fList of objects in ascending order of value
    void sort() {

    }

    // Requires: Object to search for in fList
    // Modifies: nothing
    // Effects: Searches for specified item in fList. return index of item in vector if found and -1 otherwise
    int find(Object object) {
        for (int i = 0; i < fList.size(); i++) {
            if (fList.get(i) == object) {
                return i;
            }
        }
        return -1;
    }

    // Randomization Methods
    // Requires: nothing
    // Modifies: fList
    // Effects: randomizes order of objects in fList
    void randomizeSC();

    void randomizeME();

    void randomizeGO() {
        for (int i = 0; i < fList.size(); i++) {
            // get random index to swap with
            int rand = 0;

            // perform swap
            Object temp = fList.at(i);
            fList.at(i) = fList.at(rand);
            fList.at(rand) = temp;
        }
    }

    void testRandomizer() {
        //create tester vector with integers in sorted order
        vector<int> testVec = {0,1,2,3,4};
        fList = testVec;
        vector<vector<int>> permHolder;

        //find all possible permutations of the vector
        do {
            permHolder.push_back(testVec);
            for (int i = 0; i < testVec.size(); ++i) {
                std::cout << testVec[i] << " ";
            }
            cout << '\n';

        } while ( std::next_permutation(testVec.begin(), testVec.end()) );

        for(int i = 0; i < 100; ++i) {
            //randomize the vector
            //find the shuffle permutation in possibilities
            //increase count of that permutation

        }
        //compare the counts of all of the permutations vs. expected frequency
    }

    // Overloaded << operator
    // Requires: ostream and items object
    // Modifies: nothing
    // Effects: prints out all objects held in fList
    friend ostream& operator << (ostream& outs, const Items &items) {
        outs << "Items held in fList vector: ";
        for (int i = 0; i < items.fList.size(); i++) {
            if (i == 0) {
                outs << items.fList.at(i);
            } else {
                outs << ", " << items.fList.at(i);
            }
        }
        return outs;
    }

private:
    vector<Object> fList;
};


#endif //PROJECT4_ITEMS_H
