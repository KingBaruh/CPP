//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "Branch.h"

// Constructor that initializes the branch with a location and capacity
Branch::Branch(const string& location, int capacity)
    : location(location), capacity(capacity)
{}

// Copy constructor for creating a copy of a branch
Branch::Branch(const Branch& other)
    : location(other.location), capacity(other.capacity)
{}

// Destructor to clean up memory when the branch is destroyed
Branch::~Branch()
{
    // Delete each item in the catalog
    for (int i = 0; i < catalog.size(); i++)
    {
        delete catalog[i];
    }
}

// Getter for location
const string& Branch::getLocation() const
{
    return location;
}

// Getter for catalog
vector<Item*> Branch::getCatalog() const
{
    return catalog;
}

// Add an item to the catalog, managing the circular buffer for a full catalog
void Branch::addItem(Item* itemPtr)
{
    if (capacity == catalog.size())
    {
        throw FullCatalogError();
    }

    // Check if the item is already in the catalog
    vector<Item*>::iterator ptr = std::find(catalog.begin(), catalog.end(), itemPtr);
    if (ptr != catalog.end())
    {
        throw ExistingItemError();
    }

    catalog.push_back(itemPtr);

    // If the catalog size exceeds the capacity, resize the catalog to the capacity
    if (catalog.capacity() > capacity)
    {
        catalog.reserve(capacity);
    }
}

// Remove an item from the catalog by its ID
Item* Branch::removeItem(int id)
{
    vector<Item*>::iterator ptr;
    for (ptr = catalog.begin(); ptr != catalog.end(); ++ptr)
    {
        if ((*ptr)->getId() == id)
        {
            Item* returnVal = (*ptr);
            catalog.erase(ptr);
            return returnVal;
        }
    }
    throw NonExistingItemError();
}

// Calculate and return the total value of all items in the branch's catalog
int Branch::getValueOfBranch() const
{
    int result = 0;
    for (Item* item : catalog)
    {
        result += item->getPrice();
    }
    return result;
}

bool Branch::valueSort(const Branch* a,const Branch* b)
{
    // Compare branches by value
    if (a->getValueOfBranch() == b->getValueOfBranch())
    {
        // If values are equal, compare branches by location alphabetically
        return a->getLocation() < b->getLocation();
    }
    // If values are different, use value comparison for sorting
    return a->getValueOfBranch() < b->getValueOfBranch();
}
