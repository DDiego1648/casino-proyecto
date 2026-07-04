#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream archivo("historial.txt");
    string linea;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();

    return 0;
}
