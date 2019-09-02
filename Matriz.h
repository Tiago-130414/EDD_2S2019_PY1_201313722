#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <iostream>
using namespace std;
class NodoFC
{
    public:
        NodoFC(int,int,string);
        string color;
        int fila;
        int columna;
        NodoFC *siguiente;
        NodoFC *anterior;
        NodoFC *arriba;
        NodoFC *abajo;
    protected:

    private:

};

class Matriz
{
    public:
        Matriz();
        NodoFC *filas;
        NodoFC *columnas;

    protected:

    private:
};

#endif // MATRIZ_H
