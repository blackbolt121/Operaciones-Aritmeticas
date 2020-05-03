#include "expresion.h"
#include "Vector.h"
expresion::expresion(string exp)
{
	this->express = exp;
	this->setPosfija();
}

string expresion::getPosfija()
{
	return this->expresionPosfija;
}

float expresion::evaluar()
{
	float resultado = 0;
	stack<float> dato;
	stack<Vector<char, float>> vars;
	string aux = "";
	for (char x : this->expresionPosfija) {
		if (x == ',')
		{
			if (aux.compare("") != 0) {
				float cast = atof(aux.c_str());
				dato.push(cast);
				aux = "";
			}
		}
		else if (48 <= x and x <= 57) {
			aux += x;
		}
		else if ((65 <= x and x <= 90) or (97 <= x and x <= 122)){
			frame<Vector<char, float>> *aux = vars.getPeek();
			while (aux != nullptr) {
				if (*aux->getItem() == x)
					break;
				else
					aux = aux->getNext();
			}
			if (aux != nullptr) {
				dato.push(*aux->getItem()->getValue(x));
			}
			else {
				cout << "Cuanto vale " << x << ": ";
				float cast;
				cin >> cast;
				cin.ignore(100, '\n');
				Vector<char, float> new_key(x, cast);
				vars.push(new_key);
				dato.push(cast);
			}
		}
		else if (x == '*' or x == '/' or x == '+' or x == '-' or x == '^') {
			float b = *dato.pop()->getItem();
			float a = *dato.pop()->getItem();
			float resultado = 0;
			switch (x) {
			case '+':
				resultado = a + b;
				dato.push(resultado);
				break;
			case '-':
				resultado = a - b;
				dato.push(resultado);
				break;
			case '*':
				resultado = a * b;
				dato.push(resultado);
				break;
			case '/':
				if (b != 0) {
					resultado = a / b;
					dato.push(resultado);
				}
				else {
					throw "Division Exception";
				}
				break;
			case '^':
				resultado = pow(a, b);
				dato.push(resultado);
				break;
			}
		}


	}
	if (dato.getSize() == 1)
		resultado = *dato.pop()->getItem();
	else
		cout << "La pila no se vacio apropiaddamente";
	return resultado;

}

void expresion::setPosfija()
{

	bool coma = false;
	for (char x : this->express) {
		if (48 <= x and x <= 57) 
		{
			if (coma == true) {
				this->expresionPosfija += ',';
				coma = false;
			}
			this->expresionPosfija += x;
		}
		else if (65 <= x and x <= 90) 
		{
			if (coma == true) {
				this->expresionPosfija += ',';
				coma = false;
			}
			this->expresionPosfija += x;
		}
		else if (97 <= x and x <= 122) {
			if (coma == true) {
				this->expresionPosfija += ',';
				coma = false;
			}
			this->expresionPosfija += x;
		}
		else 
		{
			
			if (this->operador.isEmpty() == true) {
				if(this->expresionPosfija.size() != 0){
					coma = true;
				}
				this->operador.push(x);
			}
			else
			{
				switch (x) {

				case '+':
				case '-':
					if (*this->operador.getPeek()->getItem() == '+' or *this->operador.getPeek()->getItem() == '-')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '/' or *this->operador.getPeek()->getItem() == '*')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '^')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '(')
					{
						coma = true;
						this->operador.push(x);
					}
					break;
				case '/':
				case '*':
					if (*this->operador.getPeek()->getItem() == '+' or *this->operador.getPeek()->getItem() == '-')
					{
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '(')
					{
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '/' or *this->operador.getPeek()->getItem() == '*')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						coma = true;
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '^')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						this->operador.push(x);
					}
					break;

				case '^':
					coma = true;
					if (*this->operador.getPeek()->getItem() == '+' or *this->operador.getPeek()->getItem() == '-')
					{
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '(')
					{
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '/' or *this->operador.getPeek()->getItem() == '*')
					{
						this->operador.push(x);
					}
					else if (*this->operador.getPeek()->getItem() == '^')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
						
						this->operador.push(x);
					}
					break;

				case '(':
					this->operador.push(x);
					break;
				case ')':
					while (*this->operador.getPeek()->getItem() != '(')
					{
						this->expresionPosfija += ',';
						this->expresionPosfija += this->operador.pop();
					}
					this->operador.pop();
					coma = true;
					break;
				default:

					break;
				}
			}
		}
	}
	if (this->operador.isEmpty() == false) {
		while (this->operador.isEmpty() == false) {
			char aux = this->operador.pop();
			this->expresionPosfija += ',';
			this->expresionPosfija += aux;
		}
	}
}
