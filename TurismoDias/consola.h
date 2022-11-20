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
            cout << "[7] Desencriptar contraseñas (Hash Table)" << endl; // HASH TABLE DE CONTRASEÑAS DE USUARIOS
            cout << "[8] SALIR" << endl;
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
                // implementando arbol binario
                /*BinaryTree<int>* userTree= new BinaryTree<int>();
                for (int i = 0; i < 100; i++) {
                    userTree->insert(vecUsers.at(i)->getDni());
                }
                cout << "\t\t[Arbol binario de usuarios]" << endl;
                cout << "[1] En Orden" << endl;
                cout << "[2] Post Orden" << endl;
                cout << "[3] Pre Orden" << endl;*/
                break;
            case 5:
                for (int i = 0; i < 20; i++)
                    BusList->push_back(generator.generate_bus());
                bFile->writeBusFile(BusList);
                bFile->readBusFile();
                break;
            case 6:
                mergeSort(BusList, 1, BusList->getSize() - 1);
                bFile->writeBusFile(BusList);
                bFile->readBusFile();
                break;
            case 7:
                cout << "\t\t[DESENCRIPTANDO CONTRASEÑAS]" << endl;
                //    HashTable<string>* ht = new HashTable<string>(nUser);
                //    for (int i = 0; i < nUser; i++){
                //        //ht->insertar();
                //    }
                break;
            }
        } while (opcion!=8);
    }

    // ordenamiento de los buses mediante su precio
    void merge(DLL<Bus>*& BusList, int l, int m, int r) {

        int n1 = m - l + 1;
        int n2 = r - m;

        DLL<Bus>* BusListRight = new DLL<Bus>();
        DLL<Bus>* BusListLeft = new DLL<Bus>();

        for (int i = 0; i < n1; i++) {
            BusListLeft->push_back(BusList->operator[](l+i));
        }

        for (int j = 0; j < n2; j++) {
            BusListRight->push_back(BusList->operator[](m + j + 1));
        }

        // index de la lista left y right
        int i1 = 0, i2 = 0;
        // index de la lista unida
        int i = l;

        while (i1 < n1 && i2 < n2) {
            if (BusListLeft->operator[](i1).getPrice() <= BusListRight->operator[](i2).getPrice()) {
                BusList->operator[](i) = BusListLeft->operator[](i1);
                i1++;
            }
            else {
                BusListLeft->operator[](i) = BusListRight->operator[](i2);
                i2++;
            }
            i++;
        }
        // Copiar los elementos restantes de la lista left si es que queda alguna
        while (i1 < n1) {
            BusList->operator[](i) = BusListLeft->operator[](i1);
            i1++;
            i++;
        }

        // Copiar los elementos restantes de la lista right si es que queda alguna
        while (i2 < n2) {
            BusList->operator[](i) = BusListLeft->operator[](i2);
            i2++;
            i++;
        }
    }

    void mergeSort(DLL<Bus>*& BusList, int l, int r) {
        if (l >= r)
            return;
        int m = (l + r) / 2;
        mergeSort(BusList, l, m);
        mergeSort(BusList, m + 1, r);
        merge(BusList, l, m, r);
    }
};
