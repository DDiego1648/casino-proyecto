#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int saldo = 100;
    int apuesta, numeroUsuario, numeroGanador;

    srand(time(0));

    cout << "Ingrese la apuesta: ";
    cin >> apuesta;

    cout << "Ingrese un numero del 1 al 10: ";
    cin >> numeroUsuario;

    numeroGanador = rand() % 10 + 1;

    cout << "Numero ganador: " << numeroGanador << endl;

    if (numeroUsuario == numeroGanador) {
        saldo = saldo + apuesta * 5;
        cout << "¡Ganaste!" << endl;
    } else {
        saldo = saldo - apuesta;
        cout << "Perdiste." << endl;
    }

    ofstream archivo("historial.txt", ios::app);

    archivo << "Apuesta: " << apuesta
            << " | Numero elegido: " << numeroUsuario
            << " | Numero ganador: " << numeroGanador
            << " | Saldo: " << saldo << endl;

    archivo.close();

    return 0;
}
