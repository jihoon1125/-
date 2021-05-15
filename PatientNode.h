#pragma once
#include <cstring>

/* Node to be stored in queue */

class PatientNode
{
private:
	char * Name;//patient name
	float Temperature;//patient temperature
	char Cough;//whether patient cough 
	char * Location;//patient location

public:
	PatientNode();
	~PatientNode();

	char * GetName();
	float GetTemp();
	char GetCough();
	char * GetLoc();

	void SetName(char * name);
	void SetTemp(float temp);
	void SetCough(char cough);
	void SetLoc(char * location);
};
