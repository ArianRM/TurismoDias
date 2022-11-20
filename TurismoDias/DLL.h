#pragma once
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

	// Obtener un valor del nodo
	G& operator[](const int& pos) {
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

