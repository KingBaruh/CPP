#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<int rows, int cols, typename T=int>
class Matrix
{
	T** data;// Pointer to a dynamically allocated 2D array to hold the matrix data

	// allocate space for the two dimensional array
	void allocateMatrix()
	{
		data = new T* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new T[cols];
		}
	}

	// Copy other matrix to this->matrix
	void copyMatrix(const Matrix<rows, cols, T>& other)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->data[i][j] = other.data[i][j]; // Copy elements from the other matrix to this matrix
			}
		}
	}

public:

	// Default constructor - given value to matrix, default to 0
	Matrix(T initValue = 0)
	{
		allocateMatrix(); // Dynamically allocate memory for the matrix
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = initValue; // Initialize all elements of the matrix with the given value
			}
		}
	}

	// Copy constructor - Matrix to Matrix
	Matrix(const Matrix<rows, cols, T>& other)
	{
		allocateMatrix();  // Dynamically allocate memory for the new matrix
		copyMatrix(other); // Copy all contents of the other matrix to this
	}

	// Destructor, for manual de-allocation of memory
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i]; // Deallocate memory for each row of the matrix
		}
		delete[] data; // Deallocate memory for the array of rows
	}

	// Operator=(assignment operator): (matrix = otherMatrix)
	Matrix<rows, cols, T>& operator=(const Matrix<rows, cols, T>& other)
	{
		if (this != &other) // Avoid self-assignment
		{
			copyMatrix(other); //Copy all contents of the other matrix to this
		}
		return *this; // Return the current matrix after assignment
	}
	
	// Operator +				Matrix = Matrix + scalar
	Matrix<rows, cols, T>  operator+(T scalar) const
	{
		Matrix<rows, cols, T> resultMat(*this); // Create a copy of the current matrix
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				resultMat(i,j) += scalar; // Add the scalar value to each element of the matrix
			}
		}
		return resultMat; // Return the new matrix with the updated values
	}
	
	// Operator +(friend)		Matrix = scalar + Matrix
	friend Matrix<rows, cols, T> operator+(T scalar, const Matrix<rows, cols, T>& matrix)
	{
		return matrix + scalar; // Call the operator+ function with the scalar value and the matrix
	}
	
	// Operator +				Matrix = Matrix1 + Matrix2
	Matrix<rows, cols, T> operator+(const Matrix<rows, cols, T>& other) const
	{
		Matrix<rows, cols, T> resultMat(*this); // Create a copy of the current matrix
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				resultMat(i, j) += other(i,j); // Add corresponding elements of both matrices
			}
		}
		return resultMat; // Return the new matrix with the updated values
	}

	// Operator -				Matrix = Matrix - scalar
	Matrix<rows, cols, T>  operator-(T scalar) const
	{
		return (*this) + ((-1) * scalar); // Subtract the scalar value from each element using operator+
	}

	// Operator -(friend)		Matrix = scalar - Matrix
	friend Matrix<rows, cols, T>  operator-(T scalar, const Matrix<rows, cols, T>& matrix)
	{
		return -matrix + scalar;	// Subtract each element of the matrix from the scalar and negate the result
	}

	// operator -				Matrix = Matrix1 - Matrix2
	Matrix<rows, cols, T> operator-(const Matrix<rows, cols, T>& other) const
	{
		return this->operator+(other * T(-1)); // Subtract the other matrix from the current matrix using operator+
	}

	// operator -				Matrix = - Matrix
	friend Matrix<rows, cols, T> operator-(const Matrix<rows, cols, T>& matrix) {

		return matrix * T(-1); // Negate each element of the matrix using operator*
	}

	// Operator *				Matrix = Matrix * scalar
	Matrix<rows, cols, T>  operator*(T scalar) const
	{
		Matrix<rows, cols, T> resultMat(*this); // Create a copy of the current matrix
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				resultMat(i,j) *= scalar; // Multiply each element of the matrix by the scalar value
			}
		}
		return resultMat; // Return the new matrix with the updated values
	}

	// Operator *(friend)		Matrix = scalar * Matrix
	friend Matrix<rows, cols, T>  operator*(T scalar, const Matrix<rows, cols, T>& matrix) 
	{
		return matrix * scalar; // Call the operator* function with the scalar value and the matrix
	}

	// operator *				Matrix = Matrix1 * Matrix2
	Matrix<rows, cols, T> operator*(const Matrix<rows, cols, T>& other) const
	{
		Matrix<rows, cols, T> tempMat;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				for (int k = 0; k < cols; k++)
				{
					tempMat.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return tempMat;
	}

	// Prefix Operator ++	++Matrix
	Matrix<rows, cols, T>& operator++()
	{
		(*this) = (*this + T(1)); // Increment each element by 1 using operator+
		return (*this); // Return the updated matrix
	}

	// Postfix Operator ++	Matrix++
	Matrix<rows, cols, T> operator++(int)
	{
		Matrix<rows, cols, T> resultMat(*this); // Create a copy of the current matrix
		(*this) = (*this + T(1)); // Increment each element by 1 using operator+
		return resultMat; // Return the original matrix before the increment
	}

	// Prefix Operator --	--Matrix
	Matrix<rows, cols, T>& operator--()
	{
		(*this) = (*this - T(1)); // Decrement each element by 1 using operator-
		return (*this); // Return the updated matrix
	}

	// Postfix Operator --	Matrix--
	Matrix<rows, cols, T> operator--(int)
	{
		Matrix<rows, cols, T> resultMat(*this); // Create a copy of the current matrix
		(*this) = (*this - T(1)); // Decrement each element by 1 using operator-
		return resultMat; // Return the original matrix before the decrement
	}

	// Operator<< Outputs the matrix to an output stream (e.g., cout)
	friend ostream& operator<<(ostream& out, const Matrix<rows, cols, T>& matrix)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				out << matrix(i,j) << " "; // Output each element of the matrix
			}
			out << endl; // Move to the next row
		}
		return out; // Return the output stream
	}

	// Operator() Allows accessing the elements of the matrix using parentheses
	T& operator()(int i, int j) const
	{
		return data[i][j]; // Return a reference to the element at the specified row and column
	}

	// Operator== Allows comparing matrices for equality
	bool operator==(const Matrix<rows, cols, T>& other)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (std::abs(data[i][j] - other.data[i][j]) >= DBL_EPSILON) // Compare floating-point values with epsilon tolerance
				{
					return false; // Return false if any elements are different
				}
			}
		}
		return true; // Return true if all elements are equal within tolerance
	}

	// Operator!= Allows comparing matrices for inequality
	bool operator!=(const Matrix<rows, cols, T>& other)
	{
		if (this->operator==(other)) // Reuse the equality operator to check for inequality
		{
			return false;
		}
		return true;
	}
	
	// Conversion operator - Converts the matrix to a scalar value, representing the sum of its diagonal elements
	operator T() const
	{
		int number;
		T result = 0;
		T* diag = getDiag(number); // Get the main diagonal elements of the matrix
		for (int i = 0; i < number; ++i) 
		{
			result += diag[i]; // Sum up the diagonal elements
		}
		delete[] diag; // Deallocate memory used for the diagonal array
		return result; // Return the sum of the diagonal elements as the converted scalar value
	}
	
	// Return the identity matrix of exact same size 
	Matrix<rows, cols, T> getIdentityMatrix() const
	{
		Matrix<rows, cols, T> identityMatrix;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				identityMatrix.data[i][j] = ((i == j) ? 1 : 0); // Set 1 on the main diagonal, 0 elsewhere
			}
		}
		return identityMatrix; // Return the identity matrix
	}
	
	// Returning the matrix main diagonal
	T* getDiag(int& number) const
	{
		number = rows < cols ? rows : cols; // The number of diagonal elements is the minimum of rows and cols
		T* diag = new T[number]; // Allocate memory for the diagonal elements
		for (int i = 0; i < number; i++)
		{
			diag[i] = data[i][i]; // Copy the diagonal elements to the array
		}
		return diag; // Return the array of diagonal elements
	}
};
