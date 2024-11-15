//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "PeripheralDevice.h"

class Mouse : public PeripheralDevice
{
private:
    int dpi;  // DPI (dots per inch) specification of the mouse

public:
    // Constructor that initializes a mouse with its price, manufacturer, color, wireless status, and DPI
    Mouse(int price, const string& manufacturer, const string& color, bool is_wireless, int dpi);

    // Setter for the DPI specification of the mouse
    void setDpi(int dpi);

    // Getter for the DPI specification of the mouse
    int getDpi() const;

    // Connect function specific to a mouse, to be implemented
    void connect(const Computer& computer) const;

    // Conversion operator to convert the mouse to a string representation
    operator string() const;
};
