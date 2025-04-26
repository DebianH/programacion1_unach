#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {
    //Ejercicio 3: Recrear Fibonacci

    int n, a = 0, b = 1, c;
    long long pares = 0, impares = 0;
    cout << "Ingrese el numero de terminos de la serie Fibonacci: ";    
    cin >> n;
    cout << "Serie Fibonacci: " << a << ", " << b;
    for (int i = 1; i < n; i++) {
        c = a + b;
        cout << ", " << c;
        a = b;
        b = c;
        if (c % 2 == 0) {
            pares += c;
        } else {
            impares += c;
        }
    }
    cout << endl;
    cout << "El " << n << "termino de la serie Fibonacci es: " << c << endl;
    cout << "Total de numeros pares: " << pares << endl;
    cout << "Total de numeros impares: " << impares << endl;

    return 0;
}