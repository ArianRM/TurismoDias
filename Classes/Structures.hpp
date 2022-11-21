#ifndef _STRUCTURES_HPP_
#define _STRUCTURES_HPP_

#include <functional>

//#################################### Arbol AVL ####################################////

//Nodo de Árbol AVL
template <typename G>
struct NodeAVL {
	G data;
	int factor;
	NodeAVL* right;
	NodeAVL* left;

	//Constructor 3 en 1.
	NodeAVL(G data = nullptr, int factor = 0, NodeAVL* right = nullptr
		, NodeAVL* left = nullptr) :data(data), factor(factor), right(right)
		, left(left) {}


};

template <class G>
class AVL
{
private:
	//Raiz
	NodeAVL<G>* root;
	void(*_function)(G);
	typedef function<int(G, G)> Compare;

	//Criterios de inserción y busqueda.
	Compare insertCriteria;
	Compare searchCriteria;


	// Estas funciones estan reservadas o privadas debido a
	// que interactúan de manera interna en la estructura de
	// la clase. Por ello, se ponen aqui debido a que el
	// usuario no podrá accederlas.

	//Eliminación del arbol AVL
	void _delete(NodeAVL<G>*& _root) {
		if (_root == nullptr) return;
		_delete(_root->left);
		_delete(_root->right);
		delete _root;
	}

	//Balanceo para convertir un arbol binario en un arbol AVL
	int getHeight(NodeAVL<G>* node) {
		if (node == nullptr) return 0;
		return node->factor;
	}

	void _rotateRight(NodeAVL<G>*& node) {
		NodeAVL<G>* _aux = node->left;
		node->left = _aux->right;
		_aux->right = node;
		//Actualizamos la altura
		node = _aux;
	}

	void _rotateLeft(NodeAVL<G>*& node) {
		NodeAVL<G>* _aux = node->_aux;
		node->right = _aux->left;
		_aux->left = node;
		//Actualizamos la altura
		node = _aux;
	}

	void _balance(NodeAVL<G>* node)
	{
		int h_left = getHeight(node->left);
		int h_right = getHeight(node->right);
		int aux = h_right - h_left;

		if (aux > 1) { //Rotación a la rama izquierda
			int hh_left = getHeight(node->right->left);
			int hh_right = getHeight(node->right->right);
			if (hh_left > hh_right) { //verificar si aplica doble rotación
				_rotateRight(node->right);
			}
			_rotateLeft(node);
		}
		if (aux < -1) { //Rotación a la rama derecha
			int hh_left = getHeight(node->left->left);
			int hh_right = getHeight(node->left->right);
			if (hh_left < hh_right) {//verificar si aplica doble rotación 
				_rotateLeft(node->left);
			}
			_rotateRight(node);
		}
		//Actualizar la altura del nodo raiz
		h_left = getHeight(node->left);
		h_right = getHeight(node->right);
		node->factor = 1 + ((h_left > h_right) ? h_left : h_right);
	}
	// Fin del proceso de balanceo

	//Insertar una hoja de árbol
	NodeAVL<G>* _insert(NodeAVL<G>*& node, G e) {
		if (node == nullptr) {
			node = new NodeAVL<G>(e);
			return node;
		}

		// Se realiza la comparación de elementos. . .
		int r = insertCriteria(e, node->data);


		if (r == 0)return;

		else if (r < 0) {
			return insert(node->left, e);
		}
		else if (r > 0) {
			return insert(node->right, e);
		}
		_balance(node);
	}

	//Para lectura
	void _inOrden(NodeAVL<G>* node) {
		if (node == nullptr) return;
		_inOrden(node->left);
		_function(node->data);
		_inOrden(node->right);
	}
public:
	
	//Constructor
	AVL() {
		root = nullptr;
		insertCriteria = nullptr;
		searchCriteria = nullptr;
	}
	//Destructor
	~AVL() {
		_delete(root);
	}

	//Establecer criterio de inserción 
	void setInsertionCriteria(Compare _insertCriteria) {
		insertCriteria = _insertCriteria;
	}

	//Establecer criterio de búsqueda 
	void setSearchCriteria(Compare _searchCriteria) {
		searchCriteria = _searchCriteria;
	}
	//Establecer función
	void setFunctionVoid(function<void(G)> function) {
		_function = function;
	}
	void setFunctionReturn(function<G(G, G)> function)
	{
		_function = function;
	}
	
	void insert(G e)
	{
		_insert(root, e);
	}
	//Para lectura
	void inOrden() {
		_inOrden(root);
	}
};


//#################################### Double List ####################################//

template <typename G>
struct ListNode
{
	G data;
	ListNode* next;
	ListNode* prev;
	size_t factor;

	ListNode(G data = nullptr, ListNode* next = nullptr, ListNode* prev = nullptr, size_t factor = 0) : 
		data(data), next(next), factor(factor) {}
};

template <class G>

class DLL {
	ListNode<G>* begin;
	ListNode<G>* end;
	long size;

public:
	DLL() { begin = nullptr; end = nullptr; size = 0; }

	// Insertar al inicio y al final
	void push_front(G element)
	{
		ListNode<G>* aux = new ListNode<G>(element);

		if (size == 0)
			begin = end = aux;
		else
		{
			aux->next = begin;
			begin->prev = aux;
			begin = aux;
		}
		++size;
	}
	void push_back(G element) {
		ListNode<G>* aux = new ListNode<G>(element);
		if (size == 0)
			begin = end = aux;
		else {
			end->next = aux;
			aux->prev = end;
			end = aux;
		}
		++size;
	}

	long getSize() { return size; }

	
	G& operator[](const int& pos) {
		ListNode<G>* aux = begin;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		return aux->data;
	}
	
	G getData(const int& pos) {
		ListNode<G>* aux = begin;
		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}
		return aux->data;
	}

	// Mostrar el valor del nodo
	void showElement() {
		ListNode<G>* aux = begin;
		for (size_t i = 0; i < size; ++i)
		{
			cout << aux->element << " ";
			aux = aux->next;
			if (aux->element == nullptr)
			{
				cout << " Valor no encontrado :( ";
			}
		}
		cout << "\n";
	}

};

//#################################### Hash Table ####################################//

template<typename T>
class HashElement {
private:
	string key;
	T value;
public:
	HashElement(string key, T value) {
		this->key = key;
		this->value = value;
	}
};

template<typename T>
class HashTable {
	HashElement<T>** tabla;
	int numElementos;
	int table_size;
public:
	HashTable(int size = 1500000) {
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
	int hashFunction(string key) {
		string password = key;
		int hash = 0;
		for (int i = 0; i < password.length(); i++) {
			hash = 37 * hash + password[i];
		}
		return hash % table_size;
	}

	int linearProbing(int collisionIndex) {
		int jump = 1;
		int newIndex = collisionIndex;
		while (tabla[newIndex] != nullptr) {
			newIndex = (collisionIndex + jump) % table_size;
			jump++;
		}
		return newIndex;
	}

	void insertar(string key, T value) {
		if (numElementos == table_size) { //ver si tabla esta llena
			return;
		}
		int index = hashFunction(key);
		if (tabla[index] != nullptr) {//ver si la posicion esta ocupada
			index = linearProbing(index);
		}
		tabla[index] = new HashElement(key, value);
		numElementos++;
	}

	T search(string key) {
		int index = hashFunction(key);
		if (tabla[index] != nullptr) {//ver si la posicion esta ocupada
			index = linearProbing(index);
		}
		return tabla[index]->value;
	}
};
#endif // !_STRUCTURES_HPP_
