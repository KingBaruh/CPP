//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice
{
private:
    int numberOfKeys;  // Number of keys on the keyboard

public:
    // Constructor that initializes a keyboard with its price, manufacturer, color, wireless status, and number of keys
    Keyboard(int price, const string& manufacturer, const string& color, bool is_wireless, int numberOfKeys);

    // Setter for the number of keys on the keyboard
    void setNumberOfKeys(int numberOfKeys);

    // Getter for the number of keys on the keyboard
    int getNumberOfKeys() const;

    // Connect function specific to a keyboard, to be implemented
    void connect(Computer& computer);

    // Conversion operator to convert the keyboard to a string representation
    operator string() const;
};