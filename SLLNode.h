#pragma once
#include <iostream>

template <class T>
class SLLNode
{
public:
	T info;
	SLLNode<T> *next;
public:
	SLLNode() { info = T(); next = nullptr; }
	SLLNode(T i) { info = i; next = nullptr; }
	SLLNode(T i, SLLNode<T>* n) { info = i; next = n; }
	~SLLNode() { if (next != nullptr) delete next; }
	T print() { return info; }
	bool isEqual(T el) { return info == el.info; }

};

