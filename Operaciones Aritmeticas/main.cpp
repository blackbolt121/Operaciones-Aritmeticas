#include <iostream>
#include <fstream>
#include <string>
#include "expresion.h"
#include "Vector.h"
using namespace std;
int main() {

	//Para poder ingresar una operacion aritmetica, favor de editar el archivo operaciones.txt, con una sola operacion aritmetica.
	string aux;
	ifstream archivo;
	archivo.open("operaciones.txt");
	if (archivo.fail()) {

	}
	else {
		while (!archivo.eof()) {
			getline(archivo, aux, '\n');

		}
	}
	expresion a(aux);
	cout << a.evaluar();
	
	return 0;
}