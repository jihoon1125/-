#include "PatientNode.h"

PatientNode::PatientNode()//PatientNode default constructor
{
	Name = NULL; Temperature = 0; Cough = 'X'; Location = NULL;	//initialize value
}

PatientNode::~PatientNode()
{
	delete[] Name; delete[] Location;//memory freeing
}

char * PatientNode::GetName()
{
	return Name;
}

float PatientNode::GetTemp()
{
	return Temperature;
}

char PatientNode::GetCough()
{
	return Cough;
}

char * PatientNode::GetLoc()
{
	return Location;
}


void PatientNode::SetName(char * name)
{
	Name = new char[strlen(name) + 1];//allocate memory for Name 
	strcpy(Name, name);
}

void PatientNode::SetTemp(float temp)
{
	Temperature = temp;
}

void PatientNode::SetCough(char cough)
{
	Cough = cough;
}

void PatientNode::SetLoc(char * location)
{
	Location = new char[strlen(location) + 1];//allocate memory for Location
	strcpy(Location, location);
}
