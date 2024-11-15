// Student Baruh Riss, 318739174
// Student Baruh Krugliak, 211641956

#pragma once

#include "PeripheralDevice.h"
#include "Computer.h"

// Tablet is always wireless
// Tablet is always not a laptop (but also not a desktop!)
class Tablet : public PeripheralDevice, public Computer
{
    int screenSize;  // Size of the tablet's screen

public:
    // Constructor that initializes a Tablet with its price, manufacturer, color, CPU, number of ports, and screen size
    Tablet(int price, const string& manufacturer, const string& color, const string& cpu, int numOfPorts, int screenSize);

    // Getter for the screen size of the tablet
    int getScreenSize() const;

    // Setter for the screen size of the tablet
    void setScreenSize(int new_size);

    // Connect function to connect the tablet to a computer
    virtual void connect(Computer& computer);

    // Conversion operator to convert the tablet to a string representation
    operator string() const;

};
