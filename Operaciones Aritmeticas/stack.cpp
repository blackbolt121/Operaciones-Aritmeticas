#include "stack.h"
template <>
frame<string>* stack<string>::get(string i) {
	frame<string>* aux;
	aux = this->item;
	while (aux != nullptr) {
		if (aux->getItem()->compare(i.c_str()) == 0) break;
		aux = aux->getNext();
	}
	return aux;
}