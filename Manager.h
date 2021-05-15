#pragma once
#include "PatientNode.h"
#include "LocationBST.h"
#include "LocationHeap.h"
#include <cstdlib>

/* handling class */
class Manager
{
private:
	queue <PatientNode *> * ds_queue;//patient_queue
	LocationBST * ds_bst;//LocationBST
	LocationHeap * ds_heap;// LocationHeap
	ifstream fin;
	ofstream flog;

public:
	Manager();
	~Manager();

	void run(const char * command);//running command from command.txt
	bool LOAD();//load data from data.txt and pushing in queue
	bool ADD(char ** info);//adding data to queue
	bool QPOP(int pop_num);//pop data from queue
	bool SEARCH(char * name);//search patient from ds_bst
	bool PRINT(char ** arg);//print ds_bst or ds_heap
	bool BPOP(char * name);//deleting patient from ds_bst and update ds_heap

	void PrintErrorCode(int num);
	void PrintSuccess(const char * act);
};
