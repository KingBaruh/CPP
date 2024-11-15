//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#pragma once
#include "Item.h"

class Computer : public Item
{
private:
    string cpu;     // CPU specification of the computer
    bool isALaptop; // Indicates if the computer is a laptop

public:
    // Constructor that initializes a computer with its price, manufacturer, CPU, and laptop status
    Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop);

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
};
