#include <iostream>
#include <string>
#include <cstdlib>
#include "pedido.h"
using namespace std;


// Prototipos //

void cargarMenu(){
    int tipo, cant; string nombre;
    system("cls");
    cout<<"--- MENU DEL DIA ---\n"
        <<"1) Bebidas   2) Platos   3) Postres\n"
        <<"Tipo: "; cin>>tipo;

    cout<<"Cantidad: "; cin>>cant; cin.ignore();
    for(int i=1;i<=cant;i++){
        cout<<"Nombre "<<i<<": "; getline(cin, nombre);
        switch(tipo){
        case 1: bebidas[cantB++] = nombre; break;
        case 2: platos[cantP++] = nombre; break;
        case 3: postres[cantC++] = nombre; break;
        }
    }
    system("pause");
}

void registrarDatosCliente(){
    system("cls");
    cout<<"--- REGISTRO DE DATOS DEL CLIENTE ---\n";
    DatosCliente& dc = baseClientes[totalClientes];
    cin.ignore();
    cout<<"Nombre completo                 : "; getline(cin, dc.nombre);
    cout<<"Ubicacion preferida de la mesa   : "; getline(cin, dc.ubicacion);
    cout<<"Alergias alimentarias           : "; getline(cin, dc.alergias);
    cout<<"Restriccion dietetica           : "; getline(cin, dc.restriccion);
    cout<<"Dia de cumple (1-31)            : "; cin>>dc.cumpleDia;
    cout<<"Mes de cumple (1-12)            : "; cin>>dc.cumpleMes;
    totalClientes++;
    cout<<"\n✔ Registro guardado.\n";
    system("pause");
}

void pedirPedido(){
    int tipo, nClientes;
    system("cls");
    cout<<"--- TIPO DE PEDIDO ---\n1) Delivery  2) Para la mesa\nElige: ";
    cin>>tipo;

    if(tipo==1){
        cout<<"(Simulacion de delivery sin detalles...)\n";
        system("pause");
        return;
    }
}

bool cumpleañosHoy(const string& nombre, int d, int m){
    for(int i=0;i<totalClientes;i++){
        if(baseClientes[i].nombre == nombre &&
           baseClientes[i].cumpleDia == d &&
           baseClientes[i].cumpleMes == m){
            baseClientes[i].esCumpleHoy = true;
            return true;
        }
    }
    return false;
}
    

    