#include <iostream>

// Ejercicio 4: Validar calificaciones y asistencia

int main() {
    int calificacion, inasistencias;

    std::cout << "Ingrese su calificación: ";
    std::cin >> calificacion;

    std::cout << "Ingrese el número de inasistencias: ";
    std::cin >> inasistencias;

    // Validacion con operadores relacionales
    bool cumpleRequisitos = (calificacion >= 60) && (inasistencias <= 3);

    std::string mensaje = cumpleRequisitos ?
        "¡Felicidades! Has aprobado el curso." :
        "Promedio bajo, no has aprobado el curso.";

    std::cout << mensaje << std::endl;
    system("pause");
    return 0;
}
