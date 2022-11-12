#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User {
	string firstName;
	string lastName;
	string dateofBirth;
	int dni;
public:
	User(string firstName=" ", string lastName = " ", string dateofBirth = " ") {
		this->firstName = firstName;
		this->lastName = lastName;
		this->dateofBirth = dateofBirth;
	}
};
class Account {
	User usuario;
	string password;
	string email;
	string paymentMethod;
	short money;
public:
	Account(string email, string password) {
		this->email=email;
		this->password = password;
	}
	Account(string fName,string lName, string doBirht, string paymentMethod, short money)
		:usuario(fName, lName, doBirht) {	
		this->paymentMethod = paymentMethod;
		this->money = money;
	}
	bool p_validation(string password) {
		short p_length = password.length();
		//minimo:
		//8 caracteres entre numeros y letras
		//1 letra en mayuscula
		if (p_length == 0) return false;
		if (!(p_length >= 8)) return false;
		
		
		
	}

};
class Seat {
	Account persona;
public:
	Seat(string nombre, string apellido, string nacimiento, string formaPago, short cantidad) 
		: persona(nombre, apellido, nacimiento, formaPago, cantidad) {	
	}
};
class Bus {
	vector<Seat*> asientos;//quiero un arreglo de punteros?
	short price;
	string service;
	string begin_p;
	string end_p;
public:
	Bus() {

	}
};
class Buses {
	vector<Bus*>buses;
public:
	Buses() {

	}
};