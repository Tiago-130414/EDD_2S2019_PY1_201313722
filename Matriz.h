#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <iostream>
#include<bits/stdc++.h>
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
    void escribirDot(string nomImg);
    string creandoNodosFilaGuia();
    string creandoNodosColumnaGuia();
    string nodosContenidoFila();
    string rankSame();
    string enlazarColumnaConNodo();
    string enlazarNodosMediosColumna();
    void linealizarFilas(string nom);
    void linealizarColumnas(string nom);
    ///cantidad de filas y columnas
    int numeroFilas();
    int numeroColumnas();
    ///linealizar matriz por filas
    string LinMF(string nomCapa,int);
    int calcularK(int,int,int);
    int esPar(int num);
    string rgbToHex(int r, int g, int b, bool with_head = false);
    ///filtro
    void aplicarNegativo();
    string negativoRGB(int r,int g,int b);
    ///escala grises
    void aplicarEscalaGrises();
    string escalaGrises(int r,int g,int b);
    ///reportes rotaciones
    void escribirDotHorizontal(string nomImg);
    void escribirDotVertical(string nomImg);
    ///manual editing
    void modificarNodo(int x, int y,string rgb);
protected:

private:
};

#endif // MATRIZ_H
