#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Classes.h"
using namespace std;

class DATA_GEN{
private:
	char letters[26] = { 'a','e','i','o','u','y','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
	string payM[2] = { "efectivo", "tarjeta" };
public:
	DATA_GEN(){}
	~DATA_GEN(){}

	User* generate_user(int n) {
		return new User(
			genUsername(n),
			genPass(),
			genName(),
			genName(),
			genBirth(),
			genPayMethod(),
			genDNI(),
			genMoney()
		);
	}

	string genUsername(int n) {
		string name = "";
		for (int i = 0; i < rand() % 10 + 1; i++)
			name = "User" + to_string(rand()%n+1);
		return name;
	}

	string genPass() {
		string pass = "";
		for (int i = 0; i < rand() % 10 + 1; i++)
			pass += letters[rand()%26];
		return pass;
	}

	string genName() {
		string name = "";
		for (int i = 0; i < rand()%10+5; i++) 
			name += letters[rand() % 26];
		

		return name;
	}

	string genBirth() {
		string day = to_string(rand() % 30);
		string month = to_string(rand() % 12);
		string year = to_string(rand() % 99);
		string birth = day + month + year;
		return birth;
	}

	string genPayMethod() {
		string pm = payM[rand() % 2];
		return pm;
	}
	
	int genDNI() {
		int dni = rand()%100000000%999999;
		return dni;
	}
	
	int genMoney() {
		int money = rand() % 1000+20;
		return money;
	}
};
