#ifndef ARBOLBB_H
#define ARBOLBB_H
#include "ListaSimple.h"
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class ArbolBB
{
    public:
        //attributes
        string nombreIMG;
        ArbolBB *izquierda;
        ArbolBB *derecha;
        ListaSimple cubo;
        //prototypes of function
        ArbolBB();
        bool estaVacio(ArbolBB *&raiz);
        ArbolBB* crearNodo(string imagen,string rutaArchivo,string rutaSinArchivo);
        void insertarNodo(ArbolBB *&raiz,string imagen,string rutaArchivoCSV,string rutaSinArchivo);
        void recorridoPre(ArbolBB *&raiz);
        void recorridoInO(ArbolBB *&raiz);
        void recorridoPost(ArbolBB *&raiz);
        ArbolBB* eliminarNodo(ArbolBB *&raiz,string elimina);
        void graficarArbol(ArbolBB *&raiz);
        string listadoNodos(ArbolBB *&raiz);
        string apuntadores(ArbolBB *raiz);
        void limpiarCadenas();
        void graficaLista(ArbolBB *&raiz);
        string listadoNodosInorder(ArbolBB *raiz);
        string apuntadoresInorder(ArbolBB *raiz);
        string eliminarUltimaFlecha(string c);
        string limpiarEspaciosBlanco(string c);
        ///grafica PostOrder
        void graficaListaPostOrden(ArbolBB *raiz);
        string listadoNodosPostorder(ArbolBB *raiz);
        string apuntadorNodosPostorder(ArbolBB *raiz);
        ///grafica PreOrder
        void graficaListaPreOrden(ArbolBB *raiz);
        string listadoNodosPreorder(ArbolBB *raiz);
        string apuntadorNodosPreorder(ArbolBB *raiz);
        ///metodos para insertar imagen
        void leerArchivoCapas(string archivo,ArbolBB *&nuevo,string rutaTemp,string nombreImagen);
        ///metodos string
        int stringToInt(string n);
    protected:

    private:
};

#endif // ARBOLBB_H
