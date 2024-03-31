#pragma once
#include "HashTable.h"
#include "SLList.h"


template <class T,class R>
class ChainedHashTable : public HashTable<T,R>
{
protected:
	SLList<HashObject<T, R>>* array;
public:
	ChainedHashTable(unsigned int len) {
		SLList<HashObject<T,R>>::length = len;
		SLList<HashObject<T, R>>::count = 0;
		array = new SLList<HashObject<T, R>>[len];
	}
	~ChainedHashTable() {
		HashObject<T, R> hobj;
		for (unsigned int i = 0; i < HashTable<T,R>::length; i++)
		{
			try {
				hobj = array[i].getHeadEl();
				while (true) {
					hobj.deleteRecord();
					hobj = array[i].getNextEl(hobj);
				}
			}
			catch(std::invalid_argument e){
				throw "NE radi";
			}
			delete[] array;
		}
	}
	void insert(HashObject<T, R> obj) {
		array[h(obj)].addToHead(obj);
		SLList<HashObject<T, R>>::count++;
	}
	void withdraw(HashObject<T, R> obj) {
		array[h(obj)].deleteEl();
		SLList<HashObject<T, R>>::count--;
	}
	void withdraw(T key) {
		HashObject<T, R> obj = find(key);
		withdraw(obj);
	}
	HashObject<T, R> find(T key) {
		HashObject<T,R> obj;
		unsigned int i = f(key) % SLList<HashObject<T,R>>::length;
		obj = 
	}

};

