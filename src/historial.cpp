#include "casino.h"

void guardarHistorial(string juego, int apuesta, string resultado, int gananciaPerdida, int saldoFinal) {
    ofstream archivo;

    archivo.open(RUTA_HISTORIAL, ios::app);

    if (archivo.is_open()) {
        archivo << "Juego: " << juego << endl;
        archivo << "Apuesta/Costo: " << apuesta << " fichas" << endl;
        archivo << "Resultado: " << resultado << endl;
        archivo << "Ganancia/Perdida: " << gananciaPerdida << " fichas" << endl;
        archivo << "Saldo final: " << saldoFinal << " fichas" << endl;
        archivo << "----------------------------------------" << endl;

        archivo.close();
    } 
    else {
        cout << "Error al abrir el archivo de historial." << endl;
    }
}

void verHistorial() {
    ifstream archivo;
    string linea;
    bool hayHistorial = false;

    archivo.open(RUTA_HISTORIAL);

    cout << endl;
    cout << "============== HISTORIAL ==============" << endl;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
            hayHistorial = true;
        }

        archivo.close();

        if (hayHistorial == false) {
            cout << "No hay historial de partidas." << endl;
        }
    } 
    else {
        cout << "No hay historial de partidas." << endl;
    }

    cout << "=======================================" << endl;
}