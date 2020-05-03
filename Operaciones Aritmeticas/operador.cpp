#include "operador.h"

operador::operador() : stack<char>()
{

}
void operador::push(char x) {
	if (x == '-' or x == '+' or x == '*' or x == '/' or x == '^' or x == '(') {
		stack<char>::push(x);
	}
	else {

	}
}
char operador::pop() {
	char* retorno = stack<char>::getPeek()->getItem();
	stack<char>::pop();
	if (retorno != nullptr) {
		return *retorno;
	}
	return ' ';
}
