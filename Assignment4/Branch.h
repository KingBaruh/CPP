//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "Item.h"

class Branch
{
private:

    vector<Item*> catalog;         // Catalog of items in the branch
    const string location;        // Location of the branch
    const int capacity;           // Capacity of the branch's catalog


public:
    // Constructor that initializes the branch with a location and capacity
    Branch(const string& location, int capacity);

    // Copy constructor for creating a copy of a branch
    Branch(const Branch& other);

    // Destructor to clean up memory when the branch is destroyed
    ~Branch();

    // Add an item to the catalog, managing the circular buffer for a full catalog
    void addItem(Item* itemPtr);

    // Get the catalog of items and the number of items in the catalog
    vector<Item*> getCatalog() const;

    // Get the location of the branch
    const string& getLocation() const;

    // Remove an item from the catalog by its ID
    Item* removeItem(int id);

    // Calculate and return the total value of all items in the branch's catalog
    int getValueOfBranch() const;

    // Find and return the finest item of a specific type in the catalog
    template<class T>
    T* giveMeFinest(T* itemType) const
    {
        T* max = NULL;
        for (Item* temp : catalog)
        {
            if (typeid(*temp) == typeid(*itemType))
            {
                if (!max)
                {
                    max = dynamic_cast<T*>(temp);
                }
                else if (temp->getPrice() > max->getPrice())
                {
                    max = dynamic_cast<T*>(temp);
                }
            }
        }
        if (!max)
        {
            throw NoneExistingItemTypeError();
        }
        return max;
    }

    static bool valueSort(const Branch* a,const Branch* b);
};
