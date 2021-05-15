#include "LocationHeapNode.h"

LocationHeapNode::LocationHeapNode()
{
	Location = NULL;//set Location as NULL
	Count = 0;
}

LocationHeapNode::~LocationHeapNode()
{
	delete[] Location;//freeing Location
}

int LocationHeapNode::GetCount()
{
	return Count;
}

char * LocationHeapNode::GetLoc()
{
	return Location;
}

void LocationHeapNode::SetCount(int count)
{
	Count = count;
}

void LocationHeapNode::SetLoc(char * location)
{
	if (Location != NULL) delete[] Location;//if Location pre-exists, delete it and reallocate memory

	Location = new char[strlen(location) + 1];
	strcpy(Location, location);
}
