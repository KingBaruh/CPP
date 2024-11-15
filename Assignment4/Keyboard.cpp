#include "Keyboard.h"

Keyboard::Keyboard(int price, const string& manufacturer, const string& color, bool is_wireless, int numberOfKeys)
	: Item(price, manufacturer),PeripheralDevice(price, manufacturer, color, is_wireless), numberOfKeys(numberOfKeys) {}

// Setter function to update the number of keys on the keyboard
void Keyboard::setNumberOfKeys(int new_numberOfKeys)
{
	this->numberOfKeys = new_numberOfKeys;
}

// Getter function to retrieve the number of keys on the keyboard
int Keyboard::getNumberOfKeys() const
{
	return numberOfKeys;
}

// Conversion operator to convert the keyboard to a string representation
Keyboard::operator string() const
{
	// Combine the peripheral device info with keyboard-specific info to create a descriptive string
	return PeripheralDevice::operator string() + ", Keyboard with " + std::to_string(numberOfKeys) + " keys";
}

void Keyboard::connect(Computer& computer)
{
	// Print a message indicating that a keyboard is connecting
	std::cout << "Connecting a keyboard" << std::endl;

	// Call the parent class connect function to complete the connection
	PeripheralDevice::connect(computer);

	// Try to connect the keyboard to the computer, throwing an exception if connection fails
	tryConnect(computer);
}
