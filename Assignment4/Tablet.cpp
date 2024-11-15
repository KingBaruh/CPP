#include "Tablet.h"

// Constructor that initializes a Tablet with its price, manufacturer, color, CPU, number of ports, and screen size
Tablet::Tablet(int price, const string& manufacturer, const string& color, const string& cpu, int numOfPorts, int screenSize)
    : Item(price, manufacturer), PeripheralDevice(price, manufacturer, color, true),
    Computer(price, manufacturer, cpu, false, numOfPorts),
    screenSize(screenSize)
{}

// Conversion operator to convert the tablet to a string representation
Tablet::operator string() const
{
    return Item::operator string() + ", " + getColor() + ", " + getCpu() + ", Tablet with screen size: " + std::to_string(screenSize);
}

// Getter for the screen size of the tablet
int Tablet::getScreenSize() const
{
    return screenSize;
}

// Setter for the screen size of the tablet
void Tablet::setScreenSize(int new_size)
{
    screenSize = new_size;
}

// Connect function to connect the tablet to a computer
void Tablet::connect(Computer& computer)
{
    // Print a message indicating that a tablet is connecting
    std::cout << "Connecting a tablet" << std::endl;

    // Call the parent class connect function to complete the connection
    PeripheralDevice::connect(computer);

    // Prevent self-connection
    // Check if the tablet and computer are the same object
    if (&computer == this)
    {
        throw ConnectError(); // Throw an exception since a tablet cannot connect to itself
    }

    // Try to connect the tablet to the computer, throwing an exception if connection fails
    tryConnect(computer);
}
