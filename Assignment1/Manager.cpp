#include "Manager.h"

// C'tor
// Default constructor
Manager::Manager()
	:id(0), firstName("~"), lastName("~"), birthYear(0)
{}

// Parameterized constructor
Manager::Manager(int id,const string& firstName,const string& lastName, int birthYear)
	:id(id), birthYear(birthYear)
{
	setFirstName(firstName); // Set the first name of the manager using the setter method
	setLastName(lastName); // Set the last name of the manager using the setter method
}

//getters
int Manager::getId() const
{
	return id;
}
string Manager::getFirstName() const
{
	return firstName;
}
string Manager::getLastName() const
{
	return lastName;
}
int Manager::getBirthYear() const
{
	return birthYear;
}

//setters
void Manager::setId(const int& new_id)
{
	id = new_id;
}
void Manager::setFirstName(const string& new_name)
{ 
	if (isValidString(new_name))
	{
		firstName = new_name;  // Update the first name of the manager if it's valid (not too long)
	}
	else
	{
		cout << "Manager first name length is too long" << endl;
		firstName = "~";  // If the first name is too long, set a default value
	}
}
void Manager::setLastName(const string& new_lastName)
{
	if (isValidString(new_lastName))
	{
		lastName = new_lastName; // Update the last name of the manager if it's valid (not too long)
	}
	else
	{
		cout << "Manager last name length is too long" << endl;
		lastName = "~"; // If the last name is too long, set a default value
	}
}
void Manager::setBirthYear(const int& new_year)
{
	birthYear = new_year;
}

// Print function to display manager details
void Manager::print() const
{
	cout << "Printing manager: " << endl;
	cout << "Id : " << id << endl;
	cout << "First name : " << firstName << endl;
	cout << "Last name : " << lastName << endl;
	cout << "Birth year : " << birthYear << endl;
}

// Private function to check if the input string is too long (more than 10 characters)
bool Manager::isValidString(const string& str) const
{
	return str.length() <= MAX_NAME_LENGTH;
}
