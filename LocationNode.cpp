#include "LocationNode.h"

LocationNode::LocationNode()
{
	Location = NULL;
	BST = new PatientBST();//when LocationNode created, create PatientBST concurrently
	pLeft = NULL;
	pRight = NULL;
}

LocationNode::~LocationNode()
{
	/* freeing memory */
	delete[] Location;
	delete BST;		
}

char * LocationNode::GetLoc()
{
	return Location;
}

PatientBST * LocationNode::GetBST()
{
	return BST;
}

LocationNode * LocationNode::GetLeft()
{
	return pLeft;
}

LocationNode * LocationNode::GetRight()
{
	return pRight;
}

void LocationNode::SetLoc(const char * location)
{
	Location = new char[strlen(location) + 1];//memory allocation for Location
	strcpy(Location, location);
}

void LocationNode::SetLeft(LocationNode * node)
{
	pLeft = new LocationNode();//memory allocate for pLeft
	pLeft->SetLoc(node->Location);
}

void LocationNode::SetRight(LocationNode * node)
{
	pRight = new LocationNode();//memory allocate for pRight
	pRight->SetLoc(node->Location);
}
