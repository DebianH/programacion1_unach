#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mainDish;
    string dayOfWeek;
    float price = 0;
    float discount = 0;

    // Entrada del usuario
    cout << "Dijite su plato (pollo, carne, pescado): ";
    cin >> mainDish;

    cout << "Ingrese el dia de la semana: ";
    cin >> dayOfWeek;

    // Comparamos con el menu
    if (mainDish == "pollo") {
        price = 10;
    } else if (mainDish == "carne") {
        price = 15;
    } else if (mainDish == "pescado") {
        price = 20;
    } else {
        cout << "Menú invalido." << endl;
        return 1;
    }

    // Aplicar descuentos según el día
    if (dayOfWeek == "lunes" || dayOfWeek == "miercoles") {
        discount = 0.10; 
    } else if (dayOfWeek == "viernes" && mainDish == "carne") {
        discount = 0.15; 
        
    }

    float total = price * (1 - discount);

    cout << "Total a pagar: $" << total << endl;
    
    system("pause");

    return 0;
}
