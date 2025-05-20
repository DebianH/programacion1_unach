#include <iostream>
using namespace std;
//Ejercicio 4
/**
 * Serie aritmética. EXplicación: Guia para saber que hace cada variable
 * @param primerTermino: el primer número de la serie (a)
 * @param diferencia: la diferencia constante entre los términos (d)
 * @param totalTerminos: cuántos términos tiene la serie (n)
 * @param indiceActual: 
 * @return 
 */
int sumaAlternadaSerie(int primerTermino, int diferencia, int totalTerminos, int indiceActual = 0) {
    // Caso base
    if (indiceActual >= totalTerminos)
        return 0;

    // Calcular el término actual de la serie: primerTermino + indiceActual * diferencia
    int terminoActual = primerTermino + indiceActual * diferencia;

    // Determinar el signo: +1 si es par, -1 si es impar
    int signo = (indiceActual % 2 == 0) ? 1 : -1;
    // Retornar el término actual multiplicado por su signo y la suma de los términos restantes
    return signo * terminoActual + sumaAlternadaSerie(primerTermino, diferencia, totalTerminos, indiceActual + 1);
}

int main() {
    int a, d, n;

    cout << "\n\t[ SUMA ALTERNADA DE UNA SERIE ARITMETICA ]\n";

    cout << "Ingrese el primer término (a): ";
    cin >> a;
    cout << "Ingrese la diferencia (d): ";
    cin >> d;
    cout << "Ingrese la cantidad de términos (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "La cantidad de términos debe ser mayor que cero.";
        return 1;
    }

    int resultado = sumaAlternadaSerie(a, d, n);
    cout << "La suma alternada de la serie es: " << resultado;
    cout << "\nEsta es la serie: ";
    for (int i = 0; i < n; i++) {
        int terminoActual = a + i * d;
        cout << ((i % 2 == 0) ? "+" : "-") << terminoActual << " ";
    }
    return 0;
}