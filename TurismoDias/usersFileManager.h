#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Classes.h"
using namespace std;

class UsersFileManager{
private:
public:
    UsersFileManager() {}
	~UsersFileManager(){}

	void writeUserFile(vector<User*> vecUsers) { // cambiar por el arbol
        ofstream file;
        file.open("users.txt", ios::out);
        if (file.fail()) {
            cout << "Error al abrir el archivo" << endl;
            exit(1);
        }
        //file << "///// USUARIOS /////" << endl;
        for (int i = 0; i < vecUsers.size(); i++) {
            //file << "\t[USUARIO " << i + 1 << "]" << endl;
            file << vecUsers[i]->getUserName() << endl;
            file << vecUsers[i]->getPassword() << endl;
            file << vecUsers[i]->getFirstName() << endl;
            file << vecUsers[i]->getLastName() << endl;
            file << vecUsers[i]->getDateofBirth() << endl;
            file << vecUsers[i]->getDni() << endl;
            file << vecUsers[i]->getPaymentMethod() << endl;
            file << vecUsers[i]->getMoney() << endl;
        }
        file.close();
	}

    vector<User*> readUsersFile() {
        vector<User*> vecUsers;
        ifstream file;
        string data;
 
        while (!file.eof()) {
            User* cuenta = new User();
            //linea 1 username
            getline(file, data);
            cuenta->setUserName(data);
            //linea 2 password
            getline(file, data);
            cuenta->setPassword(data);
            //linea 3 name
            getline(file, data);
            cuenta->setFirstName(data);
            //linea 4 lastname
            getline(file, data);
            cuenta->setLastName(data);
            //linea 5 birth
            getline(file, data);
            cuenta->setDateofBirth(data);
            //linea 6 dni
            //getline(file, data);
            int readDni;
            file >> readDni;
            cuenta->setDni(readDni);
            //linea 7 payment method
            getline(file, data);
            cuenta->setPaymentMethod(data);
            //linea 8 saldo
            getline(file, data);
            int readSaldo;
            file >> readSaldo;
            cuenta->setMoney(readSaldo);
            vecUsers.push_back(cuenta);
        }
        return vecUsers;
    }
};
