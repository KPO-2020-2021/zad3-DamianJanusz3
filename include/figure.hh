#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "vertices.hh"

class Figure {

private:
    Vector vertices [VERTICES];               // tablica wektorów wierzchołków
    double leng [VERTICES];
public:
    Figure(Vector [VERTICES]);            // Konstruktor klasy

    Figure(double tmp[VERTICES]);

    Figure();                               // Konstruktor klasy

    Figure length (Figure rect) ; //const

    const Vector &operator () (int index) const;

    Vector &operator () (int index);

    const double &operator [] (int index) const;

    double &operator[](int index);



    //Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    //Matrix operator + (Matrix tmp);

    //double  &operator () (unsigned int row, unsigned int column);
    
    //const double &operator () (unsigned int row, unsigned int column) const;

    //void make (double alfa);

    
};



std::ostream &operator << (std::ostream &out, Figure const &tmp);

