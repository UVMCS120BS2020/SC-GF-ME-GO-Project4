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
    vector<int> v = {1,2,3,4};
    cout << "The 4! possible permutations with 3 elements:\n";
   // std::sort (myints,myints+3);
    do {
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';
    } while ( std::next_permutation(v.begin(), v.end()) );

    Tile test = Tile(6, "Wood");
    cout << test << endl;

    // Test sort
    vector<int> testVect;
    for (int i = 0; i < 30; i++) {
        testVect.push_back(rand() % 25);
    }
    Items<int> items(testVect);
    cout << "Unsorted elements: " << items << endl;
    items.sort();
    cout << "Sorted elements: " << items << endl;
    return 0;
}