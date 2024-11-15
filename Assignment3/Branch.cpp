//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "Branch.h"

// Constructor that initializes the branch with a location
Branch::Branch(const string& location)
    : location(location), currSize(0), oldestItemIndex(0)
{
    // Initialize the catalog array with NULL pointers
    for (int i = 0; i < STORE_SIZE; i++)
    {
        catalog[i] = NULL;
    }
}

// Destructor to clean up memory when the branch is destroyed
Branch::~Branch()
{
    // Delete each item in the catalog
    for (int i = 0; i < currSize; i++)
    {
        delete catalog[i];
    }
}

// Getter for location
const string& Branch::getLocation() const
{
    return location;
}

// Setter for location
void Branch::setLocation(const string& newLocation)
{
    location = newLocation;
}

// Getter for catalog
Item* const* Branch::getCatalog(int& number) const
{
    number = currSize;
    return catalog;
}

// Add an item to the catalog, managing the circular buffer for full catalog
void Branch::addItem(Item* itemPtr)
{
    if (currSize < STORE_SIZE)
    {
        // If there's space in the catalog, add the item to the end
        catalog[currSize++] = itemPtr;
    }
    else
    {
        // If the catalog is full, replace the oldest item with the new item

        // Place the new item at the current oldestItemIndex
        catalog[oldestItemIndex] = itemPtr;

        // Move oldestItemIndex to the next position
        oldestItemIndex++;

        // Wrap around oldestItemIndex if it reaches the end of the catalog
        if (oldestItemIndex == STORE_SIZE)
        {
            oldestItemIndex = START_INDEX;
        }
    }
}
