#pragma once
#define MAX_SHOPS_NUMBER 10
#include "Shop.h"

class Company
{
private:

	string name;
	Shop shops[MAX_SHOPS_NUMBER];
	int shopsNumber;

	bool isValidString(const string& str) const; // Check if input string is too long (more than 10 characters)
	void printShops() const; // Print details of all the shops
	void swap(Shop& shop1,Shop& shop2); // Swap two Shop objects

	//sorting funcions
	void sortByDay(); // Sort the shops by closed day
	void sortByName(); // Sort the shops by name
	
public:

	//C'tor
	Company();
	Company(const string& name);

	//getters
	string getName() const;
	int getShopsNumber() const;
	Shop* getShops(); 

	//setters
	void setName(const string& new_name);
	void addShop(const Shop& new_shop);
	
	//print funcions
	void printShopsByName(); // Print the company's shops sorted by name
	void printShopsByDay(); // Print the company's shops sorted by closed day

};
