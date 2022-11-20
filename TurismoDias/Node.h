#pragma once
#ifndef _NODE_H_
#define _NODE_H_

template <typename G>
struct Node {
	G element;
	Node* next;
	Node* prev;

	Node(G e, Node* n = nullptr, Node* p = nullptr) : element(e), next(n), prev(p) {}
};
#endif // !_NODE_HPP_

