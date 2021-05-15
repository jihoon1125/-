#pragma once
#include "LocationNode.h"
#include "PatientNode.h"

class LocationBST
{
private:
	LocationNode * Root;

public:
	LocationBST();
	~LocationBST();

	void DestroyBST(LocationNode* root);//destroying BST recursively

	LocationNode * GetRoot();
	void Insert_Location(LocationNode * node);//inserting location node
	bool Insert_Patient(PatientNode * node);//inserting patient node
	bool Search(char * name);//search in BST
	char * Delete(char * name); //delete from BST 
	void Print_PRE(LocationNode* node);//print in pre-order
	void Print_IN(LocationNode* node);//print in in-order
	void Print_POST(LocationNode* node);//print in post-order
	void Print_LEVEL(LocationNode* node);//print in level-order
};	
