#include "size.hh"

#include "matrix.hh"

#include <iomanip>
#include <iostream>
#include <cstdlib>


 


Vector Matrix::gaussdet (int n) {
/* Applying Gauss Elimination */
Vector x;
int i,j,k;
double ratio;



	 for(i=1;i<=n-1;++i)
	 {
		  if(this->value[i][i] == 0.0)
		  {
			   //std::cout<<"Mathematical Error!";
               throw std::runtime_error("0 na glownej przekatnej");
			   //exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = this->value[j][i]/this->value[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		this->value[j][k] = this->value[j][k] - ratio*this->value[i][k];
			   }
		  }
	 }
     //return *this;
	 /* Obtaining Solution by Back Substitution Method */
	 x[n] = this->value[n][n+1]/this->value[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = this->value[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - this->value[i][j]*x[j];
		  }
		  x[i] = x[i]/this->value[i][i];
	 }
return x;
}


 /******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      tmp - macierz, czyli drugi skladnik dodawania.                        |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 *///
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}





/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        //std::cout << "Error: Macierz jest poza zasiegiem"; 
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    if (column >= SIZE) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    if (column >= SIZE) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    return value[row][column];
}



/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << std::setw(16) << std::fixed << std::setprecision(10) << mat(i, j); 
        }
        std::cout << std::endl;
    }
    return out;
}


/******************************************************************************
 |  Metoda make - tworzy macierz obrotu o zadany kąt alfa                     |
 |  Argumenty:                                                                |
 |      alfa - zadany kąt                                                     |
 |                                                                            |
 |  Zwraca:                                                                   |
 |      NIC                  |
 */
void Matrix::make (double alfa) {
    double alfainrad = alfa * M_PI /180;
    this->value[0][0]= cos( alfainrad);
    this->value[0][1]=(-1)*( sin( alfainrad));
    this->value[1][0]= sin( alfainrad);
    this->value[1][1]= cos( alfainrad);   
    
}


/******************************************************************************
 |  Funkcja multiply - mnoży macierz obrotu z wektorem                        |
 |  Argumenty:                                                                |
 |      m - macierz obrotu                                                    |
 |      v - wektor                                                            |
 |      amount - ilość powtórzeń mnożenia                                     |
 |  Zwraca:                                                                   |
 |      wektor v po obrocie wokół środka układu współrzędnych.                |
 */
Matrix multiply (Matrix m, Matrix v,  double amount ) {

int k=0;
Matrix result;
while (k < amount) {
    result=m*v;
    ++k;
}
    return result;
}




Matrix Matrix::operator * (Matrix m) {
Matrix result;
for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
    result.value[i][j]=this->value[i][j]*m.value[i][j];
        }
    }
    return result;
}