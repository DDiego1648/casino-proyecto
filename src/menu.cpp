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
    int opcionInicio = 0;

    while (opcionInicio != 1 && opcionInicio != 2) {
        cout << "Deseas jugar?" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionInicio;

        if (opcionInicio != 1 && opcionInicio != 2) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
            cout << endl;
        }
    }

    return opcionInicio;
}

void ingresarMontoInicial(int &saldo) {
    int montoIngreso = 0;

    while (montoIngreso <= 0) {
        cout << "Ingrese monto inicial en dolares: ";
        cin >> montoIngreso;

        if (montoIngreso <= 0) {
            cout << "Monto invalido. Debe ingresar un monto mayor a 0." << endl;
            cout << endl;
        }
    }

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
    int opcionMenu = 0;

    while (opcionMenu < 1 || opcionMenu > 7) {
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        if (opcionMenu < 1 || opcionMenu > 7) {
            cout << "Opcion invalida. Debe seleccionar una opcion entre 1 y 7." << endl;
            cout << endl;
        }
    }

    return opcionMenu;
}

void agregarFondos(int &saldo) {
    int montoIngreso = 0;

    cout << endl;
    cout << "============= AGREGAR FONDOS =============" << endl;
    cout << "Saldo actual: " << saldo << " fichas." << endl;
    cout << "Recuerda que: 1 dolar = 1 ficha." << endl;
    cout << "==========================================" << endl;

    while (montoIngreso <= 0) {
        cout << "Ingrese dinero a agregar: ";
        cin >> montoIngreso;

        if (montoIngreso <= 0) {
            cout << "Monto invalido. Debe ingresar un monto mayor a 0." << endl;
            cout << endl;
        }
    }

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