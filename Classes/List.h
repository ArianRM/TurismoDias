#pragma once
#pragma once
#include <functional>
#include <iostream>
using namespace std;
template <class G, G BLANK>
class List {
    struct Node;
    typedef function<int(G, G)> Comp;

    Node* first;
    Node* last;
    Node* tmp;
    size_t size; // n�mero de elementos en la lista

    Comp    compare; // lambda de criterio de comparaci�n

public:
    List() : first(nullptr), last(nullptr), size(0), compare([](G a, G b) {return a - b; }) {}
    List(Comp compare) : first(nullptr), last(nullptr), size(0), compare(compare) {}
    ~List();

    // Retorno de la longitud de lista
    size_t getSize();

    // Insertar elemento en la lista
    void    push_front(G elem);
    void    addPos(G elem, size_t pos);
    void    push_back(G element);

    //Borrar elemento de la lista
    void delete_back();
    void delete_at(size_t pos);
    void delete_front();

    //Obtener elemento de la lista
    G       getFirst();
    G       getPos(size_t pos);
    G       getLast();

    // Por terminar
    void    modifyFirst(G elem);
    void    modifyPos(G elem, size_t pos);
    void    modifyLast(G elem);
    G       search(G elem);
    //void print(function<void(G)> print);
};

template <typename G, G BLANK>
struct List<G, BLANK>::Node {
    G elem;
    Node* next; // puntero apunta al siguiente nodo
    Node* prev; // puntero apunta al anterior nodo
    Node(G elem = BLANK, Node* next = nullptr, Node* prev = nullptr) : elem(elem), next(next), prev(prev) {}
};


template <typename G, G BLANK>
List<G, BLANK>::~List() {
    Node* aux = first;
    while (aux != nullptr) {
        aux = first;
        first = first->next;
        delete aux;
    }
}

template <typename G, G BLANK>
size_t List<G, BLANK>::getSize() { return size; }


//Insertar
template <typename G, G BLANK>
void List<G, BLANK>::push_front(G elem) {
    Node* aux = new Node(elem);
    if (size == 0)
        first = last = aux;
    else {
        aux->next = first;
        aux->next->prev = aux;
        first = aux;
    }
    ++size;
}

template <typename G, G BLANK>
void List<G, BLANK>::push_back(G elem) {
    Node* news = new Node(elem);
    if (size == 0)
        first = last = news;
    else {
        last->next = news;
        news->prev = last;
        last = news;
    }
    ++size;
}

template <typename G, G BLANK>
void List<G, BLANK>::addPos(G elem, size_t pos) {
    if (pos<0 || pos>size)return;
    if (pos == 0)
        push_front(elem);
    else if (pos == size)
        push_back(elem);
    else {
        Node* news = new Node(elem);
        Node* aux = first;
        for (size_t i = 0; i < pos - 1; ++i) {
            aux = aux->next;
        }
        news->next = aux->next;
        news->prev = aux;
        news->next->prev = news;
        aux->next = news;
        ++size;
    }
}


//Eliminar
template <typename G, G BLANK>
void List<G, BLANK>::delete_front() {
    if (size == 0)return;
    else if (size == 1) {
        delete first;
        first = last = nullptr;
    }
    else {
        Node* aux = first;
        first = first->next;
        delete aux;
        first->prev = nullptr;
    }
    --size;
}

template <typename G, G BLANK>
void List<G, BLANK>::delete_back() {
    if (size == 0)return;
    else if (size == 1)
    {
        delete last;
        first = last = nullptr;
        --size;
    }
    else {
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        --size;
    }
}

template <typename G, G BLANK>
void List<G, BLANK>::delete_at(size_t pos) {
    if (pos == 0) { delete_front(); }
    else if (pos == size - 1) { delete_back(); }
    else {
        Node* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        Node* obj = aux->next;
        aux->prev->next = obj;
        obj->prev = aux->prev->next;
        size--;
    }
}


//Obtener
template <typename G, G BLANK>
G List<G, BLANK>::getFirst() {
    return getPos(0);
}
template <typename G, G BLANK>
G List<G, BLANK>::getPos(size_t pos) {
    if (pos >= 0 && pos <= size) {
        Node* aux = first;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux->elem;
    }
    else {
        return BLANK;
    }
}
template <typename G, G BLANK>
G List<G, BLANK>::getLast() {
    return getPos(size - 1);
}


//Por terminar
template <typename G, G BLANK>
void List<G, BLANK>::modifyFirst(G elem) {
    if (size > 0) {
        first->elem = last->elem = elem;
    }
}

template <typename G, G BLANK>
void List<G, BLANK>::modifyPos(G elem, size_t pos) {
    if (pos >= 0 && pos < size) {
        Node* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        aux->elem = elem;
    }
}

template <typename G, G BLANK>
void List<G, BLANK>::modifyLast(G elem) {
    modifyPos(elem, size - 1);
}

template <typename G, G BLANK>
G List<G, BLANK>::search(G elem) {
    Node* aux = first;
    while (aux != nullptr) {
        if (compare(aux->elem, elem) == 0) {
            cout << "Se encontro el valor buscado";
            return aux->elem;
        }


        aux = aux->next;
    }
    cout << "No se encontro";

    return BLANK;
}
/*
template <typename G, G BLANK>
void List<G, BLANK>::print(function<void(G)> imprime) {
    Node<G>* aux = first;
    while (aux != nullptr) {
        imprime(aux->elem);
        aux = aux->next;
    }
    cout << "\n";
}*/
