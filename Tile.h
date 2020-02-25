// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#ifndef PROJECT4_TILE_H
#define PROJECT4_TILE_H

#include <ostream>

using namespace std;

/********** Tile Class **********/

class Tile {
public:
    // Default Constructor
    // Requires: nothing
    // Modifies: nothing
    // Effects: creates Tile object
    Tile();

    // Alternate Constructor
    // Requires: int param
    // Modifies: nothing
    // Effects: creates Tile object with number field
    Tile(int pNumber);

    // Alternate Constructor
    // Requires: string param
    // Modifies: nothing
    // Effects: creates Tile object with resource field
    Tile(string pResource);

    // Full Constructor
    // Requires: int and string param
    // Modifies: nothing
    // Effects: creates Tile object with both fields
    Tile(int pNumber, string pResource);

    // Getters
    // Requires: nothing
    // Modifies: nothing
    // Effects: returns Tile object field
    int getNumber() const;
    string getResource() const;

    // Setters
    // Requires: int or string param
    // Modifies: nothing
    // Effects: sets Tile object field to new param value
    void setNumber(int pNumber);
    void setResource(string pResource);

private:
    // Fields
    int fNumber; // the dice roll number needed to collect
    string fResource // the type of resource
};

#endif //PROJECT4_TILE_H
