#include <iostream>
using namespace std;

int main(){
    string texto;    
    while (true) {
        cout << "Ingresa una palabra: ";
        cin >> texto;
        if (texto == "exit") {
            break; 
        }
        cout << "La palabra ingresada es: " << texto << endl;
    }
    return 0;
}