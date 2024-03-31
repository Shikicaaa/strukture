#include "ChainedHashTable.h"
#include "SLList.h"

int main() {
	SLList<int> lista;
	for (int i = 0; i < 5; i++)
	{
		lista.addToHead(i);
	}
	lista.printAll();
	ChainedHashTable<int,double> heshtable(5);
	for (int i = 0; i < 5; i++)
	{
		double rez = i * 2.87;
		double *ptr = &rez;
		HashObject<int, double> obj(i, ptr);
		heshtable.insert(obj);
	}
	
	return 0;
}