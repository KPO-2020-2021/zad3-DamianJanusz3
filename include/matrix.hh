#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include<iomanip>

class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    void make (double alfa);

    Vector gaussdet (int n);

    Matrix operator * (Matrix m);

    
};

Matrix multiply (Matrix m, Matrix v, double amount );

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

