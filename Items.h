// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#ifndef PROJECT4_ITEMS_H
#define PROJECT4_ITEMS_H

#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include "Tile.h"
#include "time.h"

using namespace std;
template <typename Object>

/********** Items Class **********/

class Items {
public:
    // Constructor
    // Requires: a vector
    // Modifies: fList
    // Effects: initializes fList field with given specified data
    Items(vector<Object> list) : fList(list) {
        srand((unsigned) time(NULL));
    }

    // Getters
    // Requires: nothing
    // Modifies: nothing
    // Effects: returns value of field requested
    vector<Object> getList() {
        return fList;
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
    int findObject(Object object) {
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
    vector<Object> randomizeSC() {
        // initialize random variables
        int randIndex = 0;
        int maxRandIndex = fList.size();
        // iterate through list
        for (int i = 0; i < fList.size(); i++) {
            // reiterate through list
            for (int j = 0; i < fList.size(); i++) {
                // objects in comparison are different
                if (!(fList[i] == fList[j])) {
                    // get random index value
                    randIndex = rand() % fList.size();
                    // swap different objects
                    swap(fList[i], fList[j]);
                    // swap with random object
                    swap(fList[randIndex], fList[i]);
                // objects in comparison are the same
                } else {
                    // get random index value
                    randIndex = rand() % fList.size();
                    // swap with last object
                    swap(fList[i], fList[fList.size() - 1]);
                    // swap with random object
                    swap(fList[randIndex], fList[i]);
                }
            }
        }
        return fList;
    }

    // Requires: nothing
    // Modifies: fList
    // Effects: randomizes order of objects in fList
    vector<Object>  randomizeME(){
        //set t as the current time
        time_t t = clock();
        //r will be the index to swap with
        int r;
        //loop through every value in the vector
        for (int i = 0 ;i < fList.size(); ++i){
            //multiply the clock by a prime number and increase
            t += (clock()*31);

            //mod by the size of the vector so the index is in range
            r = t%fList.size();

            //swap the indices
            swap(fList[i], fList[r]);

        }

        return fList;
    }

    // Requires: nothing
    // Modifies: fList
    // Effects: randomizes order of objects in fList
    void randomizeGO() {
        // loop through all items in fList vector
        // for each iteration, get a random index and swap item with object at that index
        for (int i = 0; i < fList.size(); i++) {
            // Get time in nanoseconds to hash an index with
            auto nano = chrono::high_resolution_clock::now();
            long long timeHash = chrono::duration_cast<chrono::nanoseconds>(nano.time_since_epoch()).count();

            // use random constant each time to add variability to index
            randConst = (int) (timeHash * 47) + randConst;

            // Use timeHash to get a random index to swap with
            int randIndex = (int)(abs(timeHash + randConst) % fList.size());

            // perform swap
            Object temp = fList.at(i);
            fList.at(i) = fList.at(randIndex);
            fList.at(randIndex) = temp;
        }
    }

    // Requires: nothing
    // Modifies: fList
    // Effects: randomizes order of objects in fList
    vector<Object> randomizeGF(){
        int randomGF = 0;
        vector<int> takenNum;
        vector<Object> copyVec = fList;
        // for every item in fList, assign random position
        for (int i = 0; i < fList.size(); ++i){
            randomGF = rand()%fList.size();
            // make sure the random isn't already chosen
            while (find(takenNum.begin(), takenNum.end(), randomGF) != takenNum.end()){
                randomGF = rand()%fList.size();
            }
            takenNum.push_back(randomGF);
            copyVec[randomGF] = fList[i];
        }
        return copyVec;
    }

    // Requires: nothing
    // Modifies: nothing
    // Effects: runs through a series of randomization functions and compares the resulting permutations
    //      with the theoretical expected counts. Displays the findings of the tests.
    void testRandomizer() {
        //create vector to hold all possible permutations of the test vector
        vector<vector<Object>> permHolder;

        //sort the list
        sort();
        //findPermutation all possible permutations of the list and add to vector
        do {
            permHolder.push_back(fList);

        } while ( std::next_permutation(fList.begin(), fList.end()));

        //create vector that matches with possible permutations and starts with all 0's
        //will hold the final counts of each permutation created with randomize functions
        vector<int> counts(permHolder.size(), 0);

        //set the number of runs to do for testing
        int testSamples = 1000;
        cout << "Running " << testSamples << " randomization tests on vector." << endl;
        //the expected count for every permutation should be an equal count
        double expectedCount = double(testSamples)/permHolder.size();
        cout << "Expected count for each permutation: " << expectedCount << endl;
        //initialize the difference count
        double avgDifference = 0;

        // run through the randomizer and keep track of counts for every permutation that results
        for(int i = 0; i < testSamples; ++i) {
            randomizeGO();
            //findPermutation the index in the permutations
            int index = findPermutation(permHolder, fList);

            //increase count of that permutation
            counts[index] += 1;

            //sort the list so that the randomizer starts at the same place every times
            sort();
        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            avgDifference += abs(counts[i]-expectedCount);
        }
        avgDifference /= counts.size();
        cout << "\nAverage difference in expected count and actual count of permutations for the GO randomizer: " << avgDifference << endl;
        //clear the counts vector and remake as all 0's
        cout << "Permutation count distribution vector for GO: ";
        cout << "[";
        for (int i = 0; i < counts.size(); ++i){
            if (i == 0) {
                cout << counts[i];
            } else {
                cout << "," << counts[i];
            }
        }
        cout << "]" << endl;
        counts.clear();
        counts.assign(permHolder.size(), 0);
        avgDifference = 0;

        //run through the randomizer and keep track of counts for every permutation that results
        for(int i = 0; i < testSamples; ++i) {
            randomizeME();
            //findPermutation the index in the permutations
            int index = findPermutation(permHolder, fList);

            //increase count of that permutation
            counts[index] += 1;

            //sort the list so that the randomizer starts at the same place every times
            sort();
        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            avgDifference += abs(counts[i]-expectedCount);
        }
        avgDifference /= counts.size();
        cout << "\nAverage difference in expected count and actual count permutations for the ME randomizer: " << avgDifference << endl;
        //clear the counts vector and remake as all 0's
        cout << "Permutation count distribution vector for ME: ";
        cout << "[";
        for (int i = 0; i < counts.size(); ++i){
            if (i == 0) {
                cout << counts[i];
            } else {
                cout << "," << counts[i];
            }
        }
        cout << "]" << endl;
        counts.clear();
        counts.assign(permHolder.size(), 0);
        avgDifference = 0;

        //run through the randomizer and keep track of counts for every permutation that results
        for(int i = 0; i < testSamples; ++i) {
            //randomize the vector
            fList = randomizeSC();
            //findPermutation the index in the permutations
            int index = findPermutation(permHolder, fList);

            //increase count of that permutation
            counts[index] += 1;

            //sort the list so that the randomizer starts at the same place every times
            sort();
        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            avgDifference += abs(counts.at(i)-expectedCount);
        }
        avgDifference /= counts.size();
        cout << "\nAverage difference in expected count and actual count permutations for the SC randomizer: " << avgDifference << endl;
        cout << "Permutation count for SC: ";
        cout << "[";
        for (int i = 0; i < counts.size(); ++i){
            if (i == 0) {
                cout << counts[i];
            } else {
                cout << "," << counts[i];
            }
        }
        cout << "]" << endl;
        counts.clear();
        counts.assign(permHolder.size(), 0);
        avgDifference = 0;

        // run through the randomizer and keep track of counts for every permutation that results
        for(int i = 0; i < testSamples; ++i) {
            fList = randomizeGF();
            //findPermutation the index in the permutations
            int index = findPermutation(permHolder, fList);

            //increase count of that permutation
            counts[index] += 1;

            //sort the list so that the randomizer starts at the same place every times
            sort();
        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            avgDifference += abs(counts[i]-expectedCount);
        }
        avgDifference /= counts.size();
        cout << "\nAverage difference in expected count and actual count of permutations for the GF randomizer: " << avgDifference << endl;
        //clear the counts vector and remake as all 0's
        cout << "Permutation count distribution vector for GF: ";
        cout << "[";
        for (int i = 0; i < counts.size(); ++i){
            if (i == 0) {
                cout << counts[i];
            } else {
                cout << "," << counts[i];
            }
        }
        cout << "]" << endl;
    }


private:
    vector<Object> fList;
    int randConst = 7; // used for randomizeGO random number generation

    // used in randomization testing method
    // Requires: a vector of vectors to store all possible permutations of values, a vector containing one of these permutations
    // Modifies: nothing
    // Effects: Searches vector of permutations for unique object vector passed in. Returns index of that object if found and -1 otherwise
    int findPermutation(vector<vector<Object>> vec, vector<Object> object) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) == object) {
                return i;
            }
        }
        return -1;
    }
};


#endif //PROJECT4_ITEMS_H