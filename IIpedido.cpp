#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "pedido.h"
using namespace std;


// Prototipos//

void cargarMenu() {
    int tipo, cant;
    string nombre;
    system("cls");
    cout << "--- MENU DEL DIA ---\n"
         << "1) Bebidas   2) Platos   3) Postres\n"
         << "Tipo: ";
    cin >> tipo;

    cout << "Cantidad: ";
    cin >> cant;
    cin.ignore();
    for (int i = 1; i <= cant; i++) {
        cout << "Nombre " << i << ": ";
        getline(cin, nombre);
        switch (tipo) {
            case 1: bebidas.push_back(nombre); break;
            case 2: platos.push_back(nombre); break;
            case 3: postres.push_back(nombre); break;
        }
    }
    system("pause");
}

void registrarDatosCliente() {
    system("cls");
    cout << "--- REGISTRO DE DATOS DEL CLIENTE ---\n";
    DatosCliente dc;
    cin.ignore();
    cout << "Nombre completo                 : "; getline(cin, dc.nombre);
    cout << "Ubicacion preferida de la mesa : "; getline(cin, dc.ubicacion);
    cout << "Dia de cumple (1-31)           : "; cin >> dc.cumpleDia;
    cout << "Mes de cumple (1-12)           : "; cin >> dc.cumpleMes;

    baseClientes.push_back(dc);
    cout << "\n✔ Registro guardado.\n";
    system("pause");
}

void pedirPedido() {
    int tipo, nClientes;
    system("cls");
    cout << "--- TIPO DE PEDIDO ---\n1) Delivery  2) Para la mesa\nElige: ";
    cin >> tipo;

    if (tipo == 1) {
        cout << "(Simulacion de delivery sin detalles...)\n";
        system("pause");
        return;
    }

    cout << "Cantidad de clientes: ";
    cin >> nClientes;
    int dia, mes;
    cout << "Fecha de hoy (d m): ";
    cin >> dia >> mes;

    for (int i = 0; i < nClientes; i++) {
        ClienteMesa c;
        cin.ignore();
        cout << "\nCliente " << i + 1 << " - Nombre : ";
        getline(cin, c.nom);
        cout << "Número de mesa: ";
        cin >> c.mesa;

        if (cumpleañosHoy(c.nom, dia, mes)) {
            cout << "¡Feliz cumpleaños! Obtiene un postre gratis.\n";
        }
    }
    system("pause");
}

bool cumpleañosHoy(const string& nombre, int d, int m) {
    for (auto& dc : baseClientes) {
        if (dc.nombre == nombre && dc.cumpleDia == d && dc.cumpleMes == m) {
            dc.esCumpleHoy = true;
            return true;
        }
    }
    return false;
}

void verPromoNavidad() {
    system("cls");
    DatosCliente c;
    cin.ignore();
    cout << "--- PROMOCION NAVIDAD ---\n";
    cout << "Nombre           : "; getline(cin, c.nombre);
    cout << "Ubicacion mesa   : "; getline(cin, c.ubicacion);
    clientesNavidad.push_back(c);
    cout << "Felices fiestas, recibes una comida gratis.\n";
    system("pause");
}


void verPromoHalloween() {
    system("cls");
    DatosCliente c;
    cin.ignore();
    cout << "--- PROMOCION HALLOWEEN ---\n";
    cout << "Nombre           : "; getline(cin, c.nombre);
    cout << "Ubicacion mesa   : "; getline(cin, c.ubicacion);
    clientesHalloween.push_back(c);
    cout << "¡Recibes una bebida gratis!\n";
    system("pause");
}

void verPromoAnioNuevo() {
    system("cls");
    DatosCliente c;
    cin.ignore();
    cout << "--- PROMOCION AÑO NUEVO ---\n";
    cout << "Nombre           : "; getline(cin, c.nombre);
    cout << "Ubicacion mesa   : "; getline(cin, c.ubicacion);
    clientesAnioNuevo.push_back(c);
    cout << "¡Feliz año nuevo! Recibes un postre gratis.\n";
    system("pause");
}
