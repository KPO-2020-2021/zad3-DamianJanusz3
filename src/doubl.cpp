#include "size.hh"
#include "doubl.hh"
//#include "matrix.hh"
//#include <math.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#define MIN_DIFF 0.00000001



/******************************************************************************
 |  Konstruktor klasy Figure.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablicę wektorów zerowych.                                            |
 *///
Doubl::Doubl() {
    
    for (int i = 0; i < VERTICES; ++i) {
        //for (int j = 0; j < SIZE; ++j) {
           
            len[i] = 0;
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
Doubl::Doubl(double tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        //for (int j = 0; j < SIZE; ++j) {
            len[i] = tmp[i];
        //}
    }
}


bool  Doubl::operator == (  Doubl m)  {

if (abs(this->len[0] - m.len[2]) <= MIN_DIFF && abs(this->len[1] - m.len[3]) <= MIN_DIFF) 
    return true;

  else
    return false;
}


/*Doubl length (Figure rect)  {
    Doubl result;
    for (int i=0; i<VERTICES; ++i) {
        result.leng[i]=rect.vertices[i] & rect.vertices[i+1];
    }
    //wynik.dl1=abs(sqrt(pow(this->tabp[0].tabv[0] - this->tabp[1].tabv[0], 2) + pow(this->tabp[0].tabv[1] - this->tabp[1].tabv[1], 2)));
   

    return result;
}*/