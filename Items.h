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
    friend ostream& operator << (ostream& outs, const Items &items) {
        outs << "Items held in list vector: ";
        for (int i = 0; i < items.list.size(); i++) {
            if (i == 0) {
                outs << items.list.at(i);
            } else {
                outs << ", " << items.list.at(i);
            }
        }
        return outs;
    }

    // Requires: nothing
    // Modifies: list
    // Effects: sorts list of objects in ascending order of value
    void sort();

    // Requires: Object to search for in list
    // Modifies: nothing
    // Effects: Searches for specified item in list. return true if found and false otherwise
    bool find(Object object);

    // Randomization Methods
    // Requires: nothing
    // Modifies: list
    // Effects: randomizes order of objects in list
    void randomizeSC();
    void randomizeME();
    void randomizeGO();

private:
    vector<Object> list;
};


#endif //PROJECT4_ITEMS_H
