#include "Company.h"

//C'tor
// Default constructor
Company::Company()
	:name("~"), shopsNumber(0)
{}

// Parameterized constructor
Company::Company(const string& name)
	:shopsNumber(0)
{
	setName(name); // Set the name of the company using the setter method
}

//getters
string Company::getName() const
{
	return name;
}
int Company::getShopsNumber() const
{
	return shopsNumber;
}
Shop* Company::getShops()
{
	return shops;
}

//setters
void Company::setName(const string& new_name)
{
	if (isValidString(new_name))
	{
		this->name = new_name; // Update the name of the company if it's valid (not too long)
	}
	else
	{
		cout << "Company name length is too long" << endl;
		this->name = "~"; // If the name is too long, set a default value
	}
}
void Company::addShop(const Shop& new_shop)
{
	// Check if the Company is full. If so, we'll notify the user and will not add another shop
	if (shopsNumber >= MAX_SHOPS_NUMBER)
	{
		cout << "There is no place for new shops!" << endl;
	}
	else
	{
		// Add the new shop to the array of shops
		shops[shopsNumber] = new_shop;
		shopsNumber++;
	}
}

//Print functions
void Company::printShopsByName() 
{
	sortByName(); // Sort the shops by name
	printShops(); // Print the details of all the shops after sorting
}
void Company::printShopsByDay() 
{
	sortByDay(); // Sort the shops by closed day
	printShops(); // Print the details of all the shops after sorting
}


// Private function to check if the input string is too long (more than 10 characters)
bool Company::isValidString(const string& str) const
{
	return (str.length() <= MAX_NAME_LENGTH);
}

// Private function that Prints details of all the shops
void Company::printShops() const
{
	if (shopsNumber == 0)
	{
		cout << "There are no shops in this company." << endl;
	}
	else
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are : " << endl;
		for (int i = 0; i < shopsNumber; i++)
		{
			cout << "Shop #" << i+1 << " :" << endl;
			shops[i].print(); // Call the print function of each shop to print shop details
			cout << endl;
		}
	}
}

// Private function to swap two Shop objects
void Company::swap(Shop& shop1,Shop& shop2)
{
	Shop temp = shop1;
	shop1 = shop2;
	shop2 = temp;
}

// Private function to sort the shops by name using bubble sort
void Company::sortByName()
{
	for (int i = 0; i < shopsNumber - 1; i++)
	{
		for (int j = 0; j < shopsNumber - 1 - i; j++)
		{
			if (shops[j].getName() > shops[j + 1].getName())
			{
				swap(shops[j], shops[j + 1]);
			}
		}
	}
}

// Private function to sort the shops by closed day using bubble sort
void Company::sortByDay()
{
	for (int i = 0; i < shopsNumber - 1; i++)
	{
		for (int j = 0; j < shopsNumber - 1 - i; j++)
		{
			if (shops[j].getClosedDay() > shops[j + 1].getClosedDay())
			{
				swap(shops[j], shops[j + 1]);
			}
		}
	}
}

