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