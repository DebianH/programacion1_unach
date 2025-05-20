// Implementa el cálculo del máximo común divisor utilizando tanto
// recursividad como iteración (se debe implementar un ejercicio tanto
// para recursividad como para iteración)
# include <iostream>
using namespace std;

int mcdRecursivo(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mcdRecursivo(b, a % b);
    }
}
int mcdIterativo(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    cout << " ---- MCD ---- " << endl;
    cout << "Ingrese primer numero para calcular el MCD!" << endl;
    cin >> num1;
    cout << "Ingrese segundo numero para calcular el MCD!" << endl;
    cin >> num2;

    cout << "El MCD de " << num1 << " y " << num2 << " (recursivo) es: " << mcdRecursivo(num1, num2) << endl;
    cout << "El MCD de " << num1 << " y " << num2 << " (iterativo) es: " << mcdIterativo(num1, num2) << endl;

    return 0;
}

