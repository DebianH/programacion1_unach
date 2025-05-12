#include <iostream>
using namespace std;

// ---------- Conversión de Kilómetros a Millas ----------
void convertKilometers() {
    double km;
    cout << "Ingrese la distancia en kilómetros: ";
    cin >> km;

    double miles = km * 0.621371;
    cout << "Resultado: " << miles << " millas\n";
}

// ---------- Conversión de Celsius a Fahrenheit ----------
void convertCelsius() {
    double celsius;
    cout << "Ingrese la temperatura en grados Celsius: ";
    cin >> celsius;

    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << "Resultado: " << fahrenheit << " grados Fahrenheit\n";
}

// ---------- Conversión de Gramos a Kilogramos ----------
void convertGrams() {
    double grams;
    cout << "Ingrese el peso en gramos: ";
    cin >> grams;

    double kilograms = grams / 1000.0;
    cout << "Resultado: " << kilograms << " kilogramos\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== Menú de Conversión de Unidades ===\n";
        cout << "1. Kilómetros a Millas\n";
        cout << "2. Celsius a Fahrenheit\n";
        cout << "3. Gramos a Kilogramos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: convertKilometers(); break;
            case 2: convertCelsius(); break;
            case 3: convertGrams(); break;
            case 4: cout << "Cerando el programa. ¡Hasta pronto!\n"; break;
            default: cout << "Opción inválida. Por favor, intente de nuevo.\n";
        }

    } while (choice != 4);

    return 0;
}
