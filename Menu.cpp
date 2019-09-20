#include "Menu.h"
#include "ArbolBB.h"
#include "ListaCircular.h"
#include "ListaSimple.h"
#include "ListaDobleLN.h"
#include "leerArchivo.h"
#include <direct.h> //crear carpetas
#include <iostream>
#include <fstream>
using namespace std;
ListaCircular obj;//lista circular de filtros
ArbolBB obj2;//objeto de tipo arbol
ArbolBB *raiz = NULL;//puntero tipo arbol
ArbolBB *temp = NULL;
ListaDobleLN obj4;//lista de linealizacion
ListaSimple objL;//lista de matrices
leerArchivo lee;//leer archivos csv
string imagenSeleccionada;
string imagenGCapa;
Menu::Menu()
{
    mostrarMenu();
}

void Menu::mostrarMenu()
{
    mkdir("c:/EXPORT");
    string carpetaRaiz;
    string carpeta;
    string csv;
    string rutaImagen;
    string rutaSinArchivo;
    int op =0;
    do
    {
        cout<<"=============== PHOTOGEN++ ==============="<<endl;
        cout<<"1.- Insert Image"<<endl;
        cout<<"2.- Select Image"<<endl;
        cout<<"3.- Apply Filters"<<endl;
        cout<<"4.- Manual Editing"<<endl;
        cout<<"5.- Export Image"<<endl;
        cout<<"6.- Reports"<<endl;
        cout<<"7.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            ///cargar imagen
            cout<<"=============== INSERT IMAGE ===============\n"<<endl;
            cout<<"Ingrese nombre de carpeta en disco C: donde se encuentran archivos: "<<endl;
            cin>>carpetaRaiz;
            cout<<"Ingrese nombre de carpeta donde se encuentran Imagen: "<<endl;
            cin>>carpeta;
            cout<<"Ingrese nombre de archivo csv de config. inicial: "<<endl;
            cin>>csv;
            rutaImagen ="C:/"+carpetaRaiz +"/"+ carpeta +"/";
            rutaSinArchivo = rutaImagen;
            rutaImagen = string(rutaImagen)+string(csv);
            obj2.insertarNodo(raiz,carpeta,rutaImagen.c_str(),rutaSinArchivo.c_str());
            break;
        case 2:
            ///seleccionar imagen
            seleccionarImagenArbol(imagenSeleccionada);
            break;
        case 3:
            ///apply filters

            break;
        case 4:
            ///manual editing
            menuReportes();
            break;
        case 5:
            ///export image
            if(imagenSeleccionada.empty())
            {
                cout<<"=============== EXPORT IMAGE ===============\n"<<endl;
                cout<<"Seleccione una imagen antes de importar"<<endl;
            }
            else
            {
                temp = obj2.buscar(raiz,imagenSeleccionada);
                if(temp!=NULL)
                {
                    temp->cubo.generarCss(imagenSeleccionada);
                    temp->cubo.generarHTML(imagenSeleccionada);
                }
                else
                {
                    cout<<"imagen buscada no encontrada"<<endl;
                }
            }
            break;
        case 6:
            ///reportes
            menuReportes();
            break;
        case 7:
            system("exit");
            break;
        }
    }
    while(op!=7);
}

void Menu::menuReportes()
{
    int op=0;
    do
    {
        cout<<"=============== REPORTS ==============="<<endl;
        cout<<"1.- Imported Images Report"<<endl;
        cout<<"2.- Image Layer Report"<<endl;
        cout<<"3.- Linear Matrix Report"<<endl;
        cout<<"4.- Traversal Report"<<endl;
        cout<<"5.- Filter Report"<<endl;
        cout<<"6.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            obj2.graficarArbol(raiz);
            break;
        case 2:
            imageLayerReport(imagenGCapa);
            break;
        case 3:
            break;
        case 4:
            traversalReport();
            break;
        case 5:
            break;
        }
    }
    while(op!=6);
}

void Menu:: traversalReport()
{
    int op=0;
    do
    {
        cout<<"=============== TRAVERSAL REPORT ==============="<<endl;
        cout<<"1.- Inorder Traversal"<<endl;
        cout<<"2.- Postorder Traversal"<<endl;
        cout<<"3.- Preorder Traversal"<<endl;
        cout<<"4.- Exit"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            obj2.graficaLista(raiz);
            break;
        case 2:
            obj2.graficaListaPostOrden(raiz);
            break;
        case 3:
            obj2.graficaListaPreOrden(raiz);
            break;
        }
    }
    while(op!=4);
}


void Menu::imageLayerReport(string& image)
{
    int numCapa =0;
    bool exist;
    if(image.empty())
    {
        cout<<"=============== IMAGE LAYER REPORT ===============\n"<<endl;
        obj2.recorridoInO(raiz);
        cout<<"\nIngrese Nombre de Imagen: "<<endl;
        cin>>image;
        temp = obj2.buscar(raiz,image);
        if(temp!=NULL)
        {
            system("cls");
            cout<<"=============== IMAGE LAYER REPORT ===============\n"<<endl;
            temp->cubo.mostrar();
            do{
             cout<<"Ingrese numero de capa valido: "<<endl;
             cin>>numCapa;
             exist = temp->cubo.existeCapa(numCapa);
            }while(exist==false&&numCapa!=0);
            temp->cubo.generarGraficaCapa(numCapa,image);
        }
        else
        {
            cout<<"imagen no generada"<<endl;
        }
    }
    else
    {
        cout<<"=============== IMAGE LAYER REPORT ===============\n"<<endl;

    }
}

///seleccionar imagen
void Menu::seleccionarImagenArbol(string& imagen)
{
    cout<<"=============== SELECT IMAGE ==============="<<endl;
    obj2.recorridoInO(raiz);
    cout<<"\nIngrese Nombre de Imagen: "<<endl;
    cin>>imagen;
    system("cls");
}

void Menu::leerArchivoCapas(string archivo)
{
    ifstream file(archivo);
    if(!file.is_open())
        cout<<"Error: Archivo no abierto"<<'\n';
    string layer;
    string nameFile;
    while(file.good())
    {
        layer="";
        nameFile="";
        getline(file,layer,',');
        getline(file,nameFile,'\n');
        if(layer!=" "&&layer!="\n"&&layer!="")
        {
            if(nameFile!=" "&&nameFile!="\n"&&nameFile!="")
            {
                if(nameFile!="File"&&layer!="Layer")
                {
                    //objL.insertarCapa(stringToInt(layer),nameFile);
                }
            }
        }
    }
    file.close();
}

////////////////////leer archivo de configuracion
void Menu::leerArchivoConfig(string archivo)
{
    ifstream file(archivo);
    if(!file.is_open())
        cout<<"Error: Archivo no abierto"<<'\n';
    string config;
    string value;
    while(file.good())
    {
        config="";
        value="";
        getline(file,config,',');
        getline(file,value,'\n');
        cout<<config<<value<<endl;
    }
    file.close();
}

////////////////////castear
int Menu::stringToInt(string s)
{
    stringstream cast(s);
    int x = 0;
    cast >> x;
    return x;
}

/*temp = obj2.buscar(raiz,"hora_de_aventura");
           temp->cubo.generarCss("prueba");
           temp->cubo.generarHTML("prueba");*/
