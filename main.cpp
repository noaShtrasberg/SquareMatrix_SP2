// main.cpp
#include "SquareMat.hpp"
#include <iostream>
using namespace std;
using namespace mat;

int main() {
    SquareMat A(2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    SquareMat B(2);
    B[0][0] = 5;
    B[0][1] = 6;
    B[1][0] = 7;
    B[1][1] = 8;

    SquareMat C(B);

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;
    cout << "Matrix C:\n" << C;

    // Addition
    cout << "\nA + B:\n" << (A + B);

    // Subtraction
    cout << "\nA - B:\n" << (A - B);

    // Scalar Multiplication
    cout << "\nA * 2:\n" << (A * 2);
    cout << "\n2 * A:\n" << (2 * A);

    // Matrix Multiplication
    cout << "\nA * B:\n" << (A * B);

    // Scalar Division
    cout << "\nA / 2:\n" << (A / 2);

    // Cell-wise multiplication (modulo-like)
    cout << "\nA % B (element-wise):\n" << (A % B);
    cout << "\nA % 2:\n" << (A % 2);

    // Unary Minus
    cout << "\n-A:\n" << (-A);

    // Transpose
    cout << "\n~B (Transpose):\n" << (~B);

    // Power
    cout << "\nB ^ 2:\n" << (B ^ 2);

    // Determinant
    cout << "\n!A (Determinant): " << !A << endl;

    // Comparisons
    cout << "\nA == B: " << (A == B) << endl;
    cout << "A != B: " << (A != B) << endl;
    cout << "A <= B: " << (A <= B) << endl;
    cout << "A >= B: " << (A >= B) << endl;
    cout << "A < B:  " << (A < B) << endl;
    cout << "A > B:  " << (A > B) << endl;

    // Increment and Decrement
    cout << "\n++A:\n" << (++A);
    cout << "\nA++:\n" << (A++); // Before increment
    cout << "\nA after A++:\n" << A;

    cout << "\n--A:\n" << (--A);
    cout << "\nA--:\n" << (A--); // Before decrement
    cout << "\nA after A--:\n" << A;

    return 0;
}