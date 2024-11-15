//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "Item.h"
#include <list>
#include "HWExceptions.h"

class PeripheralDevice;

using std::list;

class Computer :virtual public Item
{
public:

    // Constructor that initializes a computer with its price, manufacturer, CPU, and laptop status
    Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop, int numOfPorts);

    // Destructor to clean up memory and disconnect all connected devices
    ~Computer();

    // Conversion operator to convert the computer to a string representation
    virtual operator string() const;

    // Setter for the CPU specification of the computer
    void setCpu(const string& new_cpu);

    // Getter for the CPU specification of the computer
    const string& getCpu() const;

    // Getter for the laptop status of the computer
    bool getIsAlaptop() const;

    // Setter for the laptop status of the computer
    void setIsAlaptop(bool new_status);

    // Print details of all connected devices
    void printConnected() const;

    // Connect a peripheral device to the computer
    void connectDevice(PeripheralDevice* device);

    // Disconnect a peripheral device from the computer
    void disconnectDevice(PeripheralDevice* device);

private:

    string cpu;             // CPU specification of the computer
    bool isALaptop;         // Indicates if the computer is a laptop
    const int numOfPorts;   // Number of available ports
    list<PeripheralDevice*> connectedDevices; // List of connected peripheral devices
};
