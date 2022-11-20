#ifndef _STRUCTURES_HPP_
define _STRUCTURES_HPP_

//#####################// Arbol AVL //#########################//

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
	typedef function<int(G, G)> Compare;

	//Criterios de inserción y busqueda.
	Compare insertCriteria;
	Compare searchCriteria;

	//Eliminación del arbol AVL
	void _delete(NodeAVL<T>*& _root) {
		if (_root == nullptr) return;
		_delete(_root->left);
		_delete(_root->right);
		delete _root;
	}

public:
	
	//Constructor
	AVL() {
		root = nullptr;
		insertCriteria = nullptr;
		searchCriteria = nulltpr;
	}
	//Destructor
	~AVL() {
		_delete(root);
	}

	//Establecer criterio de inserción 
	void setInsertionCriteria(Compare _insertionCriteria) {
		insertionCriteria = _insertionCriteria;
	}

	//Establecer criterio de búsqueda 
	void setSearchCriteria(Compare _searchCriteria) {
		searchCriteria = _searchCriteria;
	}

	//Insertar una hoja de árbol
	NodeAVL<G>* insert(NodeAVL<G>*& node, G e){
		if (node == nullptr) {
			node = new NodeAVL<G>(e);
			return node;
		}
	// Se realiza la comparación de elementos. . .
	int r = insertCriteria(e, node->data);
	if (r < 0) {
		return insert(node->left, e);
	}
	else if (r >= 0) {
		return insert(node->right, e);
		}
	}

	//Para lectura
	void inOrden(NodeAVL<G>* node) {
		if (node == nullptr) return;
		inOrden(node->left);
		cout << node->data << " ";
		inOrden(node->right);
	}
};


//#####################// Double List //#########################//

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
		return aux->element;
	}

	void selectionSort() {}
	void insertionSort() {}

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




#endif // !_STRUCTURES_HPP_
