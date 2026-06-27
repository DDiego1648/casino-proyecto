#ifndef MENU_H
#define MENU_H

void mostrarBienvenida();
int menuInicio();
void ingresarMontoInicial(int &saldo);
void mostrarMenuPrincipal(int saldo);
int leerOpcionMenu();
void agregarFondos(int &saldo);
void salirCasino(int saldo);

#endif