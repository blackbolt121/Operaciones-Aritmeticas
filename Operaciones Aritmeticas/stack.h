#pragma once
#include <iostream>
#include <ostream>
#include "frame.h"
using namespace std;
template <class T>
class stack {
public:
	stack<T>();
	stack<T>(T* i);
	int getSize();
	frame<T>* getPeek();
	virtual void push(const T& i);
	bool isEmpty();
	frame<T>* pop();
	frame<T>* get(T i);

private:
	frame<T>* item;
	int size;

};
template <class T>
stack<T>::stack() {
	this->item = NULL;
	this->size = 0;
}
template <class T>
stack<T>::stack(T* i) {
	this->item = new frame<T>(i);
	this->size = 1;
}
template <class T>
void stack<T>::push(const T& i) {
	this->size++;
	if (this->item == NULL) {
		this->item = new frame<T>(i);
		this->item->setNext(nullptr);
	}
	else {
		frame<T>* aux = this->item;
		this->item = new frame<T>(i);
		this->item->setNext(aux);
	}

}
template <class T>
frame<T>* stack<T>::pop() {
	if (this->item != NULL) {

		frame<T>* aux = this->item;
		this->item = this->item->getNext();
		this->size--;
		return aux;
	}
	else {
		this->item = NULL;
		return nullptr;
	}
}
template <class T>
frame<T>* stack<T>::getPeek() {
	try {
		if (this->item == NULL) throw - 1;
		else return this->item;
	}
	catch (int exp) {
		std::cout << "La pila esta vacia" << std::endl;
		return NULL;
	}
}
template <class T>
int stack<T>::getSize() {
	return this->size;
}
template <class T>
frame<T>* stack<T>::get(T i) {
	frame<T>* aux;
	aux = this->item;
	if (aux == NULL) return NULL;
	while (aux != NULL) {
		if (*aux->getItem() == i) break;
		else {
			aux = aux->getNext();
		}
	}
	return aux;
}
template <class T>
bool stack<T>::isEmpty() {
	if (this->size == 0) {
		return true;
	}
	else {
		return false;
	}
}