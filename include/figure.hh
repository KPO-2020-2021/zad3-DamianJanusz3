#pragma once

#include "size.hh"
#include "matrix.hh"
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

    bool  operator == ( Figure m);

    Figure move ( Vector move1);

    Figure rotate (Matrix m , int amount);

    void showlength (Figure rectangle, std::ostream& strmo) const;

    void read( std::istream& strmi, std::ostream& strmo);



    

    
};



std::ostream &operator << (std::ostream &out, Figure const &tmp);

