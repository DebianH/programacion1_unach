//--DESCRIPCIÓN DEL PROYECTO--
/*
Este software permite gestionar múltiples usuarios, a cada uno se le pueden asociar diferentes URLs. El sistema ofrece funciones para crear usuarios, agregarles enlaces web, mostrar sus URLs, obtener estadísticas como promedio, usuarios con más o menos URLs, y diferenciar entre números pares e impares. También se puede eliminar un usuario del sistema. Todo se gestiona mediante un menú interactivo con validación de entradas y uso de memoria dinámica.
*/
#include <iostream>
#include <string>

using namespace std;

// Estructura para representar un usuario y sus URLs
struct Usuario {
    string nombre;
    string* urls;
    int cantidadUrls;
};

// Prototipos de funciones -- para que no de error al compilar
void mostrarMenu();
int obtenerOpcionValida(int min, int max);
void crearUsuario(Usuario*& usuarios, int& totalUsuarios);
void agregarURL(Usuario*& usuarios, int totalUsuarios);
void mostrarURLs(Usuario* usuarios, int totalUsuarios);
void estadisticasUsuarios(Usuario* usuarios, int totalUsuarios);
void borrarUsuario(Usuario*& usuarios, int& totalUsuarios);

int main() {
    Usuario* usuarios = nullptr;
    int totalUsuarios = 0;
    int opcion;

    do {
        mostrarMenu();
        opcion = obtenerOpcionValida(1, 6); // Cambiado a 6 para incluir la opción extra

        switch (opcion) {
            case 1: crearUsuario(usuarios, totalUsuarios); break;
            case 2: agregarURL(usuarios, totalUsuarios); break;
            case 3: mostrarURLs(usuarios, totalUsuarios); break;
            case 4: estadisticasUsuarios(usuarios, totalUsuarios); break;
            case 5: cout << "Saliendo del programa.\n"; break;
            case 6: borrarUsuario(usuarios, totalUsuarios); break; // Extra
            default: cout << "Opcion no valida. Intente nuevamente.\n"; break;
        }

        cout << endl;
    } while (opcion != 6);

    return 0;
}

// Funciones de menú
void mostrarMenu() {
    cout << "|------ MENU PRINCIPAL ------|\n\n";

    cout << "1. Crear nuevo usuario\n";
    cout << "2. Agregar URL a un usuario\n";
    cout << "3. Mostrar URLs por usuario\n";
    cout << "4. Ver estadisticas\n";
    cout << "5. Salir\n";
    cout << "6. Borrar usuario (*Extra)\n";
    cout << "Ingrese una opcion: ";
}
// Función para obtener una opción válida del usuario
int obtenerOpcionValida(int min, int max) {
    int opcion;
    // Bucle para asegurarse de que la opción ingresada sea válida
    while (!(cin >> opcion) || opcion < min || opcion > max) {
        cout << "Opcion invalida. Intente nuevamente: ";
        cin.clear();
        // Limpiar el buffer de entrada para evitar problemas con entradas inválidas
        cin.ignore(10, '\n');
    }
    cin.ignore();
    return opcion;
}

// Crear usuario
void crearUsuario(Usuario*& usuarios, int& totalUsuarios) {
    cout << "Ingrese el nombre del nuevo usuario: ";
    string nombre;
    getline(cin, nombre);

    if (nombre.empty()) {
        cout << "Nombre no valido.\n";
        return;
    }
    // Verificar si el usuario ya existe
    Usuario* nuevoArreglo = new Usuario[totalUsuarios + 1];
    for (int i = 0; i < totalUsuarios; ++i) {
        nuevoArreglo[i] = usuarios[i];
    }

    nuevoArreglo[totalUsuarios].nombre = nombre;
    nuevoArreglo[totalUsuarios].urls = nullptr; // Inicializamos el puntero a URLs como nullptr o null que es lo mismo
    nuevoArreglo[totalUsuarios].cantidadUrls = 0;

    usuarios = nuevoArreglo;
    totalUsuarios++;

    cout << "Usuario creado exitosamente.\n";
}

// Agregar URL a un usuario
void agregarURL(Usuario*& usuarios, int totalUsuarios) {
    if (totalUsuarios == 0) {
        cout << "No hay usuarios creados \n";
        return;
    }

    cout << "Ingrese el numero del usuario: \n";
    for (int i = 0; i < totalUsuarios; ++i) {
        cout << i + 1 << ". " << usuarios[i].nombre << endl;
    }

    int index = obtenerOpcionValida(1, totalUsuarios) - 1;

    cout << "Ingrese la URL: ";
    string nuevaURL;
    getline(cin, nuevaURL);

    if (nuevaURL.empty()) {
        cout << "URL vacia. No se guardara.\n";
        return;
    }
    //Utizo para trabjar directamente con el array Ojo <-
    Usuario& u = usuarios[index];
    string* nuevasUrls = new string[u.cantidadUrls + 1];
    for (int i = 0; i < u.cantidadUrls; ++i) {
        nuevasUrls[i] = u.urls[i];
    }
    nuevasUrls[u.cantidadUrls] = nuevaURL;
    // Con esto liberamos memoria del array anterior
    delete[] u.urls;
    u.urls = nuevasUrls;
    u.cantidadUrls++;

    cout << "URL agregada a " << u.nombre << " correctamente \n";
}

// Mostrar URLs de cada usuario
void mostrarURLs(Usuario* usuarios, int totalUsuarios) {
    if (totalUsuarios == 0) {
        cout << "No hay usuarios registrados \n";
        return;
    }

    for (int i = 0; i < totalUsuarios; ++i) {
        cout << "\nUsuario: " << usuarios[i].nombre << endl;
        if (usuarios[i].cantidadUrls == 0) {
            cout << "  No tiene URLs registradas.\n";
        } else {
            for (int j = 0; j < usuarios[i].cantidadUrls; ++j) {
                cout << "  " << j + 1 << ". " << usuarios[i].urls[j] << endl;
            }
        }
    }
}

// Estadísticas de usuarios - Promedio, máximo, mínimo, pares e impares
void estadisticasUsuarios(Usuario* usuarios, int totalUsuarios) {
    if (totalUsuarios == 0) {
        cout << "No hay datos para mostrar.\n";
        return;
    }

    int suma = 0;
    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < totalUsuarios; ++i) {
        suma += usuarios[i].cantidadUrls;
        if (usuarios[i].cantidadUrls < usuarios[minIndex].cantidadUrls)
            minIndex = i;
        if (usuarios[i].cantidadUrls > usuarios[maxIndex].cantidadUrls)
            maxIndex = i;
    }

    double promedio = static_cast<double>(suma) / totalUsuarios;

    cout << "\n|--- ESTADISTICAS ---|\n";
    cout << "Promedio de URLs por usuario: " << promedio << endl;
    cout << "Usuario con MAS URLs: " << usuarios[maxIndex].nombre << " (" << usuarios[maxIndex].cantidadUrls << ")\n";
    cout << "Usuario con MENOS URLs: " << usuarios[minIndex].nombre << " (" << usuarios[minIndex].cantidadUrls << ")\n";

    cout << "\nUsuarios con numero PAR de URLs:\n";
    // Recorremos el array de usuarios y mostramos los que tienen un numero par de URLs
    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i].cantidadUrls % 2 == 0)
            cout << "  " << usuarios[i].nombre << " (" << usuarios[i].cantidadUrls << ")\n";
    }

    cout << "Usuarios con numero IMPAR de URLs:\n";
    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i].cantidadUrls % 2 != 0)
            cout << "  " << usuarios[i].nombre << " (" << usuarios[i].cantidadUrls << ")\n";
    }
}

//FFUNCION EXTRA

void borrarUsuario(Usuario*& usuarios, int& totalUsuarios) {
    if (totalUsuarios == 0) {
        cout << "No hay usuarios registrados.\n";
        return;
    }

    cout << "Seleccione el número del usuario que desea eliminar:\n";
    for (int i = 0; i < totalUsuarios; ++i) {
        cout << i + 1 << ". " << usuarios[i].nombre << endl;
    }

    int index = obtenerOpcionValida(1, totalUsuarios) - 1;

    // Liberar memoria de URLs del usuario
    delete[] usuarios[index].urls;

    // Mover los usuarios siguientes hacia arriba
    for (int i = index; i < totalUsuarios - 1; ++i) {
        usuarios[i] = usuarios[i + 1];
    }

    // Crear nuevo arreglo con un espacio menos
    Usuario* nuevoArreglo = new Usuario[totalUsuarios - 1];
    for (int i = 0; i < totalUsuarios - 1; ++i) {
        nuevoArreglo[i] = usuarios[i];
    }

    // Liberar arreglo anterior
    delete[] usuarios;

    usuarios = nuevoArreglo;
    totalUsuarios--;

    cout << "Usuario eliminado correctamente.\n";
}
