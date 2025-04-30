// noashalom5@gmail.com

#include <iostream>
#include <iomanip>

using namespace std;
namespace mat {
class SquareMat {
private:
    int size;
    double** matrix;

public:
    SquareMat();
    SquareMat(int sizeMat); // Identity matrix - for the power
    SquareMat(const SquareMat& other); // Copy constructor
    ~SquareMat();

    // For matrix[i][j]:
    double* operator[](int row);
    const double* operator[](int row) const;

    SquareMat& operator=(const SquareMat& other); // Assignment operator
    SquareMat& operator+=(const SquareMat& other);
    SquareMat operator+(const SquareMat& other) const; // Matrix + Matrix
    SquareMat& operator-=(const SquareMat& other);
    SquareMat operator-(const SquareMat& other) const; // Matrix - Matrix

    SquareMat& operator*=(double scalar); // Matrix * Scalar
    SquareMat& operator*=(const SquareMat& other); // Matrix * Matrix
    SquareMat operator*(const SquareMat& other) const; // Matrix * Matrix
    SquareMat operator*(double scalar) const; // Matrix * Scalar
    friend SquareMat operator*(double scalar, const SquareMat& mat); // Scalar * Matrix

    SquareMat& operator%=(const SquareMat& other); // Multiple every cell
    SquareMat& operator%=(double scalar); // Matrix % Scalar
    SquareMat operator%(const SquareMat& other) const; // Multiple every cell
    SquareMat operator%(double scalar) const; // Matrix % Scalar

    SquareMat& operator/=(double scalar);
    SquareMat operator/(double scalar) const;
    double sumOfMatrix() const; // Helper function
    bool operator<=(const SquareMat& other);
    bool operator>=(const SquareMat& other);
    bool operator==(const SquareMat& other);
    bool operator!=(const SquareMat& other);
    bool operator<(const SquareMat& other);
    bool operator>(const SquareMat& other);

    SquareMat& operator++(); // ++Mat
    SquareMat operator++(int); // Mat++
    SquareMat& operator--(); // --Mat
    SquareMat operator--(int); // Mat--

    SquareMat operator-() const; // Unary minus
    SquareMat operator~() const; // Transpose
    SquareMat operator^(int power) const;
    double operator!() const; // Determinant
    friend ostream& operator<<(ostream& os, const SquareMat& mat); // Printing
};
}
