#pragma once
#include "classes.h"

template<typename T>
class HashElement {
private:
	T key;
	T value;
public:
	HashElement(T key, T value) {
		this->key = key;
		this->value = value;
	}
};
template<typename T>
class HashTable {
	HashElement** tabla;
	T numElementos;
	T table_size;
public:
	HashTable(T size) {
		numElementos = 0;
		table_size = size;
		tabla = new HashElement * [table_size];
		for (int i = 0; i < table_size; i++) {
			tabla[i] = nullptr;
		}
	}
	~HashTable() {
		for (int i = 0; i < table_size; i++) {
			if (tabla[i] != nullptr) {
				delete tabla[i];
			}
		}
		delete[] tabla;
	}
	T hashFunction(T key) {
		
		
		T base;

		/*int base, step, index;
		base = key % TABLE_SIZE;
		index = base;
		step = 0;
		while (tabla[index] != nullptr)
		{
			index = (base + step) % TABLE_SIZE;
			step++;
		}*/
	}
	void insertar(T key, T value) {
		if (numElementos == table_size)return;
		
		tabla[index] = new HashEntidad(key, value);
		numElementos++;
	}

};