//Student Baruh Riss, 318739174
//Student Baruh Krugliak, 211641956

#include "Computer.h"

// Constructor that initializes a computer with its price, manufacturer, CPU, and laptop status
Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isALaptop)
    : Item(price, manufacturer), cpu(cpu), isALaptop(isALaptop) {}

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

Computer::operator string() const {
    // Determine if the computer is a laptop or desktop
    string output = isALaptop ? "Laptop" : "Desktop";

    // Call the parent class operator to get the basic item info and add computer-specific info
    return Item::operator string() + "," + output + ", " + cpu;
}
