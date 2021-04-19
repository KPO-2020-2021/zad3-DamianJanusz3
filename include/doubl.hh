#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "vertices.hh"
#include "figure.hh"


class Doubl {

private:
    double len [VERTICES];
public:

    Doubl (double tmp[VERTICES]);   // Konstruktor klasy

    Doubl();                               // Konstruktor klasy

     bool  operator == (  Doubl m) ;

    //const Vector &operator () (int index) const;

    //Vector &operator () (int index);

    //const double &operator [] (int index) const;

    //double &operator[](int index);

};
//Doubl length (Figure rect) ;


