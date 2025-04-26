#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

    int numeroSecreto, intento;
    int opcion;
    bool adivinado = false;

    // Generar número aleatorio
    srand(time(0));
    numeroSecreto = rand() % 10 + 1;

    cout << "⭐¡Bienvenido al juego de adivinar el numero!" << endl;

    while (!adivinado) {
        cout << "\nMenu:" << endl;
        cout << "1. Adivinar el numero" << endl;
        cout << "2. Mostrar el numero secreto" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            while (true) {
                cout << "Adivina el numero entre 1 y 100: ";
                cin >> intento;

                if ( intento == 0) {
                    cout << "Saliendo del juego. ¡Hasta luego!" << endl;
                    break;
                } else if (intento == numeroSecreto) {
                    cout << "¡Felicidades! Adivinaste el numero secreto." << endl;
                    adivinado = true;
                    break;
                } else if (intento < 1 || intento > 10) {
                    cout << "Numero fuera de rango. Intenta de nuevo." << endl;                    
                } else if (intento < numeroSecreto) {
                    cout << "Incorrecto. El numero es mayor. [Si quiere salir digita 0]" << endl;
                } else if (intento > numeroSecreto) {
                    cout << "Incorrecto. El numero es menor. [Si quiere salir digita 0]" << endl;
                } else {
                    cout << "Incorrecto. Intenta de nuevo. [Si quiere salir digita 0]" << endl;
                }
            }
        } else if (opcion == 2) {
            cout << "El numero secreto es: " << numeroSecreto << endl;
        } else if (opcion == 3) {
            cout << "Saliendo del juego. ¡Hasta luego!" << endl;
            break;
        } else {
            cout << "Opcion invalida. Intenta otra vez." << endl;
        }
    }

    return 0;
}