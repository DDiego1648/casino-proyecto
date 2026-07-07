#include "casino.h"

int main() {
    int saldo = 0;
    int opcionInicio = 0;
    int opcionMenu = 0;
    bool programaActivo = true;

    mostrarBienvenida();

    opcionInicio = menuInicio();

    if (opcionInicio == 2) {
        cout << "Saliendo del casino. Hasta pronto." << endl;
        return 0;
    }

    ingresarMontoInicial(saldo);

    while (programaActivo == true) {
        mostrarMenuPrincipal(saldo);
        opcionMenu = leerOpcionMenu();

       switch (opcionMenu) {
    case 1:
        juegoDados(saldo);
        break;

    case 2:
        juegoTragamonedas(saldo);
        break;

    case 3:
        juegoRuleta(saldo);
        break;

    case 4:
        juegoBlackjack(saldo);
        break;

    case 5:
        verHistorial();
        break;

    case 6:
        agregarFondos(saldo);
        break;

    case 7:
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
