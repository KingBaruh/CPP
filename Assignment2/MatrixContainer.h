#pragma once
#include "Matrix.h"

template<int rows, int cols, typename T = int>
class MatrixContainer 
{
    Matrix<rows, cols, T>* arr;     // Pointer to an array of Matrix objects
    int length;                     // The current capacity of the array 
    int usedCells;                  // The number of Matrix objects currently stored in the container

    // Create a new container by copying elements from another container
    void createContainer(const MatrixContainer<rows, cols, T>& other)
    {
        arr = new Matrix<rows, cols, T>[length]; // Allocate memory for the new array to hold Matrix objects

        // Copy elements from the other container to this container
        for (int i = 0; i < usedCells; i++)
        {
            arr[i] = other.arr[i]; // Copy Matrix object at index i from the other container
        }
    }

    // Method to reallocate memory for the array with a new capacity
    void reallocateArray(const int newCapacity)
    {
        Matrix<rows, cols, T>* newArr = new Matrix<rows, cols, T>[newCapacity]; // Create a new array with double the size

        for (int i = 0; i < usedCells; i++)//usedCells < newCapacity 
        {
            newArr[i] = arr[i]; // Copy the existing Matrix objects to the new array
        }
        length = newCapacity; // Update the capacity
        delete[] arr; // Delete the old array
        arr = newArr; // Point arr to the new array  
    }

    // Helper function to double the size of the array when it becomes full
    void doubleSize() 
    {
        int newCapacity = length * 2; // Calculate the new capacity, which is double the current length
        reallocateArray(newCapacity); // Call reallocateArray to perform the resizing
    }
    
    // Helper function to halve the size of the array when it is less than 1/4 full
    void divideSize() 
    { 
        int newCapacity = length / 2; // Calculate the new capacity, which is half the current length
        reallocateArray(newCapacity); // Call reallocateArray to perform the resizing
    }
    
public:
    // Constructor: Initialize the MatrixContainer with an array of length 1
    MatrixContainer() : length(1), usedCells(0), arr(new Matrix<rows, cols, T>[1])
    {}

    // Destructor: Clean up the dynamically allocated array
    ~MatrixContainer()
    {
        delete[] arr;
    }
    
    // Copy constructor - MatrixContainer to MatrixContainer
    MatrixContainer(const MatrixContainer<rows, cols, T>& other) : length(other.length),usedCells(other.usedCells)
    {
        createContainer(other); // Create a new container by copying elements from the other container
    }

    // Operator=(assignment operator):
    MatrixContainer <rows, cols, T>& operator=(const MatrixContainer <rows, cols, T>& other)
    {
        if (this != &other) // Check for self-assignment
        {
            usedCells = other.usedCells; // Copy the number of used cells from the other container
            length = other.length; // Copy the length of the array from the other container
            delete[]arr; // Deallocate memory for the current array
             
            createContainer(other); // Create a new container by copying elements from the other container
        }
        return *this; // Return a reference to the updated container
    }

    // Add a Matrix object to the container
    void addMatrix(const Matrix<rows, cols, T>& matrix)
    {
        if (usedCells >= length)
        {
            doubleSize(); // If the array is full, double its size
        }
        arr[usedCells] = matrix; // Add the matrix to the container
        usedCells++; // Increment the count of stored matrices
    }

    // Remove the last Matrix object from the container
    void removeLastMatrix()
    {
         usedCells--; // Decrement the count of stored matrices

         if (usedCells * 4 <= length)
         { 
            divideSize(); // If the array is less than 1/4 full, halve its size
         }
    }

    // Access operator to get the Matrix object at the specified index
    Matrix<rows, cols, T>& operator[](int index) const
    {
        return arr[index];
    }

    // Friend function to overload the << operator for outputting the container
    friend ostream& operator<<(ostream& out, const MatrixContainer<rows, cols, T>& container) 
    {
        out << "There are " << container.usedCells << " matrices in the container. The matrices:" << endl;
        for (int i = 0; i < container.usedCells; i++)
        {
            out << container[i] << endl;
        }
        return out;
    }

    // Get the number of Matrix objects stored in the container
    int size() const
    {
        return usedCells;
    }

    // Get the current capacity of the container (the length of the array)
    int capacity() const
    {
        return length;
    }
};