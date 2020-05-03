#pragma once;
#include <iostream>
#include <sstream>
#include <type_traits>
using namespace std;
template <class T>
class frame {
public:
	frame<T>();
	frame<T>(T* item);
	frame<T>(const T& item);
	T* getItem();
	frame<T>* getNext();
	void setItem(T* item);
	void setNext(frame<T>* next);

private:
	T* item;
	frame<T>* next;
};

template <class T>
frame<T>::frame() {
	this->item = NULL;
	this->next = NULL;
}
template <class T>
frame<T>::frame(T* item) {
	this->item = item;
	this->next = NULL;
}
template <class T>
frame<T>::frame(const T& item) {
	this->item = new T;
	*this->item = item;
	this->next = nullptr;
}
template <class T>
frame<T>* frame<T>::getNext() {
	if (this->item == NULL) {
		return NULL;
	}
	else {
		return this->next;
	}
}
template <class T>
void frame<T>::setItem(T* item) {
	this->item = item;
}
template<class T>
T* frame<T>::getItem() {
	return this->item;
}
template <class T>
void frame<T>::setNext(frame<T>* next) {
	frame<T>* aux = next;
	this->next = aux;
}
template <class T>
ostream& operator<<(ostream& out, const frame<T>& aux) {
	out << aux.item;
	return out;
}