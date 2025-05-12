#include <iostream>
#include <cmath>
using namespace std;

// Calcular y mostrar 
void mostrarMonedas(int centavos) {
    int monedas1 = centavos / 100; centavos %= 100;
    int monedas50 = centavos / 50; centavos %= 50;
    int monedas25 = centavos / 25; centavos %= 25;
    int monedas10 = centavos / 10; centavos %= 10;
    int monedas5 = centavos / 5; centavos %= 5;
    int monedas1cent = centavos;

    cout << "\nMostrar monedas:\n";
    cout << "Monedas de $1.00: " << monedas1 << endl;
    cout << "Monedas de $0.50: " << monedas50 << endl;
    cout << "Monedas de $0.25: " << monedas25 << endl;
    cout << "Monedas de $0.10: " << monedas10 << endl;
    cout << "Monedas de $0.05: " << monedas5 << endl;
    cout << "Monedas de $0.01: " << monedas1cent << endl;
}

int main() {
    double cantidad;
    cout << "Ingrese una cantidad en dinero (por ejemplo 3.76): ";
    cin >> cantidad;

    int centavos = round(cantidad * 100); // Convertir a centavos

    mostrarMonedas(centavos);

    return 0;
}
