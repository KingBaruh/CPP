//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "Computer.h"

class PeripheralDevice : public Item
{
private:
    string color;        // Color of the peripheral device
    bool isWireless;     // Indicates if the peripheral device is wireless

public:
    // Constructor that initializes a peripheral device with its price, manufacturer, color, and wireless status
    PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless);

    // Setter for the wireless status of the peripheral device
    void setIsWireless(bool isWireless);

    // Getter for the wireless status of the peripheral device
    bool getIsWireless() const;

    // Setter for the color of the peripheral device
    void setColor(const string& color);

    // Getter for the color of the peripheral device
    const string& getColor() const;

    // Connect function to be implemented by derived classes
    virtual void connect(const Computer& computer) const = 0;

    // Conversion operator to convert the peripheral device to a string representation
    virtual operator string() const = 0;
};