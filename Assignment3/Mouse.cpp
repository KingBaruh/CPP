//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "Mouse.h"

Mouse::Mouse(int price, const string& manufacturer, const string& color, bool is_wireless, int dpi)
	:PeripheralDevice(price, manufacturer, color, is_wireless), dpi(dpi) {}

// Setter function to update the DPI of the mouse
void Mouse::setDpi(int dpi)
{
	this->dpi = dpi;
}

// Getter function to retrieve the DPI of the mouse
int Mouse::getDpi() const
{
	return dpi;
}

// Conversion operator to convert the mouse keyboard to a string representation
Mouse::operator string() const
{
	// Combine the peripheral device info with mouse-specific info to create a descriptive string
	return PeripheralDevice::operator string() + ", Mouse with dpi : " + std::to_string(dpi);
}

void Mouse::connect(const Computer& computer)const
{
	// Print a message indicating that a mouse is connecting
	std::cout << "Connecting a mouse" << std::endl;

	// Call the parent class connect function to complete the connection
	PeripheralDevice::connect(computer);
}