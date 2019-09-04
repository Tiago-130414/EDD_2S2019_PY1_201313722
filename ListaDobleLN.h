#ifndef LISTADOBLELN_H
#define LISTADOBLELN_H
#include <string>
using namespace std;
class ListaDobleLN
{
    public:
        ListaDobleLN();
        int posicionX;
        int posicionY;
        int tamanio;
        string colorRGB;
        ListaDobleLN *siguiente;
        ListaDobleLN *anterior;
        //funciones
        bool estaVacia(ListaDobleLN *&primero);
        ListaDobleLN* crearNodo(int posX,int posY,string color);
        void insertarNodo(int pX,int pY,string co,ListaDobleLN *&primero);
        void mostrar(ListaDobleLN *&primero);
        void graficaLista(ListaDobleLN *&primero);
        string defineNodos(ListaDobleLN *&primero);
        string apuntarNodos(ListaDobleLN *&primero);
        string intToString(int val);
    protected:

    private:
};

#endif // LISTADOBLELN_H
