#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include "Node.h"

template <class G>

class DLL {
    Node<G>* begin;
    Node<G>* end;
    long size;

public:
    DLL() { begin = nullptr; end = nullptr; size = 0; }

    // Insertar al inicio y al final
    void push_front(G element)
    {
        Node<G>* aux = new Node<G>(element);

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
        Node<G>* aux = new Node<G>(element);
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
        Node<G>* aux = begin;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->element;
    }

    void selectionSort(){}
    void insertionSort(){}

    // Mostrar el valor del nodo
    void showElement() {
        Node<G>* aux = begin;
        for (size_t i = 0; i < size; ++i)
        {
            cout << aux->element << " ";
            aux = aux->element;
            if (aux->element == nullptr)
            {
                cout << " Valor no encontrado :( ";
            }
        }
        cout << "\n";
    }

};

#endif