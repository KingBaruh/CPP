#include "Item.h"

int Item::lastId = FIRST_ID;  // Initialize the static variable for IDs

// Constructor that initializes an item with its price, manufacturer, and a unique ID
Item::Item(int price, const string& manufacturer)
    : price(price), manufacturer(manufacturer), id(lastId++)
{}

// Destructor to clean up an item instance
Item::~Item()
{
    std::cout << "Throwing away an item" << std::endl;
}

// Getter for the price of the item
int Item::getPrice() const
{
    return price;
}

// Setter for the price of the item
void Item::setPrice(int newPrice)
{
    price = newPrice;
}

// Getter for the manufacturer of the item
const string& Item::getManufacturer() const
{
    return manufacturer;
}

// Setter for the manufacturer of the item
void Item::setManufacturer(const string& newManufacturer)
{
    manufacturer = newManufacturer;
}

// Getter for the unique ID of the item
int Item::getId() const
{
    return id;
}

// Conversion operator to convert the item to a string representation
Item::operator string() const
{
    return "id " + std::to_string(id) + ": " + manufacturer + ", " + std::to_string(price) + "$";
}

// Static function to compare two item pointers for sorting
bool Item::itemPtrCompare(Item* const& first, Item* const& second)
{
    return (first->id < second->id);
}
