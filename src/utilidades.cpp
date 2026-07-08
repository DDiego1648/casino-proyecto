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
int leerEntero(const char mensaje[]) {
    int numero;
    bool valido = false;

    while (valido == false) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Entrada invalida. Debe ingresar un numero." << endl;
        }
        else {
            valido = true;
        }
    }

    return numero;
}

int leerEnteroMayorQueCero(const char mensaje[]) {
    int numero = 0;

    while (numero <= 0) {
        numero = leerEntero(mensaje);

        if (numero <= 0) {
            cout << "Valor invalido. Debe ser mayor que cero." << endl;
        }
    }

    return numero;
}

int leerEnteroEnRango(const char mensaje[], int minimo, int maximo) {
    int numero;

    while (true) {
        numero = leerEntero(mensaje);

        if (numero >= minimo && numero <= maximo) {
            return numero;
        }

        cout << "Valor invalido. Debe estar entre ";
        cout << minimo;
        cout << " y ";
        cout << maximo;
        cout << "." << endl;
    }
}