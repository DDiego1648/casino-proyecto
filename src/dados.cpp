#include "casino.h"

void juegoDados(int &saldo) {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        cout << endl;
        cout << "======================" << endl;
        cout << "     JUEGO DE DADOS   " << endl;
        cout << "======================" << endl;

        if (saldo < APUESTA_MIN_DADOS) {
            cout << "Fondos insuficientes para jugar dados." << endl;
            cout << "Necesitas al menos " << APUESTA_MIN_DADOS << " fichas." << endl;
            return;
        }

        int apuesta = 0;
        int dado1 = 0;
        int dado2 = 0;
        int suma = 0;
        int gananciaPerdida = 0;
        string resultado = "";

        while (validarApuesta(apuesta, saldo, APUESTA_MIN_DADOS) == false) {
            cout << "Ingrese la apuesta minima de " << APUESTA_MIN_DADOS << " fichas: ";
            cin >> apuesta;

            if (validarApuesta(apuesta, saldo, APUESTA_MIN_DADOS) == false) {
                cout << "Apuesta invalida." << endl;
                cout << "La apuesta debe ser minimo " << APUESTA_MIN_DADOS;
                cout << " y no puede ser mayor que tu saldo." << endl;
                cout << endl;
            }
        }

        dado1 = generarNumeroAleatorio(1, 6);
        dado2 = generarNumeroAleatorio(1, 6);
        suma = dado1 + dado2;

        cout << endl;
        cout << "Dado 1: " << dado1 << endl;
        cout << "Dado 2: " << dado2 << endl;
        cout << "Suma: " << suma << endl;

        if (suma == 7 || suma == 11) {
            saldo = saldo + apuesta;
            gananciaPerdida = apuesta;
            resultado = "Gano";

            cout << "Ganaste el juego de dados." << endl;
            cout << "Ganancia: " << apuesta << " fichas." << endl;
        } 
        else {
            saldo = saldo - apuesta;
            gananciaPerdida = -apuesta;
            resultado = "Perdio";

            cout << "Perdiste el juego de dados." << endl;
            cout << "Perdida: " << apuesta << " fichas." << endl;
        }

        cout << "Saldo actual: " << saldo << " fichas." << endl;

        guardarHistorial("Dados", apuesta, resultado, gananciaPerdida, saldo);

        cout << endl;
        cout << "Deseas volver a jugar dados? s/n: ";
        cin >> repetir;
    }
}