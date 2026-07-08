#include "casino.h"

void mostrarBienvenida() {
    cout << endl;
    cout << "========================================" << endl;
    cout << "          BIENVENIDO AL CASINO          " << endl;
    cout << "========================================" << endl;
    cout << "Tenemos una gran variedad de juegos." << endl;
    cout << "Puedes ganar excelentes recompensas." << endl;
    cout << "Ten en cuenta que: 1 dolar = 1 ficha." << endl;
    cout << "========================================" << endl;
    cout << endl;
}

int menuInicio() {
    int opcionInicio;

    cout << "Deseas jugar?" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Salir" << endl;

    opcionInicio =
        leerEnteroEnRango(
            "Seleccione una opcion: ",
            1,
            2
        );

    return opcionInicio;
}

void ingresarMontoInicial(int &saldo) {
    int montoIngreso;

    montoIngreso =
        leerEnteroMayorQueCero(
            "Ingrese monto inicial en dolares: "
        );

    saldo = montoIngreso;

    cout << endl;
    cout << "Fondos agregados correctamente." << endl;
    cout << "Saldo actual: " << saldo << " fichas." << endl;
}

void mostrarMenuPrincipal(int saldo) {
    cout << endl;
    cout << "============== MENU PRINCIPAL ==============" << endl;
    cout << "Saldo actual: " << saldo << " fichas" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Dados" << endl;
    cout << "2. Tragamonedas" << endl;
    cout << "3. Ruleta" << endl;
    cout << "4. Blackjack" << endl;
    cout << "5. Historial" << endl;
    cout << "6. Agregar fondos" << endl;
    cout << "7. Salir" << endl;
    cout << "============================================" << endl;
}

int leerOpcionMenu() {
    return leerEnteroEnRango(
        "Seleccione una opcion: ",
        1,
        7
    );
}

void agregarFondos(int &saldo) {
    int montoIngreso;

    cout << endl;
    cout << "============= AGREGAR FONDOS =============" << endl;
    cout << "Saldo actual: " << saldo << " fichas." << endl;
    cout << "==========================================" << endl;

    montoIngreso =
        leerEnteroMayorQueCero(
            "Ingrese dinero a agregar: "
        );

    saldo = saldo + montoIngreso;

    cout << endl;
    cout << "Fondos agregados correctamente." << endl;
    cout << "Nuevo saldo: " << saldo << " fichas." << endl;
}

void salirCasino(int saldo) {
    cout << endl;
    cout << "========================================" << endl;
    cout << "          SALIENDO DEL CASINO           " << endl;
    cout << "========================================" << endl;
    cout << "Hasta pronto." << endl;
    cout << "Saldo final: " << saldo << " fichas." << endl;
    cout << "========================================" << endl;
}