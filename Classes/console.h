#pragma once
#include"hashing.h"
#include<iostream>
#include<string>
using namespace std;


class Controladora{
	HashTable<Account> cuentas(10);
public:

};
void sign_up() {
	string email;
	string password;
	cout << "Ingrese su email";
	getline(cin, email);
	cout << "Ingrese su contrasena";
	getline(cin, password);
}
void log_in() {
	string email;
	string password;
	cout << "Ingrese su email";
	getline(cin, email);
	cout << "Ingrese su contrasena";
	getline(cin, password);
	
}