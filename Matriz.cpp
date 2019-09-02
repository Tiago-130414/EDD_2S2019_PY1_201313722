#include "Matriz.h"
#include <string>
#include <iostream>
using namespace std;
NodoFC::NodoFC(int fila,int columna,string color)
{
    //ctor
    fila = fila;
    columna = columna;
    color =color;
    siguiente = NULL;
    anterior = NULL;
    arriba = NULL;
    abajo = NULL;
}

Matriz::Matriz()
{
    //ctor
    columnas = NULL;
    filas = NULL;
}
