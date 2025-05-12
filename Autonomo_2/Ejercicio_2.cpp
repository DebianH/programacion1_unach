#include <iostream>
#include <vector>
using namespace std;

// ---------- Función para calcular el promedio ----------
float calculateAverage(const vector<float>& notes) {
    //verifica si el vector está vacío
    if (notes.empty()) return 0.0f;

    float sum = 0;
    for (float note : notes) {
        sum += note;
    }
    return sum / notes.size();
}

// ---------- Función para ingresar notas ----------
void inputNotes(vector<float>& notes) {
    char continueInput;
    do {
        float note;
        cout << "\nIngrese una nota: ";
        cin >> note;

        if (cin.fail()) {
            cin.clear(); // limpiar error
            cin.ignore(1000, '\n'); // descartar entrada inválida
            cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }

        notes.push_back(note);

        cout << "¿Desea ingresar otra nota? (s/n): ";
        cin >> continueInput;

    } while (continueInput == 's' || continueInput == 'S');
}

// ---------- Función para mostrar resultados ----------
void showResult(const vector<float>& notes) {
    float average = calculateAverage(notes);

    cout << "\n===== RESULTADOS =====\n";
    cout << "Notas ingresadas: " << notes.size() << endl;
    cout << "Promedio: " << average << endl;
}

int main() {
    vector<float> notes;
    
    inputNotes(notes);
    showResult(notes);

    return 0;
}
