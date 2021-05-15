#pragma once
#include <cstring>
#include <queue>
using namespace std;

/* nodes to be stored in LocationHeap */
class LocationHeapNode
{
private:
	int Count;//total popped patient's count in Location area
	char * Location;// Location info

public:
	LocationHeapNode();
	~LocationHeapNode();

	int GetCount();
	char * GetLoc();

	void SetCount(int count);
	void SetLoc(char * location);
};
