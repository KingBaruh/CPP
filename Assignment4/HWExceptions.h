//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include <exception>
using std::exception;

class ExistingBranchInsertError : public exception
{
	const char* what() const throw()
	{
		return "Trying to add a branch with an already existing location";
	}
};
class NonExistingBranchRemoveError : public exception
{
	const char* what() const throw()
	{
		return "Trying to remove a branch with a non existing location";
	}
};
class NonExistingBranchRetrieveError : public exception
{
	const char* what() const throw()
	{
		return "Trying to retrieve a branch with a non existing location";
	}
};
class ExistingItemError : public exception
{
	const char* what() const throw()
	{
		return "Trying to add an item with an id already in the catalog";
	}
};
class FullCatalogError : public exception
{
	const char* what() const throw()
	{
		return "Trying to add an item to a full catalog";
	}
};
class NonExistingItemError : public exception
{
	const char* what() const throw()
	{
		return "Trying to remove an item with a non existing id";
	}
};
class NoneExistingItemTypeError : public exception
{
	const char* what() const throw()
	{
		return "Trying to get an item with a non existing type";
	}
};
class ConnectError : public exception
{
	const char* what() const throw()
	{
		return "Failed connection attempt";
	}
};