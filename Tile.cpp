// Sean Cosgrove, Molly Eaton, George Fafard and Gavin O'Sullivan
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

// Randomize Tile
Tile Tile::randomizeTile() {
    // variables
    Tile returnTile;
    int randomNumber;
    // call randomizeResource function
    string randomResource = returnTile.randomizeResource();
    // randomResource is desert
    if (randomResource == "desert") {
        randomNumber = 7; // set randomNumber to seven for robber
    // randomResource is not desert
    } else {
        // call randomizeNumber function
        randomNumber = returnTile.randomizeNumber();
    }
    // create Tile object with random fields and return
    returnTile = Tile(randomNumber, randomResource);
    return returnTile;
}

// Randomize Number
int Tile::randomizeNumber() {
    // initialize variables
    int returnNumber;
    vector<int> possibleNumbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    // use rand function to get random index value
    int randomNumberIndex = rand() % possibleNumbers.size();
    // get randomNumber from vector of possible values and return
    returnNumber = possibleNumbers[randomNumberIndex];
    return returnNumber;
}

// Randomize Resource
string Tile::randomizeResource() {
    // initialize variables
    string returnResource;
    vector<string> possibleResources = {"wood", "wood", "wood", "wood", "sheep", "sheep", "sheep", "sheep", "wheat", "wheat", "wheat", "wheat", "brick", "brick", "brick", "stone", "stone", "stone", "desert"};
    // use rand function to get random index value
    int randomResourceIndex = rand() % possibleResources.size();
    // get randomResource from vector of possible values and return
    returnResource = possibleResources[randomResourceIndex];
    return returnResource;
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
