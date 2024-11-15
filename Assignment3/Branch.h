#pragma once
#include "Item.h"
#define STORE_SIZE 10
#define START_INDEX 0

class Branch
{
private:
    Item* catalog[STORE_SIZE];  // Array to store items in the catalog
    string location;            // Location of the branch
    int currSize;               // Current number of items in the catalog
    int oldestItemIndex;        // Index of the oldest item in the circular buffer

public:
    // Constructor that initializes the branch with a location
    Branch(const string& location);

    // Destructor to clean up memory when the branch is destroyed
    ~Branch();

    // Add an item to the catalog, managing the circular buffer for full catalog
    void addItem(Item* itemPtr);

    // Get the catalog of items and the number of items in the catalog
    Item* const* getCatalog(int& number) const;

    // Get the location of the branch
    const string& getLocation() const;

    // Set the location of the branch
    void setLocation(const string& newLocation);
};

