#pragma once
#include "SLLNode.h"


template <class T>
class SLList
{
protected:
	SLLNode<T>* head, * tail;
public:
	SLList() { head = tail = nullptr; }
	~SLList();
	bool isEmpty() { return head == nullptr; }
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	SLLNode<T>* findNodePtr(T el);
	SLLNode<T>* getHead() { return head; }
	SLLNode<T>* getNext(SLLNode<T>* node);
	T getHeadEl();
	T getNextEL(T el);
	void printAll();
	bool isInList(T el);
	void deleteEl(T el);

};

template<class T>
inline SLList<T>::~SLList()
{
	while (!isEmpty()) {
		T tmp = deleteFromHead();
	}
}

template<class T>
inline void SLList<T>::addToHead(T el)
{
	head = new SLLNode<T>(el, head);
	if (tail == nullptr) tail = head;

}

template<class T>
inline void SLList<T>::addToTail(T el)
{
	if (!isEmpty()) {
		tail->next = new SLLNode<T>(el);
		tail = tail->next;
	}
	else
		head = tail = new SLLNode<T>(el);
}

template<class T>
inline T SLList<T>::deleteFromHead()
{
	if (isEmpty()) {
		throw "Lista je prazna";
	}
	T el = head->info;
	SLLNode<T>* tmp = head;
	if (head == tail)
		head = tail = nullptr;
	else
		head = head->next;
	delete tmp;
	return el;
}

template<class T>
inline T SLList<T>::deleteFromTail()
{
	if (isEmpty()) {
		throw "Lista je prazna";
	}
	T el = tail->info;
	SLLNode<T>* forDel = tail;
	if (head == tail)
		head = tail = nullptr;
	else {
		SLLNode<T>* tmp;
		for (SLLNode<T>* tmp = head; tmp->next == tail; tmp = tmp->next);
		tail = tmp;
		tail->next = nullptr;
	}
	delete forDel;
	return el;
}

template<class T>
inline SLLNode<T>* SLList<T>::findNodePtr(T el)
{
	SLLNode<T>* tmp;
	for(tmp=head;tmp!=nullptr && !(tmp->isEqual(el)); tmp->tmp->next)
	return tmp;
}

template<class T>
inline SLLNode<T>* SLList<T>::getNext(SLLNode<T>* node)
{
	return node->next;
}

template<class T>
inline T SLList<T>::getHeadEl()
{
	return head->info;
}

template<class T>
inline T SLList<T>::getNextEL(T el)
{
	SLLNode<T>* tmp = findNodePtr(el);
	tmp->next;
	return tmp->info;
}

template<class T>
inline void SLList<T>::printAll()
{
	for (SLLNode<T>* temp = head; temp != nullptr; temp=temp->next)
	{
		std::cout << temp->print() << " ";
	}
}

template<class T>
inline bool SLList<T>::isInList(T el)
{
	for (SLLNode<T>* tmp = head; !tmp->isEqual(el) && tmp != nullptr; tmp = tmp->next)
		return true;
	return false;
}

template<class T>
inline void SLList<T>::deleteEl(T el)
{
	if (isEmpty()) {
		throw "Lista je prazna";
	}
	if (head == tail && head->isEqual(el)) {
		delete head;
		head = tail = nullptr;
	}
	else if (el == head->info) {
		SLLNode<T>* tmp = head;
		head = head->next;
		delete tmp;
	}
	else {
		SLLNode<T> *tmp, *pred;
		for (pred = head, tmp = head->next; tmp != nullptr && !(tmp->isEqual()); pred = pred->next, tmp = tmp->next);
		if (tmp != nullptr) {
			pred->next = tmp->next;
			if (tmp == tail)
				tail = pred;
			delete tmp;
		}

	}
}
