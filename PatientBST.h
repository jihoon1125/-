#pragma once
#include "PatientBSTNode.h"
#include "PatientNode.h"
#include <fstream>
#include <queue>
#include <iostream>
using namespace std;

/* BST including patient's node stored in each LocationNode */
class PatientBST
{
private:
	PatientBSTNode * Root;//root

public:
	PatientBST();
	~PatientBST();

	void DestroyBST(PatientBSTNode* root);//destructor for PatientBST

	PatientBSTNode * GetRoot();
	bool Insert(PatientNode * node);//inserting new PatientNode into BST
	bool Search(char * name);//searching PatientNode
	bool Delete(char * name);//deleting patientNode
	void Print_PRE(PatientBSTNode * node);//print BST in pre-order way
	void Print_IN(PatientBSTNode * node);//print BST in in-order way
	void Print_POST(PatientBSTNode * node);//print BST in post-order way
	void Print_LEVEL();//print BST in level-order way
};
