/*
Escribe un programa que calcule el área de diferentes figuras geométricas según la 
selección del usuario:
"	C: Círculo (Área = PI * radio²).
"	R: Rectángulo (Área = largo * ancho).
"	T: Triángulo (Área = (base * altura) / 2).
*/

#include <iostream>
#include <cmath> 
#include <string>
#include <map>

using namespace std;
int main() {
	
	 map<string, int> opciones = {
        {"circulo", 1},
        {"rectangulo", 2},
        {"triangulo", 3}
    };

    string opcion;
    float area = 0;
    float radio, largo, ancho;

    cout << "Ingrese la figura (circulo, rectangulo, triangulo): "<< endl;
    cin >> opcion;

    if (opciones[opcion] == 1) {
        cout << "Ingrese el valor del radio: ";
        cin >> radio;
        area = M_PI * (radio * radio);
    } else if (opciones[opcion] == 2) {
        cout << "Ingrese el valor del largo: ";
        cin >> largo;
        cout << "Ingrese el valor del ancho: ";
        cin >> ancho;
        area = largo * ancho;
    } else if (opciones[opcion] == 3) {
        float base, h;
        cout << "Ingrese la base: ";
        cin >> base;
        cout << "Ingrese la altura: ";
        cin >> h;
        area = base * (h / 2);
    } else {
        cout << "Opcion invalida" << endl;
        return 1; 
    }

    cout << "El area es: " << area << endl;
    return 0;
}
