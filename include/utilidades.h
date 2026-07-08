#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <random>

using namespace std;

const int APUESTA_MIN_DADOS = 5;
const int APUESTA_MIN_RULETA = 10;
const int APUESTA_MIN_BLACKJACK = 5;
const int COSTO_TRAGAMONEDAS = 1;

const char RUTA_HISTORIAL[] = "data/historial.txt";
const char RUTA_SALDO[] = "data/saldo.txt";

bool validarApuesta(int apuesta, int saldo, int minimo);
int generarNumeroAleatorio(int minimo, int maximo);

int cargarSaldoGuardado();
void guardarSaldoActual(int saldo);

int leerEntero(const char mensaje[]);
int leerEnteroMayorQueCero(const char mensaje[]);
int leerEnteroEnRango(const char mensaje[], int minimo, int maximo);

#endif