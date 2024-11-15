//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "MainOffice.h"

MainOffice::MainOffice()
{}

MainOffice::~MainOffice()
{
    // Clean up memory for each branch in the map
    for (auto& it : branches)
    {
        delete it.second;
    }
}

// Singleton pattern: Get the instance of the MainOffice class
MainOffice& MainOffice::getInstance()
{
    // Create a static instance of MainOffice
    static MainOffice instance;

    // Return the instance
    return instance;
}

// Add a branch to the main office
void MainOffice::addBranch(const string& location, int capacity)
{
    // Try to insert a new branch into the map
    auto result = branches.try_emplace(location, new Branch(location, capacity));
    if (!result.second)
    {
        throw ExistingBranchInsertError(); // Throw an error if the branch already exists
    }
}

// Remove a branch from the main office
void MainOffice::removeBranch(const string& location)
{
    // Find the branch with the given location
    map<string, Branch*>::iterator it = branches.find(location);
    if (it != branches.end())
    {
        // Delete the branch and remove it from the map
        delete it->second;
        branches.erase(it);
        return;
    }
    throw NonExistingBranchRemoveError(); // Throw an error if the branch doesn't exist
}

// Get a reference to a branch from the main office
Branch& MainOffice::getBranch(const string& location) const
{
    // Find the branch with the given location
    auto it = branches.find(location);
    if (it != branches.end())
    {
        return (*it->second); // Return a reference to the found branch
    }
    throw NonExistingBranchRetrieveError(); // Throw an error if the branch doesn't exist
}

// Print branches sorted by value using a function pointer
void MainOffice::printBranchesByValue(void (*functionPointer)(const Branch& branch)) const
{
    // Create a vector to store pairs of branch location and Branch* pointers
    vector<Branch*> sortedBranches;

    // Populate the sortedBranches vector with pairs of location and branch pointers
    for (auto& pair : branches)
    {
        sortedBranches.push_back(pair.second);
    }

    // Sort the sortedBranches vector based on the branch values using the valueSort comparator
    std::sort(sortedBranches.begin(), sortedBranches.end(), Branch::valueSort);

    // Print the header indicating the number of branches
    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;

    // Print the main office branches directly
    for (auto& branch : sortedBranches)
    {
        std::cout << branch->getLocation() << " : Item count: " << std::to_string(branch->getCatalog().size()) << ", Total Value: " << std::to_string(branch->getValueOfBranch()) << std::endl;
        functionPointer(*branch); // Call the provided function on each branch
    }
}

// Print branches sorted by location using a function pointer
void MainOffice::printBranchesByLocation(void (*functionPointer)(const Branch& branch)) const
{
    // Print the header indicating the number of branches
    std::cout << "There are " << branches.size() << " branches in Main Office: " << std::endl;

    // Print the main office branches directly
    for (auto& pair : branches)
    {
        Branch& branch = *pair.second;
        std::cout << pair.first << " : Item count: " << std::to_string(branch.getCatalog().size()) << ", Total Value: " << std::to_string(branch.getValueOfBranch()) << std::endl;
        functionPointer(branch); // Call the provided function on each branch
    }
}
