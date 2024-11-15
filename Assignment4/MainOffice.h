//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "Branch.h"
#include <map>

using std::map;

class MainOffice
{
public:
    // Singleton pattern: Get the instance of the MainOffice class
    static MainOffice& getInstance();

    // Add a branch to the main office
    void addBranch(const string& location, int capacity);

    // Remove a branch from the main office
    void removeBranch(const string& location);

    // Get a reference to a branch from the main office
    Branch& getBranch(const string& location) const;

    // Print branches sorted by location using a function pointer
    void printBranchesByLocation(void (*functionPointer)(const Branch& branch)) const;

    // Print branches sorted by value using a function pointer
    void printBranchesByValue(void (*functionPointer)(const Branch& branch)) const;

private:
    map<string, Branch*> branches;  // Map of branch locations to their corresponding Branch objects

    // Constructor (private to enforce singleton pattern)
    MainOffice();

    // Destructor
    ~MainOffice();

    // Copy constructor and assignment operator disabled
    MainOffice(const MainOffice& other) = delete;
    MainOffice operator=(const MainOffice& other) = delete;

};
