#include "Vector.h"
bool operator == (const Vector<char, float> &vect, const char& key) {

	return *vect.key == key;
}
