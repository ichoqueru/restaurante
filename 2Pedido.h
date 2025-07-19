#ifndef  Pedido_h
#define Pedido_h
#include<iostream>
#include <vector>
#include<string>
#include "cliente.h"
using namespace std;


struct ClienteMesa {
    string nom;
    int mesa;
};

struct DatosCliente {
    string nombre;
    string ubicacion;
    int cumpleDia;
    int cumpleMes;
    bool esCumpleHoy = false;
};





void cargarMenu();
void registrarDatosCliente();             
void pedirPedido();
bool cumpleañosHoy(const string& nombre, int d, int m); 

void verPromoNavidad();
void verPromoHalloween();
void verPromoAnioNuevo();

#endif