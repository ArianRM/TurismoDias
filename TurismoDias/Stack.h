#include "Node.h"
#include <iostream>

using namespace std;

#ifndef _STACK_H_
#define _STACK_H_



template <class G>
class Stack
{
	Node<G>* top;
	size_t size;

public:
	Stack() { top = nullptr; size = 0; }
	~Stack() {}

	//Insertar en la pila
	void push(G element)
	{
		Node<G>* aux = new Node<G>(element);
		if (size == 0)
		{
			top = aux;
		}
		else
		{
			top->next = aux;
		}
		++size;
	}
	/*
	void print(function<void(G)> imprime) {
		Node<G>* aux = begin;

		for (size_t i = 0; i < size; i++)
		{

		}
		Node<G>* aux = begin;
		while (aux != nullptr) {
			imprime(aux->element);
			aux = aux->next;
		}
		cout << "\n";
	}
	*/
	Stack<G> pop()
	{
		if (size == 0)
		{
			cout << " [X] Error, la pila esta vacia\n";
			return;
		}
		else
		{
			G element = (G)(top->element);
			top = (Node<G>*) top->next;
			--size;
			return element;

		}
	}
	Stack<G> get(size_t i) {
		G element = NULL;
		Node<G>* it;
		int cont = 0;
		if (size == 0) {
			return NULL;
		}
		else {
			do {
				if (cont == 0) {
					it = top;
				}
				else {
					it = it->next;
				}
				element = (G)(it->element);
				cont++;
			} while (cont < i);
		}
		return element;
	}
};


#endif // 

