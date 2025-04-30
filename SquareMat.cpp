// noashalom5@gmail.com

#include <stdexcept> 
#include <sstream>
#include <cmath>
#include "SquareMat.hpp"

using namespace std;
namespace mat {
    SquareMat::SquareMat()
    {
        cout << "Please enter size of Square Matrix: ";
        cin >> size;
        if (cin.fail() || size<=0) {
            throw invalid_argument("Error: size must be a positive integer.");
        }

        matrix = new double*[size];
        for (int i=0 ; i<size ; i++) {
            matrix[i] = new double[size];
        }
        cin.ignore();

        // Enter values
        cout << "Enter " << size << " real numbers in each row, separated by space.";
        for (int i=0 ; i<size ; i++) {
            string line;
            getline(cin, line);
            istringstream s(line);
            double number;
            int count = 0;
            while (s >> number) {
                if(count > size) 
                    throw runtime_error("Error: too many values in row " + to_string(i+1));
                matrix[i][count] = number;
                count++;
            }
            if(count < size)
                throw runtime_error("Error: row " + to_string(i+1) + " must contain exactly " + to_string(size) + " values.");
        }
    }

    SquareMat::SquareMat(int sizeMat)
    {
        size = sizeMat;
        matrix = new double*[size];
        for (int i=0 ; i<size ; i++) {
            matrix[i] = new double[size];
        }

        // Identity matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j)
                    matrix[i][j] = 1.0; 
                else
                    matrix[i][j] = 0.0;
            }
        }
    }

    SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
        matrix = new double*[size];
        for (int i=0 ; i<size ; i++) {
            matrix[i] = new double[size];
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    SquareMat::~SquareMat() {
        for (int i=0 ; i<size ; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    double* SquareMat::operator[](int row) {
        if (row<0 || row>=size) {
            throw out_of_range("Error: index out of bounds");
        }
        return matrix[row];
    }
    
    const double* SquareMat::operator[](int row) const {
        if (row<0 || row>=size) {
            throw out_of_range("Error: index out of bounds");
        }
        return matrix[row];
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this == &other) return *this;

        for (int i=0 ; i<size ; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        size = other.size;
        matrix = new double*[size];
        for (int i=0 ; i<size ; i++) {
            matrix[i] = new double[size];
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (size != other.size) {
            throw invalid_argument("Error: can't do the addition. The matrixs are not in the same size.");
        }
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator+(const SquareMat& other) const {
        SquareMat result(*this);
        result += other;
        return result;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size) {
            throw invalid_argument("Error: can't do the subtraction. The matrixs are not in the same size.");
        }
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator-(const SquareMat& other) const{
        SquareMat result(*this);
        result -= other;
        return result;
    }

    SquareMat& SquareMat::operator*=(double scalar) {
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (size != other.size) {
            throw invalid_argument("Error: can't do the multiplication. The matrixs are not in the same size.");
        }
        double** result = new double*[size];
        for(int i=0 ; i<size ; i++)
            result[i] = new double[size];

        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                result[i][j] = 0;
                for(int k=0 ; k<size ; k++) {
                    result[i][j] += matrix[i][k]*other.matrix[k][j];
                }
            }
        }

        for(int i=0 ; i<size ; i++)
            delete[] matrix[i];
        delete[] matrix;
        matrix = result;
        return *this;
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const {
        SquareMat result(*this);
        result *= other;
        return result;
    }

    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result(*this);
        result *= scalar;
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat& mat) {
        SquareMat result(mat);
        result *= scalar;
        return result;
    }

    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (size != other.size) {
            throw invalid_argument("Error: can't do the multiplication. The matrixs are not in the same size.");
        }
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] *= other.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMat& SquareMat::operator%=(double scalar) {
        if (scalar == 0) {
            throw invalid_argument("Error: can't do modulo by zero.");
        }
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] = fmod(matrix[i][j], scalar);
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator%(const SquareMat& other) const {
        SquareMat result(*this);
        result %= other;
        return result;
    }

    SquareMat SquareMat::operator%(double scalar) const {
        SquareMat result(*this);
        result %= scalar;
        return result;
    }

    SquareMat& SquareMat::operator/=(double scalar) {
        if (scalar == 0) {
            throw invalid_argument("Error: can't do division by zero.");
        }
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] = matrix[i][j]/scalar;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator/(double scalar) const{
        SquareMat result(*this);
        result /= scalar;
        return result;
    }

    double SquareMat::sumOfMatrix() const {
        double sumMat = 0.0;
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                sumMat += matrix[i][j];
            }
        }
        return sumMat;
    }

    bool SquareMat::operator<=(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1 <= sumMat2)
            return true;
        return false;
    }

    bool SquareMat::operator>=(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1 >= sumMat2)
            return true;
        return false;
    }

    bool SquareMat::operator==(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1 == sumMat2)
            return true;
        return false;
    }

    bool SquareMat::operator!=(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1 != sumMat2)
            return true;
        return false;
    }

    bool SquareMat::operator<(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1<=sumMat2 && sumMat1!=sumMat2)
            return true;
        return false;
    }

    bool SquareMat::operator>(const SquareMat& other) {
        double sumMat1 = (*this).sumOfMatrix();
        double sumMat2 = other.sumOfMatrix();
        if(sumMat1>=sumMat2 && sumMat1!=sumMat2)
            return true;
        return false;
    }

    SquareMat& SquareMat::operator++() { // ++A
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] += 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator++(int) { // A++
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    SquareMat& SquareMat::operator--() { // --A
        for(int i=0 ; i<size ; i++) {
            for (int j=0 ; j<size ; j++) {
                matrix[i][j] -= 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator--(int) { // A--
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat result(*this);
        for(int i=0 ; i<result.size ; i++) {
            for (int j=0 ; j<result.size; j++) {
                result.matrix[i][j] = -result.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator~() const {
        SquareMat result(*this);
        for(int i=0 ; i<result.size ; i++) {
            for (int j=0 ; j<result.size; j++) {
                result.matrix[i][j] = matrix[j][i];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) {
            throw invalid_argument("Error: the power must be positive.");
        }
        SquareMat result((*this).size); // Identity matrix
        SquareMat originalMat(*this);
        while(power > 0) {
            if((power%2) == 1)
                result *= originalMat;
            originalMat *= originalMat;
            power /= 2;
        }
        return result;
    }

    double SquareMat::operator!() const {
        if(size == 1)
            return matrix[0][0];
        if(size == 2)
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        
        double det = 0.0;

        // Do the minor matrix (remove the first line and the 'delCol' column)
        for(int delCol=0 ; delCol<size ; delCol++) {
            SquareMat minor(size-1);
            for(int i=1 ; i<size ; i++) {
                int mincol = 0;
                for(int j=0 ; j<size ; j++) {
                    if(j == delCol)
                        continue;
                    minor.matrix[i-1][mincol] = matrix[i][j];
                    mincol++;
                }
            }
            double sign = (delCol%2 == 0) ? 1.0 : -1.0;
            det += sign*matrix[0][delCol]*(!minor); // Recursive
        }
        return det;
    }

    ostream& operator<<(ostream& os, const SquareMat& mat) {
        for(int i=0 ; i<mat.size ; i++) {
            for(int j=0 ; j<mat.size ; j++) {
                os << mat.matrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
}