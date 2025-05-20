// Crear una función recursiva que cuente cuántos ceros hay en un número
// entero positivo.
//Ejercicio 3
# include <iostream>
using namespace std;

int contarCeros(string numUser) {
    for(int i = 0; i < numUser.length(); i++) {
        if (numUser[i] == '0') {
            return 1 + contarCeros(numUser.substr(i + 1));
        }
    }
    return 0;
}

int main() {
    string numUser;
    cout << "Ingrese un numero entero positivo!" << endl;
    cin >> numUser;
    cout << "El numero de ceros en el numero es: " << contarCeros(numUser) << endl;
    return 0;
}
