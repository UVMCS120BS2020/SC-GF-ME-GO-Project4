// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#ifndef PROJECT4_ITEMS_H
#define PROJECT4_ITEMS_H

#include <vector>
#include <iostream>
#include <cmath>
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
    int findObject(vector<Object> vec, Object object) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec.get(i) == object) {
                return i;
            }
        }
        return -1;
    }

    int find(vector<vector<Object>> vec, vector<Object> object) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) == object) {
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
        // initialize return vector
        vector<Object> returnVector = {};
        // iterate through loop for 19 Tiles
        for (int i = 0; i < 19; i++) {
            // create and randomize new Tile object
            Tile newTile;
            newTile = newTile.randomizeTile();
            // check to see if this Tile is already in the vector
            for (int i = 0; i < fList.size(); i++) {
                // randomize Tile until a new one is created
                while (findObject(returnVector, newTile) != 1) {
                    newTile = newTile.randomizeTile();
                }
            }
            // push new Tile object to vector
            returnVector.push_back(newTile);
        }
        // return vector of Tile objects
        return returnVector;
    }

    vector<Object>  randomizeME(){

        srand((unsigned) time(0));
        for (int i = 0 ;i < fList.size(); ++i){
            int r = rand() %fList.size();

            iter_swap(fList.begin() + i, fList.begin() + r);

        }

        return fList;
    }

    void randomizeGO() {
        for (int i = 0; i < fList.size(); i++) {
            // get random index to swap with
            // use memory address of object held and prime number 47 to get random index
            int randIndex = (int) &fList.at(i) * 47 % fList.size();

            // perform swap
            Object temp = fList.at(i);
            fList.at(i) = fList.at(randIndex);
            fList.at(randIndex) = temp;
        }
    }

    void testRandomizer() {
        //create vector to hold all possible permutations of the test vector
        vector<vector<int>> permHolder;

        //sort the list
        sort();
        //find all possible permutations of the list and add to vector
        do {
            permHolder.push_back(fList);

        } while ( std::next_permutation(fList.begin(), fList.end()));

        //create vector that matches with possible permutations and starts with all 0's
        //will hold the final counts of each permutation created with randomize functions
        vector<int> counts(permHolder.size(), 0);

        //set the number of runs to do for testing
        int testSamples = 100;
        //the expected count for every permutation should be an equal count
        double expectedCount = double(testSamples)/permHolder.size();
        //initialize the difference count
        double totalDifference = 0;

        //run through the randomizer and keep track of counts for every permutation that results
//        for(int i = 0; i < testSamples; ++i) {
//            //randomize the vector
//            randomizeGO();
//            //find the shuffle permutation in possibilities
//            auto iteration = find(permHolder.begin(), permHolder.end(), fList);
//            int index = distance(permHolder.begin(), iteration);
//            //increase count of that permutation
//            counts.at(index) = counts.at(index) + 1;
//
//            //sort the list so that the randomizer starts at the same place every times
//            sort();
//
//        }
//        //compare the counts of all of the permutations vs. expected frequency
//        for (int i = 0; i < counts.size(); ++i) {
//            totalDifference += abs(counts.at(i)-expectedCount);
//        }
//        cout << "Total differences for the GO randomizer: " << totalDifference << endl;
//        //clear the counts vector and remake as all 0's
//        counts.clear();
//        counts.assign(permHolder.size(), 0);
//        totalDifference = 0;

        //run through the randomizer and keep track of counts for every permutation that results
        for(int i = 0; i < testSamples; ++i) {
            //randomize the vector
            //randomizeME();
            int index = find(permHolder, randomizeME());
            //find the shuffle permutation in possibilities
//            auto iteration = find(permHolder.begin(), permHolder.end(), fList);
//            int index = distance(permHolder.begin(), iteration);
            //increase count of that permutation
            counts.at(index) = counts.at(index) + 1;

            //sort the list so that the randomizer starts at the same place every times
            sort();

        }
        //compare the counts of all of the permutations vs. expected frequency
        for (int i = 0; i < counts.size(); ++i) {
            totalDifference += abs(counts.at(i)-expectedCount);
        }
        cout << "\nTotal differences for the ME randomizer: " << totalDifference << endl;
        //clear the counts vector and remake as all 0's
        counts.clear();
        counts.assign(permHolder.size(), 0);
        totalDifference = 0;

        //run through the randomizer and keep track of counts for every permutation that results
//        for(int i = 0; i < testSamples; ++i) {
//            //randomize the vector
//            randomizeSC();
//            //find the shuffle permutation in possibilities
//            auto iteration = find(permHolder.begin(), permHolder.end(), fList);
//            int index = distance(permHolder.begin(), iteration);
//            //increase count of that permutation
//            counts.at(index) = counts.at(index) + 1;
//
//            //sort the list so that the randomizer starts at the same place every times
//            sort();
//
//        }
//        //compare the counts of all of the permutations vs. expected frequency
//        for (int i = 0; i < counts.size(); ++i) {
//            totalDifference += abs(counts.at(i)-expectedCount);
//        }
//        cout << "Total differences for the SC randomizer: " << totalDifference << endl;


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
