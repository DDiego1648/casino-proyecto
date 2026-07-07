#include "casino.h"

void juegoBlackjack(int &saldo) {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        cout << endl;
        cout << "======================" << endl;
        cout << "       BLACKJACK      " << endl;
        cout << "======================" << endl;
        cout << "Descripcion: Debes acercarte a 21 sin pasarte." << endl;
        cout << "Si superas 21, pierdes automaticamente." << endl;
        cout << "Ganas si tienes mas puntos que la casa." << endl;
        cout << endl;

        if (saldo < APUESTA_MIN_BLACKJACK) {
            cout << "Fondos insuficientes para jugar Blackjack." << endl;
            cout << "Necesitas al menos " << APUESTA_MIN_BLACKJACK << " fichas." << endl;
            return;
        }

        int apuesta = 0;
        int carta = 0;
        int puntosJugador = 0;
        int puntosCasa = 0;
        int gananciaPerdida = 0;
        string resultado = "";
        char opcion = 's';

        while (validarApuesta(apuesta, saldo, APUESTA_MIN_BLACKJACK) == false) {
            cout << "Ingrese la apuesta minima de " << APUESTA_MIN_BLACKJACK << " fichas: ";
            cin >> apuesta;

            if (validarApuesta(apuesta, saldo, APUESTA_MIN_BLACKJACK) == false) {
                cout << "Apuesta invalida." << endl;
                cout << "La apuesta debe ser minimo " << APUESTA_MIN_BLACKJACK;
                cout << " y no puede ser mayor que tu saldo." << endl;
                cout << endl;
            }
        }

        carta = generarNumeroAleatorio(1, 11);
        puntosJugador = puntosJugador + carta;

        carta = generarNumeroAleatorio(1, 11);
        puntosJugador = puntosJugador + carta;

        cout << "Tus puntos iniciales: " << puntosJugador << endl;

        while (puntosJugador < 21 && opcion != 'n' && opcion != 'N') {
            cout << "Deseas pedir otra carta? s/n: ";
            cin >> opcion;

            if (opcion == 's' || opcion == 'S') {
                carta = generarNumeroAleatorio(1, 11);
                puntosJugador = puntosJugador + carta;

                cout << "Carta recibida: " << carta << endl;
                cout << "Tus puntos actuales: " << puntosJugador << endl;
            }
        }

        if (puntosJugador > 21) {
            saldo = saldo - apuesta;
            gananciaPerdida = -apuesta;
            resultado = "Perdio";

            cout << endl;
            cout << "Te pasaste de 21." << endl;
            cout << "Perdiste " << apuesta << " fichas." << endl;
        } 
        else {
            while (puntosCasa < 17) {
                carta = generarNumeroAleatorio(1, 11);
                puntosCasa = puntosCasa + carta;
            }

            cout << endl;
            cout << "Tus puntos finales: " << puntosJugador << endl;
            cout << "Puntos de la casa: " << puntosCasa << endl;

            if (puntosCasa > 21) {
                saldo = saldo + apuesta;
                gananciaPerdida = apuesta;
                resultado = "Gano";

                cout << "La casa se paso de 21." << endl;
                cout << "Ganaste " << apuesta << " fichas." << endl;
            }
            else if (puntosJugador > puntosCasa) {
                saldo = saldo + apuesta;
                gananciaPerdida = apuesta;
                resultado = "Gano";

                cout << "Ganaste Blackjack." << endl;
                cout << "Ganaste " << apuesta << " fichas." << endl;
            }
            else if (puntosJugador == puntosCasa) {
                gananciaPerdida = 0;
                resultado = "Empate";

                cout << "Empate. No ganas ni pierdes fichas." << endl;
            }
            else {
                saldo = saldo - apuesta;
                gananciaPerdida = -apuesta;
                resultado = "Perdio";

                cout << "Perdiste Blackjack." << endl;
                cout << "Perdiste " << apuesta << " fichas." << endl;
            }
        }

        cout << "Saldo actual: " << saldo << " fichas." << endl;

        guardarHistorial("Blackjack", apuesta, resultado, gananciaPerdida, saldo);

        cout << endl;
        cout << "Deseas volver a jugar Blackjack? s/n: ";
        cin >> repetir;
    }
}