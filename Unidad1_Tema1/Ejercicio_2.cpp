#include <iostream>

const double PI = 3.14159;

// Ejercicio 2: Calcular el volumen de un cilindro
double radio = 5.0; 

int main() {
    double altura;
    double volumen;

    std::cout << "Ingrese la altura del cilindro: ";
    std::cin >> altura;

    // Aplicamos la formula: V = π * radio² * altura nos proporcionan en el requerimiento
    volumen = PI * radio * radio * altura;

    std::cout << "El volumen del cilindro es: " << volumen << std::endl;
    system("pause");
    return 0;
}
