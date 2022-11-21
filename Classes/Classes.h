#pragma once

#ifndef _CLASSES_HPP_
#define _CLASSES_HPP_

#include <string>


using namespace std;

class Transaction {
	short seat;
	short price;
	string service;
	string begin_p;
	string end_p;

public:
	Transaction(short seat = 0, short price = 0, string service = "", string begin_p = "", string end_p = "")
		:seat(seat), price(price), service(service), begin_p(begin_p), end_p(end_p) {}

	~Transaction() {}

	string toString() {
		return "Asiento: " + to_string(seat) + "Precio: " + to_string(price) +
			"Tipo de servicio: " + service + "Lugar de inicio:" + begin_p +
			" Lugar de llegada: " + end_p + "\n\n";
	}

	void setSeat(short _seat) { seat = _seat; }
	void setPrice(short _price) { price = _price; }
	void setService(string _service) { service = _service; }
	void setBegin_p(string _begin_p) { begin_p = _begin_p; }
	void setEnd_p(string _end_p) { end_p = _end_p; }

	short getSeat(short _seat) { return seat; }
	short getPrice(short _price) { return price; }
	string getService(string _service) { return service; }
	string getBegin_p(string _begin_p) { return begin_p; }
	string getEnd_p(string _end_p) { return end_p; }

};

class User {
private:
	

	string userName;
	string password;
	string firstName;
	string lastName;
	string dateofBirth;
	string paymentMethod;
	int dni;
	int money;
public:
	User(string uName = " ", string pWord = " ", string fName = " ", string lName = " ",
		string doBirth = " ", string pMethod = " ", int id = 0, int balance = 0)
		: userName(uName), password(pWord), firstName(fName), lastName(lName),
		dateofBirth(doBirth), paymentMethod(pMethod), dni(id), money(balance) {}
	~User() {}

	


	void setUserName(string _userName) { userName = _userName; }
	void setPassword(string _password) { password = _password; }
	void setFirstName(string a) { firstName = a; }
	void setLastName(string b) { lastName = b; }
	void setDateofBirth(string c) { dateofBirth = c; }
	void setPaymentMethod(string d) { paymentMethod = d; }
	void setDni(int e) { dni = e; }
	void setMoney(int f) { money = f; }

	string getUserName() { return userName; }
	string getPassword() { return password; }
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getDateofBirth() { return dateofBirth; }
	string getPaymentMethod() { return paymentMethod; }
	int getDni() { return dni; }
	int getMoney() { return money; }



};

class Bus {
	short seats;
	short price;
	string service;
	string begin_p;
	string end_p;

public:
	Bus(short precio = 0, string servicio = " ") {
		seats = 40;
		price = precio;
		service = servicio;

	}
	~Bus() {}

	void setPrice(short precio) { price = precio; }
	void setService(string servicio) { service = service; }
	void setBegin_p(string _begin_p) { begin_p = _begin_p; }
	void setEnd_p(string _end_p) { end_p = _end_p; }

	short getSeats() { return seats; }
	short getPrice() { return price; }
	string getService() { return service; }
	string getBegin_p(string _begin_p) { return begin_p; }
	string getEnd_p(string _end_p) { return end_p; }

	void print()
	{
		cout << "[Asientos: " << seats <<"]" << " [Precio: " << price << "]";
		cout << " [Servicio: " << service << "]\n";
	}

};



#endif
