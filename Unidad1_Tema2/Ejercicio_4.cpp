#include <iostream>
using namespace std;

int main() {
    int numero; 
    int multiplicador = 1;

    cout << "Ingrese un número entero: ";
    cin >> numero;

    if (numero == 0) {
        cout << "Componente: 0" << endl;
        return 0; 
    }

    while (numero > 0) {
        int digito = numero % 10;
        int componente = digito * multiplicador;

        if (multiplicador == 1) {
            cout << "Unidad: " << componente << endl;
        } else if (multiplicador == 10) {
            cout << "Decena: " << componente << endl;
        } else if (multiplicador == 100) {
            cout << "Centena: " << componente << endl;
        } else if (multiplicador == 1000) {
            cout << "Unidad de mil: " << componente << endl;
        } 
        
        numero = numero / 10; 
        multiplicador = multiplicador * 10; 
    }
    return 0; 
}