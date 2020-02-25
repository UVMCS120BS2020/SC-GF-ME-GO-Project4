// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#ifndef PROJECT4_TILE_H
#define PROJECT4_TILE_H

#include <ostream>
#include <vector>
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

    // Overloaded << Operator
    // Requires: ostream and Tile object
    // Modifies: nothing
    // Effects: prints out the Tile's two fields
    friend ostream& operator << (ostream& outs, const Tile &tile) {
        outs << tile.getResource() << " (" << tile.getNumber() << ") ";
        return outs;
    }

private:
    // Fields
    int fNumber; // the dice roll number needed to collect
    string fResource; // the type of resource
};

#endif //PROJECT4_TILE_H
