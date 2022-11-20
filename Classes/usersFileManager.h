#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Classes.h"
using namespace std;

class UsersFileManager {
private:
public:
    UsersFileManager() {}
    ~UsersFileManager() {}

    void writeUserFile(vector<User*>* vecUsers) { // cambiar por el arbol
        ofstream file;
        file.open("users.txt", ios::out);
        if (file.fail()) {
            cout << "Error al abrir el archivo" << endl;
            exit(1);
        }
        //file << "///// USUARIOS /////" << endl;
        for (int i = 0; i < vecUsers->size(); i++) {
            //file << "\t[USUARIO " << i + 1 << "]" << endl;
            file << vecUsers->at(i)->getUserName() << endl;
            file << vecUsers->at(i)->getPassword() << endl;
            file << vecUsers->at(i)->getFirstName() << endl;
            file << vecUsers->at(i)->getLastName() << endl;
            file << vecUsers->at(i)->getDateofBirth() << endl;
            file << vecUsers->at(i)->getDni() << endl;
            file << vecUsers->at(i)->getPaymentMethod() << endl;
            file << vecUsers->at(i)->getMoney() << endl;
        }
        file.close();
    }

    void readUsersFile() {
        ifstream file;
        string username, password, fname, lname, birth, pmethod, dni, money;
        int i = 0;
        file.open("users.txt", ios::in);
        if (file.is_open()) {
            while (!file.eof()) {
                i++;
                getline(file, username);
                getline(file, password);
                getline(file, fname);
                getline(file, lname);
                getline(file, birth);
                getline(file, dni);
                getline(file, pmethod);
                getline(file, money);
                cout
                    << "[Username:" << username
                    << " | Password:" << password
                    << " | FirstName:" << fname
                    << " | LastName:" << lname
                    << " | Birth:" << birth
                    << " | DNI:" << dni
                    << " | Payment Method:" << pmethod
                    << " | Money:" << money
                    << "]" << endl;
            }
        }
    }

};