#pragma once
#include <iostream>
#include "operador.h"
class expresion
{
public:
	expresion(string exp);
	string getPosfija();
	float evaluar();
private:
	operador operador;
	string express;
	string expresionPosfija;
	void setPosfija();

};

