#ifndef LISTADOBLELN_H
#define LISTADOBLELN_H
#include <string>
using namespace std;
class nodoListaDobleLN
{
public:
    nodoListaDobleLN();
    int posicionX;
    int posicionY;
    int tamanio;
    string colorRGB;
    nodoListaDobleLN *siguiente;
    nodoListaDobleLN *anterior;

};
class ListaDobleLN
{
public:
    ListaDobleLN();
    nodoListaDobleLN *primero;
    //funciones
    bool estaVacia();
    nodoListaDobleLN* crearNodo(int posX,int posY,string color);
    void insertarNodo(int pX,int pY,string co);
    void mostrar();
    void graficaLista(string nomGrafica, string tipoLN);
    string defineNodos();
    string apuntarNodos();
    string intToString(int val);
protected:

private:
};

#endif // LISTADOBLELN_H
