#pragma once

#include <iostream>
#include <string> 
#define MAX_NAME_LENGTH 10

using std::cout;
using std::endl;
using std::string;

class Manager
{
private:

	int id;
	string firstName; //max 10 characters
	string lastName;  //max 10 characters
	int birthYear;

	bool isValidString(const string& str) const; // Check if input string is too long (more than 10 characters)


public:

	//C'tor	
	Manager();
	Manager(int id,const string& firstName,const string& lastName , int birthYear);

	//getters
	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	int getBirthYear() const;

	//setters
	void setId(const int& new_id);
	void setFirstName(const string& new_name);
	void setLastName(const string& new_lastName);
	void setBirthYear(const int& new_year);

	//print func
	void print() const;
};
