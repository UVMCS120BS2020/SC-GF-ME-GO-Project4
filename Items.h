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
        // Insertion sort
        for (int i = 0; i < fList.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (fList.at(j) < fList.at(j - 1)) {
                    // perform swap
                    Object temp = fList.at(j);
                    fList.at(j) = fList.at(j - 1);
                    fList.at(j - 1) = temp;
                } else {
                    // object is greater than or equal to all elements below it
                    // go to next object in list
                    break;
                }
            }
        }
    }

    // Requires: Object to search for in fList
    // Modifies: nothing
    // Effects: Searches for specified item in fList. return index of item in vector if found and -1 otherwise
    int find(vector<Object> vec, Object object) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec.get(i) == object) {
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

    vector<Object>  randomizeME(){
        vector<Object> temp = {};
        string resource;
        for (int i = 0 ;i < fList.size(); ++i){
            int hash = 0;
            resource = fList.at(i).getResource();
            for (int i = 0; i < resource.length(); ++i) {
                hash += (resource[i]);
            }
            temp.insert((hash%fList.size()), fList.at(i));
        }
        return temp;
    }

    void randomizeGO() {
        for (int i = 0; i < fList.size(); i++) {
            // get random index to swap with
            // use memory address of object held and prime number 47 to get random index
            int rand = (int) &fList.at(i) * 47 % fList.size();

            // perform swap
            Object temp = fList.at(i);
            fList.at(i) = fList.at(rand);
            fList.at(rand) = temp;
        }
    }

    void testRandomizer() {
        //create tester vector with integers in sorted order
        vector<int> testVec = {0,1,2,3,4};

        //create vector to hold all possible permutations of the test vector
        vector<vector<int>> permHolder;

        //create vector that matches with possible permutations and starts with all 0's
        //will hold the final counts of each permutation created with randomize functions
        vector<int> counts(permHolder.size(), 0);

        int testSamples = 1000;
        double expectedCount = double(testSamples)/permHolder.size();
        double totalDifference = 0;

        //find all possible permutations of the vector and add to vector
        do {
            permHolder.push_back(testVec);
            for (int i = 0; i < testVec.size(); ++i) {
                std::cout << testVec[i] << " ";
            }
            cout << '\n';

        } while ( std::next_permutation(testVec.begin(), testVec.end()) );

        for(int i = 0; i < testSamples; ++i) {
            //randomize the vector
            //find the shuffle permutation in possibilities
            int index = find(permHolder, randomizeME());
            //increase count of that permutation
            counts.at(index) = counts.at(index) + 1;

        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            totalDifference += (counts.at(i)-expectedCount);
        }
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
