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
    srand(time(NULL));
    cout << "Testing effectiveness of each randomization method created" << endl;
    cout << "Evaluation Metrics:" << endl;
    cout << "Each permutation of the vector should have an equal likelihood of being created when randomized." << endl;
    cout << "The randomization test will determine the difference in probabilities between the expected count for each permutation " << endl;
    cout << "and the actual count for a set number of test samples." << endl;
    cout << endl;

    // Create and test randomization on int vector and Tile vector
    cout << "************* Randomization Method Test - Integer Vector *************" << endl;
    vector<int> testVectInt;
    for (int i = 0; i < 3; i++) {
        testVectInt.push_back(rand() % 25);
    }
    Items<int> itemsInt(testVectInt);
    itemsInt.testRandomizer();
    cout << endl << endl;

    cout << "************* Randomization Method Test - Tile Vector *************" << endl;
    vector<Tile> testVectTile;
    for (int i = 0; i < 7; i++) {
        Tile newTile;
        newTile = newTile.randomizeTile();
        testVectTile.push_back(newTile);
    }
    Items<Tile> itemsTile(testVectTile);
    itemsTile.testRandomizer();

    return 0;
}