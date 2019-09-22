#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;
class Menu
{
public:
    Menu();
    void mostrarMenu();
    void menuReportes();
    void traversalReport();
    void leerArchivoCapas(string archivo);
    void leerArchivoConfig(string archivo);
    int stringToInt(string s);
    void seleccionarImagenArbol(string& imagen);
    void imageLayerReport(string& image);
    void linearMatrixReport(string& img);
    void aplicarFiltro(string& im);
    void menuNegativo(string& im);
    void negativoPorCapa(string &im);
    void menuEscalaGrises(string& im);
    void exportarImagen();
    void espejo(string& ima);
    void reporteFiltros();
    void escalaGPorCapa(string &im);
    void reporteFiltrosIndividuales();
    void reportesindividuales();
    void manualEditing();



protected:

private:
};

#endif // MENU_H
