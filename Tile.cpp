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

Tile Tile::randomizeTile() {
    srand(time(NULL));
    Tile returnTile;
    int randomNumber;
    string randomResource = returnTile.randomizeResource();
    if (randomResource == "desert") {
        randomNumber = 7;
    } else {
        randomNumber = returnTile.randomizeNumber();
    }
    returnTile = Tile(randomNumber, randomResource);
    return returnTile;
}

int Tile::randomizeNumber() {
    srand(time(NULL));
    int returnNumber;
    int maxNumberRand = 19;
    vector<int> possibleNumbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    int randomNumberIndex = rand() % maxNumberRand;
    returnNumber = possibleNumbers[randomNumberIndex];
    return returnNumber;
}

string Tile::randomizeResource() {
    srand(time(NULL));
    string returnResource;
    int maxResourceRand = 20;
    vector<string> possibleResources = {"wood", "wood", "wood", "wood", "sheep", "sheep", "sheep", "sheep", "wheat", "wheat", "wheat", "wheat", "brick", "brick", "brick", "stone", "stone", "stone", "desert"};
    int randomResourceIndex = rand() % maxResourceRand;
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