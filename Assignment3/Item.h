#pragma once
#include <iostream>
#include <string>
#define FIRST_ID 1

using std::string;

class Item
{
private:
    int price;                 // Price of the item
    string manufacturer;       // Manufacturer of the item
    const int id;              // Unique ID of the item
    static int lastId;         // Static variable to keep track of the last assigned ID

public:
    // Constructor that initializes an item with its price and manufacturer
    Item(int price, const string& manufacturer);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Item();

    // Getter for the price of the item
    int getPrice() const;

    // Setter for the price of the item
    void setPrice(int newPrice);

    // Getter for the manufacturer of the item
    const string& getManufacturer() const;

    // Setter for the manufacturer of the item
    void setManufacturer(const string& newManufacturer);

    // Getter for the unique ID of the item
    int getId() const;

    // Virtual function to convert the item to a string representation
    virtual operator string() const = 0;
};
