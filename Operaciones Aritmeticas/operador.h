#pragma once
#include <iostream>
#include "stack.h"
class operador : public stack<char>
{
public:
	operador();
	void push(char x);
	char pop();
private:

};

