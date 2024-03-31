#pragma once
#include <iostream>
template <class T, class R>

class HashObject
{
protected:
	T key;
	R* record;
	void obrisi() {
		if (record != nullptr)
			delete record;
	}
public:
	HashObject() { key = (T)0, record = nullptr; }
	HashObject(T k) { key = k; record = nullptr; }	
	HashObject(T k, R* object) { key = k; record = object; }
	~HashObject() { obrisi(); }
	HashObject& operator=(HashObject& const h) {
		key = h.key;
		record = h.record;
		return *this;
	}
	bool operator==(HashObject const h) {
		return record == h.record;
	}
	T getKey() { return key; }
	R* getRecord() { return record; }
	bool isEqualKey(T k) { return key == k; }
	void print() { std::cout << key << "|" << record; }
};

