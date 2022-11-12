#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

#include <iostream>
#include <functional>
#include <vector>

template <class T>
class Node {
public:
	T elemento;
	Node* izq;
	Node* der;
	Node* prev;
	Node(T elemento) {
		this->elemento = elemento;
		izq = der = nullptr;
	}
	Node() {
	}
};

template <class T>
class BinaryTree {
	Node<T>* root;
	Node<T>* end;
	int size;
	std::function<int(T, T)> insertionCriteria;
	std::function<int(T, T)> searchCriteria;

private:
	Node<T>* _insertar(Node<T>*& node, T e) {
		if (node == nullptr) {
			node = new Node<T>(e);
			return node;
		}

		int r = insertionCriteria(e, node->elemento);
		if (r < 0) {
			return _insertar(node->izq, e);
		}
		else if (r >= 0) {
			return _insertar(node->der, e);
		}
	}

	void _enOrden(Node<T>* node) {
		if (node == nullptr) return;
		_enOrden(node->izq);
		std::cout << node->elemento << " ";
		_enOrden(node->der);
	}

	bool _vacio() {
		return root == nullptr;
	}
	int _cantidad(Node<T>* node) {
		if (node == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(node->izq);
			cd = _cantidad(node->der);
			return 1 + ci + cd;
		}
		
	}
	/*
		bool _eliminar(Node<T>*& node, T buscado){
			if(node == NULL){
				return false;
			}
			int r = compCriterio(node->elemento, buscado);

			if(r < 0){
				return _eliminar(node->der, buscado);
			}else if(r > 0){
				return _eliminar(node->izq, buscado);
			}else{
				if(node->der == NULL && node->izq == NULL){
					node = NULL;
					return true;
				}else if(node->izq == NULL){
					node = node->der;
					return true;
				}else if(node->der == NULL){
					node = node->izq;
					return true;
				}else{
					Node<T>* aux = node->der;
					while(aux->izq != NULL){
						aux = aux->izq;
					}
					node->elemento = aux->elemento;
					return _eliminar(node->der, aux->elemento);
				}
			}
		}
	*/
	int _altura(Node<T>* node) {
		if (node == NULL) {
			return 0;
		}

		int izq = 1 + _altura(node->izq);
		int der = 1 + _altura(node->der);
		return std::max(izq, der);
	}

	T _searchFirst(Node<T>* node, T _toCompare) {
		int r = searchCriteria(_toCompare, node->elemento);
		if (r == 0) {
			return node->elemento;
		}
		else if (r < 0) {
			return _searchFirst(node->izq, _toCompare);
		}
		else if (r > 0) {
			return _searchFirst(node->der, _toCompare);
		}
	}

	void _searchAll(Node<T>* node, T _toCompare, std::vector<T>& _register) {
		if (node == nullptr) return;

		int r = searchCriteria(_toCompare, node->elemento);

		if (r == 0) {
			_register.push_back(node->elemento);
			_searchAll(node->izq, _toCompare, _register);
			_searchAll(node->der, _toCompare, _register);
		}
		else if (r < 0) {
			_searchAll(node->izq, _toCompare, _register);
		}
		else if (r > 0) {
			_searchAll(node->der, _toCompare, _register);
		}
	}
	

	void _free(Node<T>*& _node) {
		if (_node == nullptr) return;
		_free(_node->izq);
		_free(_node->der);
		delete _node;
	}

public:

	BinaryTree() {
		end = nullptr;
		root = nullptr;
		size = 0;
		insertionCriteria = nullptr;
		searchCriteria = nullptr;
	}
	~BinaryTree() {
		std::cout << size;

		_free(root);
	}

	void setInsertionCriteria(std::function<int(T, T)> _insertionCriteria) {
		insertionCriteria = _insertionCriteria;
	}
	void setSearchCriteria(std::function<int(T, T)> _searchCriteria) {
		searchCriteria = _searchCriteria;
	}
	Node<T>* insert(T e) {
		return _insertar(root, e);
	}
	void enOrden() {
		_enOrden(root);
	}
	int cantidad() {
		return _cantidad(root);
	}
	int altura() {
		return _altura(root);
	}

	bool eliminar(T _buscado) {
		return _eliminar(root, _buscado);
	}

	bool vacio() {
		return _vacio();
	}

	T searchFirst(T _toCompare) {
		return _searchFirst(root, _toCompare);
	}

	std::vector<T> searchAll(T _toCompare) {
		std::vector<T> aux;
		_searchAll(root, _toCompare, aux);
		return aux;
	}
	std::vector<T> EqualsTo(T _toCompare)
	{
		std::vector<T> aux;
		_equalsto(raiz, _toCompare; aux);
		return aux;
	}


};

#endif