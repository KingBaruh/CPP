#pragma once
#include "Manager.h"

enum Day 
{
	Sunday = 0, Monday, Tuesday,
	Wednesday, Thursday, Friday,
	Saturday
};

class Shop
{
private:

	Manager manager;
	string name;
	Day closedDay;
	bool isOnline;

	bool isValidString(const string& str) const ; // Check if input string is too long (more than 10 characters)
	string getClosedDayString() const; // Convert the Day enumeration to a string representation

public:

	//C'tor
	Shop();
	Shop(const Manager& manager,const string& name, Day closedDay, bool isOnline);

	//getters
	Manager getManager() const; 
	string getName() const;
	Day getClosedDay() const;
	bool getIsOnline() const;

	//setters
	void setManager(const Manager& new_manager);
	void setName(const string& new_name);
	void setClosedDay(const Day& closedDay);
	void setIsOnline(const bool& isOnline);

	//print
	void print() const;

};
