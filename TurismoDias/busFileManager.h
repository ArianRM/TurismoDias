#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Classes.h"
#include "DLL.h"
using namespace std;

class BusFileManager {
private:
public:
    BusFileManager() {}
    ~BusFileManager() {}

    void writeBusFile(DLL <Bus*> BusList) {
        ofstream file;
        file.open("buses.txt", ios::app);
        if (file.fail()) {
            cout << "Error al abrir el archivo" << endl;
            exit(1);
        }
        for (int i = 0; i < BusList.getSize(); i++) {
            file << BusList.operator[](i)->getSeats() << endl;
            file << BusList.operator[](i)->getPrice() << endl;
            file << BusList.operator[](i)->getService() << endl;
        }
        file.close();
    }

    void readBusFile() {
        ifstream file;
        string seats, price, service;
        int i=0;
        file.open("buses.txt", ios::in);
        if (file.is_open()) {
            while (!file.eof()) {
                i++;
                getline(file, seats);
                getline(file, price);
                getline(file, service);
                cout << "[Bus " << i << ": Asiento=" << seats << " | Price=" << price << " | Servicio=" << service << "]" << endl;
            }
        }
    }
};
