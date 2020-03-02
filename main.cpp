// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4
#include <algorithm>
#include "Items.h"
#include "Tile.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;



int main() {
    vector<int> testVec = {1,2,3,4,5};


    Tile test;
    test = test.randomizeTile();
    cout << test << endl;


    // Test sort
    vector<int> testVect;
    for (int i = 0; i < 4; i++) {
        testVect.push_back(rand() % 25);
    }
    Items<int> items(testVect);
    cout << "Unsorted elements: " << items << endl;
    items.sort();
    cout << "Sorted elements: " << items << endl;

    items.randomizeME();
    cout << (cout, items);
    items.testRandomizer();
    return 0;
}