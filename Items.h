#ifndef PROJECT4_ITEMS_H
#define PROJECT4_ITEMS_H

#include <vector>
#include <ostream>

using namespace std;

template <typename Object>
class Items {
public:
    // Constructor
    // Requires: a vector
    // Modifies: list
    // Effects: initializes list field with given specified data
    Items(vector<Object> list) : list(list) {}

    // Overloaded << operator
    // Requires: ostream and items object
    // Modifies: nothing
    // Effects: prints out all objects held in list
    friend ostream& operator << (ostream& outs, const Items &items);

private:
    vector<Object> list;
};


#endif //PROJECT4_ITEMS_H
