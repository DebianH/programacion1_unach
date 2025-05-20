# include <iostream>
using namespace std;


int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}


int main() {
    int numUser;
    cout << "Ingrese un numero para factorial!" << endl;
    cin >> numUser;
    cout << "El factorial de " << numUser << " es " << factorial(numUser) << endl;
    return 0;
}