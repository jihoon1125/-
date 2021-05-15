#pragma once
#include "PatientBST.h"

/* Nodes to be stored in LocationBST */
class LocationNode
{
private:
	char * Location;
	PatientBST * BST;//each LocationNode has PatientBST
	LocationNode * pLeft;
	LocationNode * pRight;

public:
	LocationNode();
	~LocationNode();

	char * GetLoc();
	PatientBST * GetBST();
	LocationNode * GetLeft();
	LocationNode * GetRight();

	void SetLoc(const char * location);
	void SetLeft(LocationNode * node);
	void SetRight(LocationNode * node);
};
