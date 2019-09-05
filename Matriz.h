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
        void insertarNodo(int fila,int columna,string color);
        void enlazarColumna(NodoFC *&pivote,NodoFC *&nuevoCol,int columna);
        void enlazarFila(NodoFC *&pivote,NodoFC *&nuevoFil,int fila);
        int stringToInt(string castear);
        string intToString(int val);
        void imprimir();
        void escribirDot();
        string creandoNodosFilaGuia();
        string creandoNodosColumnaGuia();
        string nodosContenidoFila();
        string rankSame();
        string enlazarColumnaConNodo();
        string enlazarNodosMediosColumna();
        void linealizarFilas();
        void linealizarColumnas();
    protected:

    private:
};

#endif // MATRIZ_H
