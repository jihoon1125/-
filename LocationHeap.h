#pragma once
#include "LocationHeapNode.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

/* having LocationHeapNode in this heap */
class LocationHeap
{
private:
	LocationHeapNode ** Heap;
	int size;

public:
	LocationHeap();
	~LocationHeap();

	bool Insert(char * location);//only insert function
	void Print();
};
