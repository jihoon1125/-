#include "PatientBSTNode.h"

PatientBSTNode::PatientBSTNode()//PatientBSTNode default constructor
{
	Name = NULL; Disease = 'X'; pLeft = NULL; pRight = NULL;
}

PatientBSTNode::~PatientBSTNode()
{
	delete[] Name;//memory freeing
}

char * PatientBSTNode::GetName()
{
	return Name;
}

char PatientBSTNode::GetDisease()
{
	return Disease;
}

PatientBSTNode * PatientBSTNode::GetLeft()
{
	return pLeft;
}

PatientBSTNode * PatientBSTNode::GetRight()
{
	return pRight;
}

void PatientBSTNode::SetName(char * name)
{
	if (Name != NULL) delete[] Name;//revising previous name

	Name = new char[strlen(name) + 1];//memory allocation for name
	strcpy(Name, name);
}

void PatientBSTNode::SetDisease(char disease)
{
	Disease = disease;
}

void PatientBSTNode::SetLeft(PatientBSTNode * node)
{
	if (node == NULL) {//setting left node null
		pLeft = NULL; return;
	}	

	/* setting new node */
	pLeft = new PatientBSTNode();
	pLeft->SetName(node->GetName());
	pLeft->SetDisease(node->GetDisease());
}

void PatientBSTNode::SetRight(PatientBSTNode * node)//behave same as SetLeft
{
	if (node == NULL) {
		pRight = NULL; return;
	}


	pRight = new PatientBSTNode();
	pRight->SetName(node->GetName());
	pRight->SetDisease(node->GetDisease());
}
