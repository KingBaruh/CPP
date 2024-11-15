#pragma once
#include "Item.h"

class Computer; // Forward declaration of Computer class

class PeripheralDevice : virtual public Item
{
private:
    string color;                // Color of the peripheral device
    bool isWireless;             // Indicates if the peripheral device is wireless
    Computer* connectedComputer; // Pointer to the connected computer

protected:
    void tryConnect(Computer& computer); // Protected function for trying to connect

public:
    // Constructor that initializes a peripheral device with its price, manufacturer, color, and wireless status
    PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless);

    // Destructor to clean up any connections when the peripheral device is destroyed
    ~PeripheralDevice();

    // Setter for the wireless status of the peripheral device
    void setIsWireless(bool isWireless);

    // Getter for the wireless status of the peripheral device
    bool getIsWireless() const;

    // Setter for the color of the peripheral device
    void setColor(const string& color);

    // Getter for the color of the peripheral device
    const string& getColor() const;

    // Connect function to be implemented by derived classes
    virtual void connect(Computer& computer) = 0 ;

    // Conversion operator to convert the peripheral device to a string representation
    virtual operator string() const = 0 ;

    // Disconnect the peripheral device from a computer
    void disconnect();
};
