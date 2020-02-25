// Sean Cosgrove, Molly Eaton and Gavin O'Sullivan
// Lisa Dion
// CS 120B
// Project 4

#include "Tile.h"

/********** Tile Class **********/

// Default Constructor
Tile::Tile() : fNumber(0), fResource("Desert") {
}

// Alternate Constructors
Tile::Tile(int pNumber) : fNumber(pNumber), fResource("Wood") {
}
Tile::Tile(string pResource) : fResource(pResource), fNumber(6) {
}

// Full Constructor
Tile::Tile(int pNumber, string pResource) : fNumber(pNumber), fResource(pResource) {
}

// Getters
int Tile::getNumber() const {
    return fNumber;
}
string Tile::getResource() const {
    return fResource;
}

// Setters
void Tile::setNumber(int pNumber) {
    fNumber = pNumber;
}
void Tile::setResource(string pResource) {
    fResource = pResource;
}


// Overloaded Operators

// <<
ostream& operator << (ostream& outs, const Tile &tile) {
    outs << tile.getResource() << " (" << tile.getNumber() << ") ";
    return outs;
}

// <
bool operator < (const Tile &lhs, const Tile &rhs) {
    return lhs.fNumber < rhs.fNumber;
}

// ==
bool operator == (const Tile &lhs, const Tile &rhs) {
    return lhs.fNumber == rhs.fNumber;
}