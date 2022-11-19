#ifndef _AVL_HPP_
define _AVL_HPP_

//Nodo de �rbol AVL
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

	//Criterios de inserci�n y busqueda.
	function<int(G, G)> insertCriteria;
	function<int(G, G)> searchCriteria;

	//Eliminaci�n del arbol AVL
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

	//Establecer criterio de inserci�n 
	void setInsertionCriteria(std::function<int(T, T)> _insertionCriteria) {
		insertionCriteria = _insertionCriteria;
	}

	//Establecer criterio de b�squeda 
	void setSearchCriteria(std::function<int(T, T)> _searchCriteria) {
		searchCriteria = _searchCriteria;
	}

	//Insertar una hoja de �rbol
	NodeAVL<G>* insert(NodeAVL<G>*& node, G e){
		if (node == nullptr) {
			node = new NodeAVL<G>(e);
			return node;
		}
	// Se realiza la comparaci�n de elementos. . .
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


#endif // !_AVL_HPP_
