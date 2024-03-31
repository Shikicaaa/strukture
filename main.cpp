#include "ChainedHashTable.h"
#include "SLList.h"

int main() {
	SLList<int> lista;
	for (int i = 0; i < 5; i++)
	{
		lista.addToHead(i);
	}
	lista.printAll();
	return 0;
}