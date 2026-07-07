#include "casino.h"

random_device dispositivoGlobal;
mt19937 generadorGlobal(dispositivoGlobal());

bool validarApuesta(int apuesta, int saldo, int minimo) {
    bool apuestaValida = true;

    if (apuesta < minimo) {
        apuestaValida = false;
    }

    if (apuesta > saldo) {
        apuestaValida = false;
    }

    return apuestaValida;
}

int generarNumeroAleatorio(int minimo, int maximo) {
    int temporal = 0;

    if (minimo > maximo) {
        temporal = minimo;
        minimo = maximo;
        maximo = temporal;
    }

    uniform_int_distribution<int> distribucion(minimo, maximo);

    return distribucion(generadorGlobal);
}

int cargarSaldoGuardado() {
    ifstream archivo;
    int saldoGuardado = 0;

    archivo.open(RUTA_SALDO);

    if (archivo.is_open()) {
        archivo >> saldoGuardado;
        archivo.close();
    }

    if (saldoGuardado < 0) {
        saldoGuardado = 0;
    }

    return saldoGuardado;
}

void guardarSaldoActual(int saldo) {
    ofstream archivo;

    archivo.open(RUTA_SALDO);

    if (archivo.is_open()) {
        archivo << saldo;
        archivo.close();
    } 
    else {
        cout << "Error al guardar el saldo." << endl;
    }
}