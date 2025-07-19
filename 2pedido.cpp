#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX = 100;

// Estructuras
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

// Arreglos y contadores
string bebidas[MAX];
string platos[MAX];
string postres[MAX];
int cantBebidas = 0, cantPlatos = 0, cantPostres = 0;

DatosCliente baseClientes[MAX];
int totalClientes = 0;

DatosCliente clientesNavidad[MAX];
int totalNavidad = 0;

DatosCliente clientesHalloween[MAX];
int totalHalloween = 0;

DatosCliente clientesAnioNuevo[MAX];
int totalAnioNuevo = 0;

// Prototipos
void cargarMenu();
void registrarDatosCliente();
void pedirPedido();
bool cumpleañosHoy(const string& nombre, int d, int m);

// Promociones
void verPromoNavidad();
void verPromoHalloween();
void verPromoAnioNuevo();

int main() {
    int op;
    do {
        system("cls");
        cout << "----- MENU DE OPCIONES -----\n"
             << "1) Menu del dia\n"
             << "2) Tipo de pedido\n"
             << "3) Imprimir boleta \n"
             << "4) Datos del cliente\n"
             << "5) Promo Navidad\n"
             << "6) Promo Halloween\n"
             << "7) Promo Año Nuevo\n"
             << "0) Salir\n"
             << "Elige una opcion: ";
        cin >> op;

        switch (op) {
            case 1: cargarMenu(); break;
            case 2: pedirPedido(); break;
            case 4: registrarDatosCliente(); break;
            case 5: verPromoNavidad(); break;
            case 6: verPromoHalloween(); break;
            case 7: verPromoAnioNuevo(); break;
        }
    } while (op != 0);

    return 0;
}


// Cargar menú
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
            case 1:
                if (cantBebidas < MAX) bebidas[cantBebidas++] = nombre;
                break;
            case 2:
                if (cantPlatos < MAX) platos[cantPlatos++] = nombre;
                break;
            case 3:
                if (cantPostres < MAX) postres[cantPostres++] = nombre;
                break;
        }
    }
    system("pause");
}

// Registro de datos del cliente
void registrarDatosCliente() {
    system("cls");
    cout << "--- REGISTRO DE DATOS DEL CLIENTE ---\n";
    DatosCliente dc;
    cin.ignore();
    cout << "Nombre completo                 : "; getline(cin, dc.nombre);
    cout << "Ubicacion preferida de la mesa : "; getline(cin, dc.ubicacion);
    cout << "Dia de cumple (1-31)           : "; cin >> dc.cumpleDia;
    cout << "Mes de cumple (1-12)           : "; cin >> dc.cumpleMes;

    if (totalClientes < MAX) {
        baseClientes[totalClientes++] = dc;
        cout << "\n✔ Registro guardado.\n";
    } else {
        cout << " No se pueden registrar más clientes.\n";
    }
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
    for (int i = 0; i < totalClientes; i++) {
        if (baseClientes[i].nombre == nombre &&
            baseClientes[i].cumpleDia == d &&
            baseClientes[i].cumpleMes == m) {
            baseClientes[i].esCumpleHoy = true;
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

    if (totalNavidad < MAX) {
        clientesNavidad[totalNavidad++] = c;
        cout << " Felices fiestas, recibes una bebida caliente gratis.\n";
    } else {
        cout << " Cupo lleno para promo de Navidad.\n";
    }
    system("pause");
}

void verPromoHalloween() {
    system("cls");
    DatosCliente c;
    cin.ignore();
    cout << "--- PROMOCION HALLOWEEN ---\n";
    cout << "Nombre           : "; getline(cin, c.nombre);
    cout << "Ubicacion mesa   : "; getline(cin, c.ubicacion);

    if (totalHalloween < MAX) {
        clientesHalloween[totalHalloween++] = c;
        cout << " ¡Disfrazado o no, llevas un dulce especial!\n";
    } else {
        cout << " Cupo lleno para promo de Halloween.\n";
    }
    system("pause");
}

void verPromoAnioNuevo() {
    system("cls");
    DatosCliente c;
    cin.ignore();
    cout << "--- PROMOCION AÑO NUEVO ---\n";
    cout << "Nombre           : "; getline(cin, c.nombre);
    cout << "Ubicacion mesa   : "; getline(cin, c.ubicacion);

    if (totalAnioNuevo < MAX) {
        clientesAnioNuevo[totalAnioNuevo++] = c;
        cout << " ¡Feliz año nuevo! Te obsequiamos un brindis de cortesía.\n";
    } else {
        cout << " Cupo lleno para promo de Año Nuevo.\n";
    }
    system("pause");
}
