//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

// Constructor that initializes a peripheral device with its price, manufacturer, color, and wireless status
PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless)
    : Item(price, manufacturer), color(color), isWireless(isWireless), connectedComputer(NULL)
{}

// Destructor to clean up any connections when the peripheral device is destroyed
PeripheralDevice::~PeripheralDevice()
{
    disconnect();
}

// Setter function to update the wireless status of the peripheral device
void PeripheralDevice::setIsWireless(bool new_isWireless)
{
    this->isWireless = new_isWireless;
}

// Getter function to retrieve the wireless status of the peripheral device
bool PeripheralDevice::getIsWireless() const
{
    return isWireless;
}

// Setter function to update the color of the peripheral device
void PeripheralDevice::setColor(const string& new_color)
{
    this->color = new_color;
}

// Getter function to retrieve the color of the peripheral device
const string& PeripheralDevice::getColor() const
{
    return color;
}

// Connect the peripheral device to the computer and print the details
void PeripheralDevice::connect(Computer& computer)
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

// Protected function for trying to connect the peripheral device to a computer
void PeripheralDevice::tryConnect(Computer& computer)
{
    // If the peripheral device is already connected to a computer, throw an error
    if (connectedComputer)
    {
        if (connectedComputer == &computer) // If the connectedComputer pointer is the same computer do nothing
            return;
        throw ConnectError();
    }
    // Try to connect the peripheral device to the computer
    computer.connectDevice(this);

    connectedComputer = &computer; // If successful, set the connected computer
    
}

// Disconnect the peripheral device from a computer
void PeripheralDevice::disconnect()
{
    // Check if the peripheral device is currently connected to a computer
    if (connectedComputer)
    {
        // Call the disconnectDevice function of the connected computer to remove the device
        connectedComputer->disconnectDevice(this);

        // Set the connectedComputer pointer to NULL to indicate disconnection
        connectedComputer = NULL;
    }
}
