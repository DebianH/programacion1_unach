#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int contarVocales(const string& texto) {
    int contador = 0;
    for (char c : texto) {
        c = tolower(c); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

// Ignorar vocales y contar consonantes
int contarConsonantes(const string& texto) {
    int contador = 0;
    for (char c : texto) {
        c = tolower(c);
        if (isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            contador++;
        }
    }
    return contador;
}

int main() {
    string texto;
    cout << "Ingrese un texto: ";
    getline(cin, texto);

    int vocales = contarVocales(texto);
    int consonantes = contarConsonantes(texto);

    cout << "Cantidad de vocales: " << vocales << endl;
    cout << "Cantidad de consonantes: " << consonantes << endl;

    return 0;
}
