#pragma once
//dependencias base
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
//manejo de archivos
#include "usersFileManager.h"
#include "busFileManager.h"
//clases y estructura de datos
#include "Classes.h"
#include "AVL.h"
#include "hashing.h"
#include "DATA_GEN.h"
#include "DLL.h"
using namespace std;

class Consola {
private:
    User* new_user;
    vector<User*>* vecUsers;
    UsersFileManager* uFile;
    BusFileManager* bFile;
    DLL <Bus>* BusList;
    DATA_GEN generator;
    
    int nUser;
public:
    Consola() {
        vecUsers = new vector<User*>();
        BusList = new DLL<Bus>();
        new_user = new User();
        uFile = new UsersFileManager();
        bFile = new BusFileManager();
    }
    ~Consola() {}

    // busca la cuenta en el vector vecUsers
    User* buscarCuentaPorUsuario(string user) {
        User* buscada = nullptr;
        for_each(vecUsers->begin(), vecUsers->end(), [=, &buscada](User* cuenta) {
            if (user == cuenta->getUserName()) {
                buscada = cuenta;
            }
            });
        return buscada;
    }
    // valida la cuenta en el vector
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
        vecUsers->push_back(new_user);
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


    //ordenamiento de usuarios mediante dni
    int partition(vector<User*>*& Usuarios, int low, int high) {
        User* pivot = Usuarios->at(high);
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (Usuarios->at(j)->getDni() <= pivot->getDni()) {
                i++;
                User* aux = Usuarios->at(i);
                Usuarios->at(i) = Usuarios->at(j);
                Usuarios->at(j) = aux;
            }
        }
        User* aux = Usuarios->at(i + 1);
        Usuarios->at(i + 1) = Usuarios->at(high);
        Usuarios->at(high) = aux;

        return (i + 1);
    }
    void quickSort(vector<User*>*& Usuarios, int low, int high) {
        if (low < high) {
            int pi = partition(Usuarios, low, high);

            quickSort(Usuarios, low, pi - 1);
            quickSort(Usuarios, pi + 1, high);
        }
    }


    void home(User *new_user) {

        int opcion;
        do {
            cout << endl;
            cout << "\t //////[BIENVENIDO " << new_user->getFirstName() << "]//////" << endl;
            cout << "[1] Generar usuarios aleatoriamente" << endl; // GENERADOR DE DATASET ALEATORIO DE USUARIOS
            cout << "[2] Ver Usuarios" << endl; 
            cout << "[3] Ordenar usuarios por dni" << endl;
            cout << "[4] Arbol AVL de usuarios" << endl; // ARBOL BINARIO DE USUARIOS
            cout << "[5] Ver buses " << endl; // DLL DE BUSES CARGADA DESDE EL DISCO
            cout << "[6] Ordenar buses por precio" << endl;
            cout << "[7] Arbol AVL buses" << endl;
            cout << "[8] Tabla contraseñas (Hash Table)" << endl; // HASH TABLE DE CONTRASEÑAS DE USUARIOS
            cout << "[9] SALIR" << endl;
            cin >> opcion;
            system("cls");
            switch (opcion){
            case 1: 
                do{
                    cout << "Ingrese la cantidad de usuarios que desea generar (hasta 10^6): ";
                    cin >> nUser;
                } while (nUser < 0 || nUser > 1000000);
                for (int i = 0; i < nUser; i++)
                    vecUsers->push_back(generator.generate_user(nUser));
                uFile->writeUserFile(vecUsers);
                cout << "DATOS DE USUARIOS GENERADOS CORRECTAMENTE" << endl;
                break;
            case 2:
                uFile->readUsersFile();
                break;
            case 3:
                quickSort(vecUsers, 0, vecUsers->size() - 1);
                uFile->writeUserFile(vecUsers);
                uFile->readUsersFile();
                break;
            case 4:
                // implementando el arbol AVL para usuarios
                break;
            case 5:
                for (int i = 0; i < 20; i++)
                    BusList->push_back(generator.generate_bus());
                bFile->writeBusFile(BusList);
                bFile->readBusFile();
                break;
            case 6:
                //Ordeamiento de lista de buses por precio
                mergeSort(*BusList, 0, BusList->getSize()-1);
                bFile->writeBusFile(BusList);
                bFile->readBusFile();
                break;
            case 7:
                // implementar arbol AVL para buses
                break;
            case 8:
                cout << "\t\t[TABLA DE CONTRASEÑAS]" << endl;
                HashTable* passTable = new HashTable(vecUsers->size());
                for (int i = 0; i < vecUsers->size(); i++){
                    passTable->insert_element(vecUsers->at(i)->getPassword(), vecUsers->at(i)->getUserName());
                }
                for (int i = 0; i < passTable->size(); ++i) {
                    cout << passTable->search_key(vecUsers->at(i)->getPassword()) << " : " << vecUsers->at(i)->getPassword() << endl;
                }
                break;
            }
        } while (opcion!=9);
    }

    // ordenamiento de los buses mediante su precio
    void merge(DLL<Bus>& buses2, int l, int m, int r) {

        int n1 = m - l + 1;
        int n2 = r - m;

        DLL<Bus> cuentasLeft;
        DLL<Bus> cuentasRight;

        for (int i = 0; i < n1; i++) {
            cuentasLeft.push_back(buses2.operator[](l + i));
        }

        for (int j = 0; j < n2; j++) {
            cuentasRight.push_back(buses2.operator[](m + j + 1));
        }

        // index of vector left and right
        int i1 = 0, i2 = 0;
        // index of merged vector
        int i = l;

        while (i1 < n1 && i2 < n2) {
            if (cuentasLeft.operator[](i1).getPrice() <= cuentasRight.operator[](i2).getPrice()) {
                buses2.operator[](i) = cuentasLeft.operator[](i1);
                i1++;
            }
            else {
                buses2.operator[](i) = cuentasRight.operator[](i2);
                i2++;
            }
            i++;
        }
        // Copy the remaining elements of cuentasLeft if there are any
        while (i1 < n1) {
            buses2.operator[](i) = cuentasLeft.operator[](i1);
            i1++;
            i++;
        }

        // Copy the remaining elements of cuentasRight if there are any
        while (i2 < n2) {
            buses2.operator[](i) = cuentasRight.operator[](i2);
            i2++;
            i++;
        }
    }
    void mergeSort(DLL<Bus>& buses2, int l, int r) {

        if (l >= r)
            return;

        int m = (l + r) / 2;

        mergeSort(buses2, l, m);
        mergeSort(buses2, m + 1, r);
        merge(buses2, l, m, r);
    }
};
