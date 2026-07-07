#include "casino.h"

void juegoRuleta(int &saldo) {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        cout << endl;
        cout << "======================" << endl;
        cout << "        RULETA        " << endl;
        cout << "======================" << endl;

        if (saldo < APUESTA_MIN_RULETA) {
            cout << "Fondos insuficientes para jugar ruleta." << endl;
            cout << "Necesitas al menos " << APUESTA_MIN_RULETA << " fichas." << endl;
            return;
        }

        int apuesta = 0;
        int numeroUsuario = 0;
        int numeroGanador = 0;
        int premio = 0;
        int gananciaPerdida = 0;
        string resultado = "";

        while (validarApuesta(apuesta, saldo, APUESTA_MIN_RULETA) == false) {
            cout << "Ingrese la apuesta minima de " << APUESTA_MIN_RULETA << " fichas: ";
            cin >> apuesta;

            if (validarApuesta(apuesta, saldo, APUESTA_MIN_RULETA) == false) {
                cout << "Apuesta invalida." << endl;
                cout << "La apuesta debe ser minimo " << APUESTA_MIN_RULETA;
                cout << " y no puede ser mayor que tu saldo." << endl;
                cout << endl;
            }
        }

        while (numeroUsuario < 1 || numeroUsuario > 10) {
            cout << "Ingrese un numero del 1 al 10: ";
            cin >> numeroUsuario;

            if (numeroUsuario < 1 || numeroUsuario > 10) {
                cout << "Numero invalido. Debe estar entre 1 y 10." << endl;
                cout << endl;
            }
        }

        numeroGanador = generarNumeroAleatorio(1, 10);

        cout << endl;
        cout << "Numero elegido: " << numeroUsuario << endl;
        cout << "Numero ganador: " << numeroGanador << endl;

        if (numeroUsuario == numeroGanador) {
            premio = apuesta * 5;
            saldo = saldo + premio;
            gananciaPerdida = premio;
            resultado = "Gano";

            cout << "Ganaste la ruleta." << endl;
            cout << "Premio: " << premio << " fichas." << endl;
        } 
        else {
            saldo = saldo - apuesta;
            gananciaPerdida = -apuesta;
            resultado = "Perdio";

            cout << "Perdiste la ruleta." << endl;
            cout << "Perdiste: " << apuesta << " fichas." << endl;
        }

        cout << "Saldo actual: " << saldo << " fichas." << endl;

        guardarHistorial("Ruleta", apuesta, resultado, gananciaPerdida, saldo);

        cout << endl;
        cout << "Deseas volver a jugar ruleta? s/n: ";
        cin >> repetir;
    }
}