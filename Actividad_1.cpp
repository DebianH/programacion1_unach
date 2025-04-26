#include <iostream>
using namespace std;

int main() {

    string palabra;
    cout << "Ingresa una palabra: ";
    cin >> palabra;

    string palabraInvertida = "";
    int i = palabra.length() - 1;
    while (i >= 0) {
        palabraInvertida += palabra[i];
        i--;
    }
  
    for (int i = 0; i < 5; i++) {
        cout << "La palabra invertida es: " << palabraInvertida << endl;
    }
    return 0;
}