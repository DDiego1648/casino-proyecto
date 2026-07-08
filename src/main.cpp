#include "casino.h"

int main() {
    int saldo = 0;
    int saldoGuardado = 0;
    int opcionInicio = 0;
    int opcionMenu = 0;
    bool programaActivo = true;

    mostrarBienvenida();

    opcionInicio = menuInicio();

    if (opcionInicio == 2) {
        cout << "Saliendo del casino. Hasta pronto." << endl;
        return 0;
    }

    saldoGuardado = cargarSaldoGuardado();

    if (saldoGuardado > 0) {
        saldo = saldoGuardado;

        cout << endl;
        cout << "Saldo guardado encontrado." << endl;
        cout << "Tu saldo actual es: " << saldo << " fichas." << endl;
    } 
    else {
        ingresarMontoInicial(saldo);
        guardarSaldoActual(saldo);
    }

    while (programaActivo == true) {
        mostrarMenuPrincipal(saldo);
        opcionMenu = leerOpcionMenu();

        switch (opcionMenu) {
            case 1:
                juegoDados(saldo);
                guardarSaldoActual(saldo);
                break;

            case 2:
                juegoTragamonedas(saldo);
                guardarSaldoActual(saldo);
                break;

            case 3:
                juegoRuleta(saldo);
                guardarSaldoActual(saldo);
                break;

            case 4:
                juegoBlackjack(saldo);
                guardarSaldoActual(saldo);
                break;

            case 5:
                verHistorial();
                break;

            case 6:
                agregarFondos(saldo);
                guardarSaldoActual(saldo);
                break;

            case 7:
                guardarSaldoActual(saldo);
                salirCasino(saldo);
                programaActivo = false;
                break;

            default:
                cout << "Opcion invalida. Regresando al menu principal." << endl;
                break;
        }
    }

    return 0;
}