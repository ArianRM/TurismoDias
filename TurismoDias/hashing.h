//#pragma once
//#include "classes.h"
//
//template<typename T>
//class HashElement {
//private:
//	string key;
//	T value;
//public:
//	HashElement(string key, T value) {
//		this->key = key;
//		this->value = value;
//	}
//};
//
//template<typename T>
//class HashTable {
//	HashElement** tabla;
//	int numElementos;
//	int table_size;
//public:
//	HashTable(int size = 1500000) {
//		numElementos = 0;
//		table_size = size;
//		tabla = new HashElement * [table_size];
//		for (int i = 0; i < table_size; i++) {
//			tabla[i] = nullptr;
//		}
//	}
//	~HashTable() {
//		for (int i = 0; i < table_size; i++) {
//			if (tabla[i] != nullptr) {
//				delete tabla[i];
//			}
//		}
//		delete[] tabla;
//	}
//	int hashFunction(string key) {
//		string password = key;
//		int hash = 0;
//		for (int i = 0; i < password.length(); i++) {
//			hash = 37 * hash + password[i];
//		}
//		return hash % table_size;
//	}
//
//	int linearProbing(int collisionIndex) {
//		int jump = 1;
//		int newIndex = collisionIndex;
//		while (tabla[newIndex] != nullptr) {
//			newIndex = (collisionIndex + jump) % table_size;
//			jump++;
//		}
//		return newIndex;
//	}
//
//	void insertar(string key, T value) {
//		if (numElementos == table_size) { //ver si tabla esta llena
//			return;
//		}
//		int index = hashFunction(key);
//		if (tabla[index] != nullptr) {//ver si la posicion esta ocupada
//			index = linearProbing(index);
//		}
//		tabla[index] = new HashElement(key, value);
//		numElementos++;
//	}
//
//	T search(string key) {
//		int index = hashFunction(key);
//		if (tabla[index] != nullptr) {//ver si la posicion esta ocupada
//			index = linearProbing(index);
//		}
//		return tabla[index]->value;
//	}
//};