#include <iostream>
#include <string>
#include <algorithm>

//Ejercicio 3: Calcular impuestos de productos
using namespace std;
int main() {
    double precioOriginal;
    string categoria;

    cout << "Ingrese el precio del producto: ";
    cin >> precioOriginal;

    cin.ignore();
    cout << "Ingrese la categoría del producto (Electrónica, Ropa, Alimentos): ";
    getline(cin, categoria);

    // Convertir texto a minusculas
    transform(categoria.begin(), categoria.end(), categoria.begin(), ::tolower);
    // Promedios para Descuentos de productos
    double precioConDescuento = (precioOriginal > 1000) ? precioOriginal * 0.9 : precioOriginal;
   
    double impuestoPorcentaje =
        (categoria == "electronica") ? 0.20 :
        (categoria == "ropa") ? 0.10 :
        (categoria == "alimentos") ? 0.05 :
        0.0; 

    // Calcular impuesto
    double impuesto = precioConDescuento * impuestoPorcentaje;

    double precioFinal = precioConDescuento + impuesto;

    cout << "Precio con descuento: $" << precioConDescuento << endl;
    cout << "Impuesto aplicado: $" << impuesto << endl;
    cout << "Precio final: $" << precioFinal << endl;
    system("pause");
    return 0;
}