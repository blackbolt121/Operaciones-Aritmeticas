#pragma once
#include <iostream>
template <class K, class V>
class Vector
{
public:
	Vector();
	Vector(const K &key, const V& value);
	V* getValue(const K &key);
	friend bool operator == (const Vector<K, V> &vector, const K& value);
	
private:
	K* key;
	V* value;
	K* getKey();
};

template<class K, class V>
inline Vector<K, V>::Vector()
{
}

template<class K, class V>
inline Vector<K, V>::Vector(const K &key, const V &value)
{
	this->key = new K;
	*this->key = key;
	this->value = new V;
	*this->value = value;
}

template<class K, class V>
inline V* Vector<K, V>::getValue(const K& key)
{
	if (*this->key == key) {
		return this->value;
	}
	else {
		return nullptr;
	}
}

template<class K, class V>
inline K* Vector<K, V>::getKey()
{
	return this->key;
}
template <class K, class V>
inline bool operator==(const Vector<K, V>& vector, const K& key)
{
	return vector.key == key;
}