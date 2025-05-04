// noashalom5@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SquareMat.hpp"
#include "doctest.hpp"
#include <sstream>

using namespace std;
using namespace doctest;
using namespace mat;

TEST_CASE("Constructor with size") {
    SquareMat A(2);
    CHECK(A[0][0] == 1.0);
    CHECK(A[1][1] == 1.0);
    A[0][0] = 9;
    CHECK(A[0][0] == 9.0);
}

TEST_CASE("Copy constructor") {
    SquareMat A(3);
    A[0][0] = 5;
    A[1][2] = 39;
    SquareMat B(A);
    CHECK(B[0][0] == 5);
    CHECK(B[1][2] == 39);
}

TEST_CASE("Assignment operator") { // "="
    SquareMat A(3);
    A[1][2] = 5;
    SquareMat B(3);
    B[1][2] = 12;
    B = A;
    CHECK(B[1][2] == 5);
}

TEST_CASE("Addition operator") { // "Matrix += Matrix, Matrix + Matrix"
    SquareMat A(2);
    A[0][0] = 4;
    A[0][1] = 3;
    A[1][0] = 8;
    A[1][1] = 5;
    SquareMat B(2); // Identity matrix
    B += A;
    CHECK(B[0][0] == 5);
    CHECK(B[0][1] == 3);
    CHECK(B[1][0] == 8);
    CHECK(B[1][1] == 6);
    SquareMat C(2);
    C = A + B;
    CHECK(C[0][0] == 9);
    CHECK(C[0][1] == 6);
    CHECK(C[1][0] == 16);
    CHECK(C[1][1] == 11);
}

TEST_CASE("Subtraction operator") { // "Matrix -= Matrix, Matrix - Matrix"
    SquareMat A(2);
    A[0][0] = 8;
    A[0][1] = 5;
    A[1][0] = 12;
    A[1][1] = 7;
    SquareMat B(2); // Identity matrix
    B -= A;
    CHECK(B[0][0] == -7);
    CHECK(B[0][1] == -5);
    CHECK(B[1][0] == -12);
    CHECK(B[1][1] == -6);
    SquareMat C(2);
    C = A - B;
    CHECK(C[0][0] == 15);
    CHECK(C[0][1] == 10);
    CHECK(C[1][0] == 24);
    CHECK(C[1][1] == 13);
}

TEST_CASE("SquareMat multiplication with scalar") { // " Matrix *= scalar,  Matrix * scalar"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 4;
    A[1][0] = 2;
    A[1][1] = 2;
    A *= 3;
    CHECK(A[0][0] == 9);
    CHECK(A[0][1] == 12);
    CHECK(A[1][0] == 6);
    CHECK(A[1][1] == 6);
    A = A * 2;
    CHECK(A[0][0] == 18);
    CHECK(A[0][1] == 24);
    CHECK(A[1][0] == 12);
    CHECK(A[1][1] == 12);
}

TEST_CASE("SquareMat multiplication with scalar") { // " Scalar * Matrix"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 4;
    A[1][0] = 2;
    A[1][1] = 2;
    A = A * 5;
    CHECK(A[0][0] == 15);
    CHECK(A[0][1] == 20);
    CHECK(A[1][0] == 10);
    CHECK(A[1][1] == 10);
}

TEST_CASE("Matrix multiplication") { // "Matrix *= Matrix, Matrix * Matrix"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 4;
    A[1][0] = 2;
    A[1][1] = 2;
    SquareMat B(2);
    B[0][0] = 2;
    B[0][1] = 1;
    B[1][0] = 4;
    B[1][1] = -1;
    A *= B;
    CHECK(A[0][0] == 22);
    CHECK(A[0][1] == -1);
    CHECK(A[1][0] == 12);
    CHECK(A[1][1] == 0);
    SquareMat C(2); // Identity matrix
    A = B * C; // A = B;
    CHECK(A[0][0] == 2);
    CHECK(A[0][1] == 1);
    CHECK(A[1][0] == 4);
    CHECK(A[1][1] == -1);
}

TEST_CASE("Multiple every cell") { // "Matrix %= Matrix, Matrix % Matrix"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 4;
    A[1][0] = 2;
    A[1][1] = 2;
    SquareMat B(2);
    B[0][0] = 2;
    B[0][1] = 1;
    B[1][0] = 4;
    B[1][1] = -1;
    A %= B;
    CHECK(A[0][0] == 6);
    CHECK(A[0][1] == 4);
    CHECK(A[1][0] == 8);
    CHECK(A[1][1] == -2);
    SquareMat C(2); 
    C = A % B; 
    CHECK(C[0][0] == 12);
    CHECK(C[0][1] == 4);
    CHECK(C[1][0] == 32);
    CHECK(C[1][1] == 2);
}

TEST_CASE("Modulo with scalar") { // // "Matrix %= Scalar, Matrix % Scalar"
    SquareMat A(2);
    A[0][0] = 10;
    A[0][1] = 12;
    A[1][0] = 16;
    A[1][1] = 18;
    A %= 5;
    CHECK(A[0][0] == 0);
    CHECK(A[0][1] == 2);
    CHECK(A[1][0] == 1);
    CHECK(A[1][1] == 3);
    SquareMat B(2); 
    B = A % 2; 
    CHECK(B[0][0] == 0);
    CHECK(B[0][1] == 0);
    CHECK(B[1][0] == 1);
    CHECK(B[1][1] == 1);
}

TEST_CASE("Division by scalar") { // "Matrix /= Scalar, Matrix / Scalar"
    SquareMat A(2);
    A[0][0] = 18;
    A[0][1] = 15;
    A[1][0] = 39;
    A[1][1] = 30;
    A /= 3;
    CHECK(A[0][0] == 6);
    CHECK(A[0][1] == 5);
    CHECK(A[1][0] == 13);
    CHECK(A[1][1] == 10);
    SquareMat B(2); 
    B = A / 2; 
    CHECK(B[0][0] == 3);
    CHECK(B[0][1] == 2.5);
    CHECK(B[1][0] == 6.5);
    CHECK(B[1][1] == 5);
}

TEST_CASE("Sum of elements in matrix") { // sumOfMatrix
    SquareMat A(2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;
    double sum = A.sumOfMatrix();
    CHECK(sum == 10);
}

TEST_CASE("Comparison operator <=") { // "<="
    SquareMat A(2);
    A[0][0] = 9;
    A[0][1] = 5;
    A[1][0] = 20;
    A[1][1] = 6;
    SquareMat B(3); // Identity matrix
    B[0][0] = 3;
    B[0][1] = 4;
    SquareMat C(3); // Identity matrix
    CHECK_FALSE(A <= B); 
    CHECK(C <= B);
}

TEST_CASE("Comparison operator >=") { // ">="
    SquareMat A(2);
    A[0][0] = 9;
    A[0][1] = 5;
    A[1][0] = 20;
    A[1][1] = 6;
    SquareMat B(3); // Identity matrix
    B[0][0] = 3;
    B[0][1] = 4;
    SquareMat C(3); // Identity matrix
    CHECK_FALSE(C >= B); 
    CHECK(A >= B);
}

TEST_CASE("Comparison operator ==") { // "=="
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat B(3); // Identity matrix
    B[0][1] = 8;
    SquareMat C(3); // Identity matrix
    CHECK(A == B); 
    CHECK_FALSE(B == C);
}

TEST_CASE("Comparison operator !=") { // "!="
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat B(3); // Identity matrix
    B[0][1] = 8;
    SquareMat C(3); // Identity matrix
    CHECK(A != C); 
    CHECK_FALSE(A != B);
}

TEST_CASE("Comparison operator <") { // "<"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat B(3); // Identity matrix
    B[0][1] = 8;
    SquareMat C(3); // Identity matrix
    CHECK(C < A); 
    CHECK_FALSE(B < C);
}

TEST_CASE("Comparison operator <") { // ">"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat B(3); // Identity matrix
    B[0][1] = 8;
    SquareMat C(3); // Identity matrix
    CHECK_FALSE(C > A); 
    CHECK(B > C);
}

TEST_CASE("Increment operator (prefix)") { // "++A"
    SquareMat A(2);
    A[0][0] = 5;
    ++A;
    CHECK(A[0][0] == 6);
}

TEST_CASE("Increment operator (postfix)") { // "A++"
    SquareMat A(2);
    A[0][0] = 5;
    SquareMat plus = A++;
    CHECK(A[0][0] == 6);
    CHECK(plus[0][0] == 5);
}

TEST_CASE("SquareMat decrement operator (prefix)") { // "--A"
    SquareMat A(2);
    A[0][0] = 5;
    --A;
    CHECK(A[0][0] == 4);
}

TEST_CASE("SquareMat decrement operator (postfix)") { // "A--"
    SquareMat A(2);
    A[0][0] = 5;
    SquareMat minus = A--;
    CHECK(A[0][0] == 4);
    CHECK(minus[0][0] == 5);
}

TEST_CASE("Negation operator") { // Unary minus
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat result = -A;
    CHECK(result[0][0] == -3);
    CHECK(result[0][1] == -5);
    CHECK(result[1][0] == -2);
    CHECK(result[1][1] == -1);
}

TEST_CASE("Transpose operator") { // "~"
    SquareMat A(2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;
    SquareMat result = ~A;
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 3);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 4);
}

TEST_CASE("Power operator") { // "^"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    SquareMat result = A ^ 3;
    CHECK(result[0][0] == 97);
    CHECK(result[0][1] == 115);
    CHECK(result[1][0] == 46);
    CHECK(result[1][1] == 51);
}

TEST_CASE("Determinant operator") { // "!"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    double det = !A;
    CHECK(det == -7);  // 3*1 - 5*2 = -7
}

TEST_CASE("SquareMat ostream operator") { // "<<"
    SquareMat A(2);
    A[0][0] = 3;
    A[0][1] = 5;
    A[1][0] = 2;
    A[1][1] = 1;
    stringstream ss;
    ss << A;
    CHECK(ss.str() == "3 5 \n2 1 \n");
}
