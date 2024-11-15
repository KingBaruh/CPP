#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

// Constructor that initializes a computer with its price, manufacturer, CPU, and laptop status
Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop, int numOfPorts)
    : Item(price, manufacturer), cpu(cpu), isALaptop(isALaptop), numOfPorts(numOfPorts) {}

// Destructor to clean up memory and disconnect all connected devices
Computer::~Computer()
{
    // Disconnect all connected devices to avoid memory leaks

    /*int length = int(connectedDevices.size());
    list<PeripheralDevice*>::iterator it = connectedDevices.begin();
    for (int i = 0; i < length; i++)
    {
        (*(it++))->disconnect();
    }*/

    while (!connectedDevices.empty())
    {
        connectedDevices.front()->disconnect();
        //(*(connectedDevices.begin()))->disconnect();
    }
}

// Setter for the CPU specification of the computer
void Computer::setCpu(const string& new_cpu) {
    cpu = new_cpu;
}

// Getter for the CPU specification of the computer
const string& Computer::getCpu() const {
    return cpu;
}

// Getter for the laptop status of the computer
bool Computer::getIsAlaptop() const {
    return isALaptop;
}

// Setter for the laptop status of the computer
void Computer::setIsAlaptop(bool new_status)
{
    isALaptop = new_status;
}

// Conversion operator to convert the computer to a string representation
Computer::operator string() const {
    // Determine if the computer is a laptop or desktop
    string output = isALaptop ? "Laptop" : "Desktop";

    // Call the parent class operator to get the basic item info and add computer-specific info
    return Item::operator string() + ", " + output + ", " + cpu;
}

// Connect a peripheral device to the computer
// Returns true if the connection is successful, false if prevented due to self-connection
void Computer::connectDevice(PeripheralDevice* device)
{
    // Check if the number of connected devices has reached the limit
    if (connectedDevices.size() == numOfPorts)
    {
        throw ConnectError();
    }

    // Check for duplicate connections of the same type
    for (PeripheralDevice* temp : connectedDevices)
    {
        if (typeid(*temp) == typeid(*device))
        {
            throw ConnectError();
        }
    }

    // Add the device to the list of connected devices
    connectedDevices.push_back(device);
}

// Disconnect a peripheral device from the computer
void Computer::disconnectDevice(PeripheralDevice* device)
{
    connectedDevices.remove(device);
}

// Print details of all connected devices
void Computer::printConnected() const
{
    std::cout << "There are " << connectedDevices.size() << " connections to " << string(*this) << std::endl;
    for (PeripheralDevice* device : connectedDevices)
    {
        std::cout << string(*device) << std::endl;
    }
}
