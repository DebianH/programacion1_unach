// Sistema Inteligente de Procesamiento de Datos - Venta de Zapatillas Nike
// Tema: Recomendaciones y análisis de zapatillas originales Nike

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

// Base de datos de productos
vector<string> modelos;
vector<double> precios;

// Cargar catálogo desde archivo externo (usando for)
void cargarCatalogoDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        exit(1);
    }

    modelos.clear();
    precios.clear();

    vector<string> lineas;
    string linea;
    while (getline(archivo, linea))
    {
        lineas.push_back(linea);
    }
    archivo.close();

    for (size_t i = 0; i < lineas.size(); ++i)
    {
        size_t separador = lineas[i].find(',');
        if (separador != string::npos)
        {
            string modelo = lineas[i].substr(0, separador);
            double precio = stod(lineas[i].substr(separador + 1));
            modelos.push_back(modelo);
            precios.push_back(precio);
        }
    }
}

// Funciones estadísticas
void mostrarCatalogo()
{
    cout << "\n|--- Catálogo de Zapatillas Nike ---|\n";
    for (size_t i = 0; i < modelos.size(); ++i)
    {
        cout << i + 1 << ". " << modelos[i] << " - $" << precios[i] << endl;
    }
}

double calcularMedia()
{
    double suma = 0;
    for (double p : precios)
        suma += p;
    return suma / precios.size();
}

double calcularMediana()
{
    vector<double> copia = precios;
    sort(copia.begin(), copia.end());
    int n = copia.size();
    if (n % 2 == 0)
        return (copia[n / 2 - 1] + copia[n / 2]) / 2;
    else
        return copia[n / 2];
}

double calcularModa()
{
    map<double, int> freq;
    for (double p : precios)
        freq[p]++;
    int maxFreq = 0;
    double moda = 0;
    for (auto &p : freq)
    {
        if (p.second > maxFreq)
        {
            maxFreq = p.second;
            moda = p.first;
        }
    }
    return moda;
}

double calcularDesviacionEstandar()
{
    double media = calcularMedia();
    double suma = 0;
    for (double p : precios)
        suma += pow(p - media, 2);
    return sqrt(suma / precios.size());
}

void mostrarEstadisticas()
{
    cout << fixed << setprecision(2);
    cout << "\n--- Estadísticas ---\n";
    cout << "Media: $" << calcularMedia() << endl;
    cout << "Mediana: $" << calcularMediana() << endl;
    cout << "Moda: $" << calcularModa() << endl;
    cout << "Desviación Estándar: $" << calcularDesviacionEstandar() << endl;
}

void prediccionPrecio()
{
    double sumaDiff = 0;
    for (size_t i = 1; i < precios.size(); ++i)
        sumaDiff += precios[i] - precios[i - 1];
    double promedioDiff = sumaDiff / (precios.size() - 1);
    double prediccion = precios.back() + promedioDiff;
    cout << "\nPrecio estimado del próximo modelo: $" << fixed << setprecision(2) << prediccion << endl;
}

void segmentarDatos()
{
    double media = calcularMedia();
    cout << "\nZapatillas por encima de la media ($" << media << "):\n";
    for (size_t i = 0; i < modelos.size(); ++i)
        if (precios[i] > media)
            cout << "- " << modelos[i] << " ($" << precios[i] << ")\n";

    cout << "\nZapatillas por debajo o igual a la media:\n";
    for (size_t i = 0; i < modelos.size(); ++i)
        if (precios[i] <= media)
            cout << "- " << modelos[i] << " ($" << precios[i] << ")\n";
}

void visualizarHistograma()
{
    cout << "\n--- Histograma de Precios ---\n";
    for (size_t i = 0; i < modelos.size(); ++i)
    {
        cout << setw(20) << left << modelos[i] << " | ";
        int barras = static_cast<int>(precios[i] / 10);
        for (int j = 0; j < barras; ++j)
            cout << "*";
        cout << " ($" << precios[i] << ")\n";
    }
}

void ordenarCatalogo(bool ascendente)
{
    for (size_t i = 0; i < precios.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < precios.size(); ++j)
        {
            if ((ascendente && precios[i] > precios[j]) || (!ascendente && precios[i] < precios[j]))
            {
                swap(precios[i], precios[j]);
                swap(modelos[i], modelos[j]);
            }
        }
    }
    cout << "\nCatálogo ordenado correctamente.\n";
}

void buscarPrecio(double precioBuscado)
{
    bool encontrado = false;
    for (size_t i = 0; i < precios.size(); ++i)
    {
        if (abs(precios[i] - precioBuscado) < 0.01)
        {
            cout << "Encontrado en posición " << i + 1 << ": " << modelos[i] << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontró ninguna zapatilla con ese precio.\n";
}

void recomendarPorPresupuesto(double presupuesto)
{
    cout << "\nRecomendaciones según tu presupuesto ($" << presupuesto << "):\n";
    for (size_t i = 0; i < modelos.size(); ++i)
    {
        if (precios[i] <= presupuesto)
            cout << "- " << modelos[i] << " ($" << precios[i] << ")\n";
    }
}

void mostrarMenu()
{
    cout << "\n\n|----- MENU PRINCIPAL -----|\n";
    cout << "1. Ver catálogo\n";
    cout << "2. Ver estadísticas\n";
    cout << "3. Predecir próximo precio\n";
    cout << "4. Segmentar datos\n";
    cout << "5. Ver histograma\n";
    cout << "6. Ordenar catálogo\n";
    cout << "7. Buscar por precio\n";
    cout << "8. Recomendación por presupuesto\n";
    cout << "9. Salir\n";
    cout << "Seleccione una opción: ";
}

int main()
{
    cargarCatalogoDesdeArchivo("catalogo.txt");

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarCatalogo();
            break;
        case 2:
            mostrarEstadisticas();
            break;
        case 3:
            prediccionPrecio();
            break;
        case 4:
            segmentarDatos();
            break;
        case 5:
            visualizarHistograma();
            break;
        case 6:
        {
            int orden;
            cout << "1. Ascendente\n2. Descendente\nSeleccione orden: ";
            cin >> orden;
            ordenarCatalogo(orden == 1);
            break;
        }
        case 7:
        {
            double precio;
            cout << "Ingrese el precio a buscar: ";
            cin >> precio;
            buscarPrecio(precio);
            break;
        }
        case 8:
        {
            double presupuesto;
            cout << "Ingrese su presupuesto: ";
            cin >> presupuesto;
            recomendarPorPresupuesto(presupuesto);
            break;
        }
        case 9:
            cout << "Gracias por usar el sistema.\n";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 9);

    return 0;
}
