#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Ejercicio 1: Validar oferta laboral

int main ()
{
    int yearExperience;
    string educationLevel;

    cout << "Ingrese años de experiencia: ";
    cin >> yearExperience;
    cin.ignore(); 
    cout << "Ingrese su nivel de estudios: (Primaria, Secundaria, Universidad): ";
    getline(cin, educationLevel);
    transform(educationLevel.begin(), educationLevel.end(), educationLevel.begin(), ::tolower);
    //Validar el nivel de estudios segun ingresa el usuario
    string resultado = 
        (yearExperience >= 5 && educationLevel == "universidad") ? "Oferta aprobada!!" :
        (yearExperience >= 3 && yearExperience <= 5 && educationLevel == "secundaria") ? "Oferta aprobada!!" :
        (yearExperience < 3) ? "Oferta no aprobada!" : "Oferta no aprobada!";

    cout << resultado << std::endl;
    system("pause");
    return 0;
}