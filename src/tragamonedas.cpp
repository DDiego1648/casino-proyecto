#include "casino.h"

void juegoTragamonedas(int &saldo) {
    char repetir = 's';

    while (repetir == 's' || repetir == 'S') {
        cout << endl;
        cout << "======================" << endl;
        cout << "     TRAGAMONEDAS     " << endl;
        cout << "======================" << endl;

        if (saldo < COSTO_TRAGAMONEDAS) {
            cout << "Fondos insuficientes para jugar tragamonedas." << endl;
            cout << "Necesitas al menos " << COSTO_TRAGAMONEDAS << " ficha." << endl;
            return;
        }

        saldo = saldo - COSTO_TRAGAMONEDAS;

        string letras[5] = {"A", "B", "C", "D", "E"};
        string jugada[3];

        for (int i = 0; i < 3; i++) {
            int posicion = generarNumeroAleatorio(0, 4);
            jugada[i] = letras[posicion];
        }

        cout << "Resultado: ";

        for (int i = 0; i < 3; i++) {
            cout << jugada[i] << " ";
        }

        cout << endl;

        int premio = 0;
        int gananciaPerdida = 0;
        string resultado = "";

        if (jugada[0] == jugada[1] && jugada[1] == jugada[2]) {
            premio = 10;
            saldo = saldo + premio;
            gananciaPerdida = premio - COSTO_TRAGAMONEDAS;
            resultado = "Gano";

            cout << "Ganaste triple." << endl;
            cout << "Premio: " << premio << " fichas." << endl;
        } 
        else if (jugada[0] == jugada[1] || jugada[0] == jugada[2] || jugada[1] == jugada[2]) {
            premio = 2;
            saldo = saldo + premio;
            gananciaPerdida = premio - COSTO_TRAGAMONEDAS;
            resultado = "Gano";

            cout << "Dos letras iguales." << endl;
            cout << "Premio: " << premio << " fichas." << endl;
        } 
        else {
            premio = 0;
            gananciaPerdida = -COSTO_TRAGAMONEDAS;
            resultado = "Perdio";

            cout << "Perdiste la jugada." << endl;
            cout << "Premio: " << premio << " fichas." << endl;
        }

        cout << "Saldo actual: " << saldo << " fichas." << endl;

        guardarHistorial("Tragamonedas", COSTO_TRAGAMONEDAS, resultado, gananciaPerdida, saldo);

        cout << endl;
        cout << "Deseas volver a jugar tragamonedas? s/n: ";
        cin >> repetir;
    }
}