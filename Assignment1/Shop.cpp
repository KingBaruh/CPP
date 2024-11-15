//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "Shop.h"

//C'tor
// Default constructor
Shop::Shop() 
	:name("~"), closedDay(Sunday), isOnline(false)
{}

// Parameterized constructor
Shop::Shop(const Manager& manager,const string& name, Day closedDay, bool isOnline)
	:manager(manager),closedDay(closedDay),isOnline(isOnline)
{
	setName(name); // Set the name of the shop using the setter method
}

//getters
Manager Shop::getManager() const
{
	return manager;
}
string Shop::getName() const
{
	return name;
}
Day Shop::getClosedDay() const
{
	return closedDay;
}
bool Shop::getIsOnline() const
{
	return isOnline;
}

//setters
void Shop::setManager(const Manager& new_manager)
{
	manager = new_manager;
}
void Shop::setName(const string& new_name)
{
	if (isValidString(new_name))
	{
		this->name = new_name; // Update the name of the shop if it's valid (not too long)
	}
	else
	{
		cout << "Shop name length is too long" << endl;
		name = "~"; // If the name is too long, set a default value
	}
}
void Shop::setClosedDay(const Day& new_closedDay)
{
	this->closedDay = new_closedDay;
}
void Shop::setIsOnline(const bool& new_isOnline)
{
	this->isOnline = new_isOnline;
}

// Print function
void Shop::print() const
{ 
	cout << "Printing shop: " << endl;
	manager.print(); // Call the print function of the manager object to print manager details
	cout << "Name : " << name << endl;
	cout << "Closed day : " << getClosedDayString() << endl; // Convert and print the closed day as a string
	cout << "Is Online : ";
	if (isOnline) // Print whether the shop is online or not
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

// Private funcions
// Private function to check if the input string is too long (more than 10 characters)
bool Shop::isValidString(const string& str) const 
{
	return str.length() <= MAX_NAME_LENGTH;
}

// Private function to convert the Day enumeration to a string representation
string Shop::getClosedDayString() const
{
	switch (closedDay) 
	{
	case Sunday:
		return "Sunday";
	case Monday:
		return "Monday";
	case Tuesday:
		return "Tuesday";
	case Wednesday:
		return "Wednesday";
	case Thursday:
		return "Thursday";
	case Friday:
		return "Friday";
	case Saturday:
		return "Saturday";
	default:
		return "Invalid Day";
	}
}