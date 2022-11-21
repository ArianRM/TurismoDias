#pragma once
#include <string>
#include "classes.h"

class HashElement {
private:
	string key;
	string value;
public:
	HashElement(string key, string value) {
		this->key = key;
		this->value = value;
	}
	string getKey() { return key; }
	string getValue() { return value; }
};

class HashTable {
private:
	HashElement** passTable;
	int numElements;
	int tableSize;

public:
	HashTable(int tableSize) {
		this->tableSize = tableSize;
		passTable = new HashElement * [tableSize];
		for (int i = 0; i < tableSize; ++i) {
			passTable[i] = nullptr;
		}
		numElements = 0;
	}
	~HashTable()
	{
		for (int i = 0; i < tableSize; ++i) {
			if (passTable[i] != nullptr) {
				delete passTable[i];
			}
		}
		delete[] passTable;
	}

	void insert_element(string key, string value) {
		int base, step, hash, newKey = 0;
		//validar si la tabla está llena
		if (numElements == tableSize)return;
		//Función Hash
		for (int i = 0; i < key.length(); i++)
			newKey += key[i];
		base = newKey % tableSize;
		hash = base;
		//constante para Hash2
		step = 0;
		while (passTable[hash] != nullptr)
		{
			//Función Hash2
			hash = (base + step) % tableSize;
			step++;
		}
		//almacenarlo en la tabla
		passTable[hash] = new HashElement(key, value);
		numElements++;
	}
	int size() {
		return tableSize;
	}

	int search_key(string key) {
		int step = 0;
		int i, base, newKey = 0;
		for (int i = 0; i < key.length(); i++)
			newKey += key[i];
		i = base = newKey % tableSize; //hash1 es = a hash2 cuando step=0;
		while (true)
		{
			if (passTable[i] == nullptr)return -1;
			else if (passTable[i]->getKey() == key) {
				return i;
			}
			else step++;

			i = (base + step) % tableSize;
		}
	}
};