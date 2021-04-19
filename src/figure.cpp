#include "size.hh"
//#include "vector.hh"
//#include "matrix.hh"
//#include <math.h>
#include "figure.hh"
#include <iomanip>
#include <iostream>
#include <cstdlib>





/******************************************************************************
 |  Konstruktor klasy Figure.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablicę wektorów zerowych.                                            |
 *///
Figure::Figure() {
    double arg[]={0,0};
    for (int i = 0; i < VERTICES; ++i) {
        //for (int j = 0; j < SIZE; ++j) {
            vertices[i] = Vector(arg);
            //leng[i] = 0;
        //}
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Figure.                                   |
 |  Argumenty:                                                                |
 |      tmp - jednowymiarowa tablica z elementami typu vector.                |
 |  Zwraca:                                                                   |
 |      tablicę wypelniona wartosciami podanymi w argumencie.                 |
 */
Figure::Figure(Vector tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        //for (int j = 0; j < SIZE; ++j) {
            vertices[i] = tmp[i];
        //}
    }
}



/******************************************************************************
 |  Konstruktor parametryczny klasy Figure.                                   |
 |  Argumenty:                                                                |
 |      tmp - jednowymiarowa tablica z elementami typu vector.                |
 |  Zwraca:                                                                   |
 |      tablicę wypelniona wartosciami podanymi w argumencie.                 |
 */
Figure::Figure(double tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        //for (int j = 0; j < SIZE; ++j) {
            leng[i] = tmp[i];
        //}
    }
}



Figure Figure::length (Figure rect)  {
    Figure result;
    for (int i=0; i<VERTICES; ++i) {
        result.vertices[i]=this->vertices[i] ;
    }
    for (int i=0; i<VERTICES; ++i) {
        result.leng[i]= this->vertices[i] & this->vertices[i+1];
        
    }
    
   
    rect=rect;
    return result;
}




/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const Vector &Figure::operator () (int index) const {
    if (index < 0 || index >= VERTICES) {
        std::cerr << "Error: Figura? jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return vertices[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
Vector &Figure::operator () (int index) {
    return const_cast<Vector &>(const_cast<const Figure *>(this)->operator () (index));
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Figure::operator [] (int index) const {
    if (index < 0 || index >= VERTICES) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return leng[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Figure::operator[](int index) {
    return const_cast<double &>(const_cast<const Figure *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator << (std::ostream &out, Figure const &tmp) {
    for (int i = 0; i < VERTICES-1; ++i) {
        out  << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i) <</* "    " << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i) <<*/"\n";
    }

    for (int j = 0; j < VERTICES-1; ++j) {
        out  << std::setw(16) << std::fixed << std::setprecision(10) << tmp[j] <</* "    " << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i) <<*/"\n";
    }

    return out;
}
