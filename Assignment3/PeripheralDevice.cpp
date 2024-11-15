//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "PeripheralDevice.h"

// Constructor that initializes a peripheral device with its price, manufacturer, color, and wireless status
PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless)
	:Item(price, manufacturer), color(color), isWireless(isWireless) {}

// Setter function to update the wireless status of the peripheral device
void PeripheralDevice::setIsWireless(bool isWireless)
{
	this->isWireless = isWireless;
}

// Getter function to retrieve the wireless status of the peripheral device
bool PeripheralDevice::getIsWireless()const
{
	return isWireless;
}

// Setter function to update the color of the peripheral device
void PeripheralDevice::setColor(const string& color)
{
	this->color = color;
}

// Getter function to retrieve the color of the peripheral device
const string& PeripheralDevice::getColor()const
{
	return color;
}

// Connect the peripheral device to the computer and print the details
void PeripheralDevice::connect(const Computer& computer) const 
{
    std::cout << string(*this) << " is connecting to computer: " << string(computer) << std::endl;
}

// Conversion operator to convert the peripheral device to a string representation
PeripheralDevice::operator string() const 
{
    // Determine if the peripheral device is wireless or wired
    string output = isWireless ? "Wireless" : "Wired";

    // Call the parent class operator to get the basic item info and add peripheral device-specific info
    return Item::operator string() + ", " + output + ", " + color;
}