#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {   

    string performance;
    int qualification;
    int experencia = 0;
    int salario = 0;
    float bono = 0;

    cout << "Ingrese el salario: "<< endl;
    cin >> salario;
    cout << "Ingrese years de experiencia: "<< endl;
    cin >> experencia;
    cout << "Ingrese la calificacion del 0 a 100: "<< endl;
    cin >> qualification;

    if(qualification > 100 || qualification < 0){
        cout << "Calificacion no valida" << endl;
        return 1;
    }

    performance = (qualification >= 90) ? "Excelente" :
                  (qualification >= 70) ? "Bueno" : "Necesita Mejora";

    if(experencia > 3){
        bono += salario * 0.10;
    } else if (experencia > 1 && experencia <= 3){
        bono += salario * 0.05;
    } else {
        bono = 0;
    }

    cout << "El bono es: " << bono << endl;
    cout << "El rendimiento: " << performance << endl;
    cout << "El salario total es: " << salario + bono << endl;

    system("pause");
    return 0;
}