#pragma once
#include <cstring>

/* Node to be stored in PatientBST*/

class PatientBSTNode
{
private:
	char * Name;//Patient's name
	char Disease;//whether patient is ill or not 

	PatientBSTNode * pLeft;//leftnode
	PatientBSTNode * pRight;//rightnode

public:
	PatientBSTNode();
	~PatientBSTNode();

	char * GetName();
	char GetDisease();
	PatientBSTNode * GetLeft();
	PatientBSTNode * GetRight();

	void SetName(char * name);	
	void SetDisease(char disease);	
	void SetLeft(PatientBSTNode * node);
	void SetRight(PatientBSTNode * node);
};
