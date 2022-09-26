#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "usersFileManager.h"
#include "busFileManager.h"
#include "Classes.h"
#include "DLL.h"
using namespace std;
class Consola {
private:
    User* new_user;
    vector<User*> vecUsers;
    UsersFileManager* uFile;
    BusFileManager* bFile;
    DLL <Bus*> BusList;
public:
    Consola() {
        BusList = DLL<Bus*>();
        new_user = new User();
        uFile = new UsersFileManager();
        bFile = new BusFileManager();
    }
    ~Consola() {}

    User* buscarCuentaPorUsuario(string user) {
        User* buscada = nullptr;
        for_each(vecUsers.begin(), vecUsers.end(), [=, &buscada](User* cuenta) {
            if (user == cuenta->getUserName()) {
                buscada = cuenta;
            }
            });
        return buscada;
    }

    User* verificarSesion(string user, string password) {
        User* cuentaObjetivo = buscarCuentaPorUsuario(user);
        if (cuentaObjetivo != nullptr &&
            cuentaObjetivo->getPassword() == password) {
            return cuentaObjetivo;
        }
        return nullptr;
    }

    void init() {
        int opcion;
        User* cuenta;
        do {
            system("cls");
            cout << "\t\t[Bienvenido a Turismo Dias]" << endl;
            cout << "[1] Iniciar Sesion" << endl;
            cout << "[2] Registrar" << endl;
            cout << "[3] Salir" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
                system("cls");
                cuenta = iniciarSesion();
                if (cuenta != nullptr)
                    home(cuenta);
                if (cuenta == nullptr) {
                    cout << "\nUsuario o contrasena incorrecta" << '\n';
                }
                break;
            case 2:
                system("cls");
                registrarUsuario();
                uFile->writeUserFile(vecUsers);
                break;
            case 3:
                cout << "///GRACIAS POR USAR TURISMO DIAS///" << endl;
                cout << "///GRACIAS POR USAR TURISMO DIAS///" << endl;
                cout << "///GRACIAS POR USAR TURISMO DIAS///" << endl;
                cout << "///GRACIAS POR USAR TURISMO DIAS///" << endl;
                break;
            }
        } while (opcion != 3);
        
    }

    void registrarUsuario() {
        system("cls");
        int dni, saldo, payMethod;
        string username, password, name, lastname, birth;
        cout << "-Ingrese su nombre de usuario: ";
        cin >> username;
        new_user->setUserName(username);
        cout << "-Ingrese su contraseña: ";
        cin >> password;
        new_user->setPassword(password);
        cout << "-Nombre: ";
        cin >> name;
        new_user->setFirstName(name);
        cout << "-Apellido: ";
        cin >> lastname;
        new_user->setLastName(lastname);
        cout << "-Fecha de nacimiento (dd/mm/yy) ";
        cin >> birth;
        new_user->setDateofBirth(birth);
        cout << "-DNI: ";
        cin >> dni;
        new_user->setDni(dni);
        do {
            cout << "-Metodo de pago(1.Tarjeta | 2.Efectivo): ";
            cin >> payMethod;
        } while (payMethod <= 0 || payMethod > 2);
        if (payMethod == 1) new_user->setPaymentMethod("tarjeta");
        else new_user->setPaymentMethod("efectivo");
        cout << "Saldo inicial: ";
        cin >> saldo;
        new_user->setMoney(saldo);
        vecUsers.push_back(new_user);
    }

    User* iniciarSesion() {
        string user, password;
        cout << "\t\tINICIAR SESION" << endl;
        cout << "Ingrese su usuario: ";
        cin >> user;
        cout << "Ingrese su contrasena: ";
        cin >> password;
        User* cuenta = verificarSesion(user, password);
        system("cls");
        if (cuenta != nullptr)
            return cuenta;
        return nullptr;
    }

    void home(User *new_user) {
        int opcion;
        do {
            cout << "\t\t[BIENVENIDO " << new_user->getFirstName() << "]" << endl;
            cout << "[1] Buscar buses" << endl;
            cout << "[2] Ver saldo de cuenta" << endl;
            cout << "[3] Ver cuenta" << endl;
            cout << "[4] SALIR" << endl;
            cin >> opcion;
            system("cls");
            switch (opcion){
            case 1:
                bFile->readBusFile();
                break;
            case 2:
                cout << "\t\t [SALDO DE CUENTA]" << endl;
                cout << "[Metodo de pago: " << new_user->getPaymentMethod() << "]" << endl;
                cout << "[Saldo: " << new_user->getMoney() << "]" << endl;
                break;
            case 3:
                cout << "\t\t[DETALLES DE CUENTA]" << endl;
                cout << "[Nombre de usuario: " << new_user->getFirstName() << "]" << endl;
                cout << "[Nombre: " << new_user->getFirstName() << "]" << endl;
                cout << "[Apellido: " << new_user->getLastName() << "]" << endl;
                cout << "[Fecha de nacimiento: " << new_user->getDateofBirth() << "]" << endl;
                cout << "[DNI: " << new_user->getDni() << "]" << endl;          
                break;
            }
        } while (opcion!=4);
    }
};
