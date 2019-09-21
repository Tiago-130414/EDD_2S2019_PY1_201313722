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
ArbolBB *tempFiltro = NULL;
ListaDobleLN obj4;//lista de linealizacion
ListaSimple objL;//lista de matrices
leerArchivo lee;//leer archivos csv
string imagenSeleccionada;
string imagenGCapa;
string linearMatrix;
Menu::Menu()
{
    mostrarMenu();
}

void Menu::mostrarMenu()
{
    mkdir("C:/EXPORT");
    mkdir("C:/GRAFICAS_PROYECTO");
    string carpetaRaiz;
    string carpeta;
    string csv;
    string rutaImagen;
    string rutaSinArchivo;
    bool existeArchivo=false;
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
            do
            {
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
                ifstream ar(rutaImagen.c_str());
                if(ar.good())
                {
                    existeArchivo = true;
                }
            }
            while(existeArchivo ==false);
            obj2.insertarNodo(raiz,carpeta,rutaImagen.c_str(),rutaSinArchivo.c_str());
            system("pause");
            system("cls");
            break;
        case 2:
            ///seleccionar imagen
            seleccionarImagenArbol(imagenSeleccionada);
            break;
        case 3:
            ///apply filters
            aplicarFiltro(imagenSeleccionada);
            break;
        case 4:
            ///manual editing

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
                exportarImagen();
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
            linearMatrixReport(linearMatrix);
            break;
        case 4:
            traversalReport();
            break;
        case 5:
            ///lista circular
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
        do
        {
            cout<<"Ingrese numero de capa valido: "<<endl;
            cin>>numCapa;
            if(numCapa!=0)
            {
                exist = temp->cubo.existeCapa(numCapa);
            }
            else
            {
                cout<<"!Error capa 0 unicamente de configuracion!"<<endl;
            }
        }
        while(exist==false);
        temp->cubo.generarGraficaCapa(numCapa,image);
        system("cls");
    }
    else
    {
        cout<<"imagen no generada"<<endl;
    }
}

void Menu::linearMatrixReport(string& img)
{
    int numCapa =0;
    bool exisT;
    int op=0;
    cout<<"=============== LINEAR MATRIX REPORT  ===============\n"<<endl;
    obj2.recorridoInO(raiz);
    cout<<"\nIngrese Nombre de Imagen: "<<endl;
    cin>>img;
    temp = obj2.buscar(raiz,img);
    if(temp!=NULL)
    {
        system("cls");
        cout<<"=============== LINEAR MATRIX REPORT ===============\n"<<endl;
        temp->cubo.mostrar();
        do
        {
            cout<<"Ingrese numero de capa valido: "<<endl;
            cin>>numCapa;
            if(numCapa!=0)
            {
                exisT = temp->cubo.existeCapa(numCapa);
            }
            else
            {
                cout<<"!Error capa 0 unicamente de configuracion!"<<endl;
            }
        }
        while(exisT==false);
        system("cls");
        cout<<"=============== LINEAR MATRIX REPORT ===============\n"<<endl;
        cout<<"1.- Linealizacion por filas"<<endl;
        cout<<"2.- Linealizacion por columnas\n"<<endl;
        cout<<"Ingrese numero metodo Linealizacion: "<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
            temp->cubo.generarGraficaLinealizacionFilas(numCapa,img);
            break;
        case 2:
            temp->cubo.generarGraficaLinealizacionColumnas(numCapa,img);
            break;
        }
    }
    else
    {
        cout<<"imagen no generada"<<endl;
    }

}

///seleccionar imagen
void Menu::seleccionarImagenArbol(string& imagen)
{
    obj.limpiarLista();
    imagenSeleccionada="";
    cout<<"=============== SELECT IMAGE ==============="<<endl;
    obj2.recorridoInO(raiz);
    cout<<"\nIngrese Nombre de Imagen: "<<endl;
    cin>>imagen;
    system("cls");
}
///aplicar filtros
void Menu::aplicarFiltro(string& ima)
{
    int op=0;
    do
    {
        cout<<"=============== APPLY FILTERS ==============="<<endl;
        cout<<"1.- Negative(Negativo)"<<endl;
        cout<<"2.- Grayscale(Escala De Grises)"<<endl;
        cout<<"3.- Mirror(Espejo)"<<endl;
        cout<<"4.- Collage(Collage)"<<endl;
        cout<<"5.- Mosaic(mosaico)"<<endl;
        cout<<"6.- Exit"<<endl;
        cin>>op;
        switch(op)
        {
        case 1:
            menuNegativo(ima);
            break;

        case 2:

            menuEscalaGrises(ima);
            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;
        }
    }
    while(op!=6);
}
///menu filtro negativo
void Menu::menuNegativo(string& im)
{
    int op=0;
    int numC=0;
    if(im.empty())
    {
        cout<<"=============== NEGATIVE FILTER ===============\n"<<endl;
        cout<<"Seleccione una imagen antes de aplicar filtro"<<endl;
    }
    else
    {
        tempFiltro = obj2.buscar(raiz,im);
        if(tempFiltro!=NULL)
        {
            do
            {
                cout<<"=============== NEGATIVE FILTER ===============\n"<<endl;
                cout<<"1.- Full Picture"<<endl;
                cout<<"2.- Per Layer"<<endl;
                cout<<"3.- Exit"<<endl;
                cin>>op;
                switch(op)
                {
                case 1:
                    obj.insertar("Negativo",tempFiltro->cubo);
                    obj.generarCssNegativo("Negativo");
                    cout<<"Filtro Negativo Aplicado"<<endl;
                    break;

                case 2:
                    negativoPorCapa(imagenGCapa);
                    break;
                }
            }
            while(op!=3);
        }
        else
        {
            cout<<"imagen buscada no encontrada"<<endl;
        }
    }
}

void Menu::negativoPorCapa(string &im){
int numCapa =0;
    bool exist = false;
    if(tempFiltro!=NULL)
    {
        system("cls");
        cout<<"=============== NEGATIVE FILTER ===============\n"<<endl;
        tempFiltro->cubo.mostrar();
        do
        {
            cout<<"Ingrese numero de capa valido: "<<endl;
            cin>>numCapa;
            if(numCapa!=0)
            {
                exist = tempFiltro->cubo.existeCapa(numCapa);
            }
            else
            {
                cout<<"!Error capa 0 unicamente de configuracion!"<<endl;
            }
        }
        while(exist==false);
        string nombreImg= "NegativoPorCapa" + numCapa;
        obj.insertar(nombreImg.c_str(),tempFiltro->cubo);
        obj.generarCssNegativoPorCapa(nombreImg.c_str(),numCapa);
        system("cls");
    }
    else
    {
        cout<<"imagen no generada"<<endl;
    }
}


void Menu::menuEscalaGrises(string& im)
{
    int op=0;
    if(im.empty())
    {
        cout<<"=============== GRAYSCALE ===============\n"<<endl;
        cout<<"Seleccione una imagen antes de aplicar filtro"<<endl;
    }
    else
    {
        tempFiltro = obj2.buscar(raiz,im);
        if(tempFiltro!=NULL)
        {
            do
            {
                cout<<"=============== GRAYSCALE ===============\n"<<endl;
                cout<<"1.- Full Picture"<<endl;
                cout<<"2.- Per Layer"<<endl;
                cout<<"3.- Exit"<<endl;
                cin>>op;
                switch(op)
                {
                case 1:
                    obj.insertar("Escala_Grises",tempFiltro->cubo);
                    obj.generarEscalaGrises("Escala_Grises");
                    cout<<"Filtro Negativo Aplicado"<<endl;
                    break;

                case 2:


                    break;
                }
            }
            while(op!=3);
        }
        else
        {
            cout<<"imagen buscada no encontrada"<<endl;
        }
    }
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

void Menu::exportarImagen(){
      int op;
      string filter;
      do
            {

                cout<<"=============== EXPORT IMAGE ===============\n"<<endl;
                cout<<"1.- Full Picture"<<endl;
                cout<<"2.- Per Filter"<<endl;
                cout<<"3.- Exit"<<endl;
                cin>>op;
                system("cls");
                switch(op)
                {
                case 1:
                     temp = obj2.buscar(raiz,imagenSeleccionada);
                    if(temp!=NULL)
                    {
                        temp->cubo.generarCss(imagenSeleccionada);
                        temp->cubo.generarHTML(imagenSeleccionada);
                        cout<<"Imagen generada con exito"<<endl;
                    }
                    else
                    {
                        cout<<"imagen buscada no encontrada"<<endl;
                    }
                    break;
                case 2:
                    cout<<"=============== EXPORT IMAGE ===============\n"<<endl;
                    obj.Mostrar();
                    cout<<"\nIngrese el nombre del filtro a exportar: "<<endl;
                    cin>>filter;
                     obj.exportarImagen(filter,imagenSeleccionada);
                    break;
                }
            }
            while(op!=3);
}
