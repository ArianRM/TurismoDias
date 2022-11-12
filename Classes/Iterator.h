#pragma once
#include "Node.h"
#include "DLL.h"
#include "Stack.h"

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class G>
class Iterator {
    unsigned int    pos;
    Node* aux;
public:
    friend class DLL;
    friend class Stack;
    Iterator(unsigned int pos = 0, Node* aux = nullptr) : pos(pos), aux(aux) {}
    void operator ++() { pos++; aux = aux->next; }
    bool operator !=(Iterator x) { return pos != x.pos; }
    G    operator  *() { return aux->elem; }
    Iterator begin() {
        Iterator it;
        it.pos = 0;
        it.aux = this->begin
            return it
    }
    Iterator end() {
        Iterator it;
        it.pos = size;
        it.aux = this->end
            return it
    }

};


#endif 
