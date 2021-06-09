#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Personaje.h"
#include "ListaPalabras.h"
#include "Habitacion.h"
using namespace std;

// Necesito tambien a todas las habitaciones

// Mensajes del Parser
const char* msg1 = "No comprendo la instruccion. Verifique que las palabras hayan sido escritas corretamente y que el orden de ellas sea el adecuado";
const char* msg2 = "No comprendo la instruccion. Verifique que la instruccion tecleada sea un comando";

class Parser
{
public:
	Parser();
	Parser(Personaje*, ListaPalabras&);
	bool procesaComando(string);
private:
	Personaje* personaje;
	ListaPalabras palabras;
	string palabra1, palabra2;
	string tipo1, tipo2;
	Item* item;

	void getPalabras(string);
	bool exist(string, vector<string>);
	void getSemanticValue();
	string toLower(string);
	void test(vector<string>);
};

Parser::Parser() {}

Parser::Parser(Personaje* personaje, ListaPalabras& palabras) {
	this->personaje = personaje;
	this->palabras = palabras;

	palabra1 = "";
	palabra2 = "";
	tipo1 = "";
tipo2 = "";

item = NULL;
}

bool Parser::procesaComando(string instruccion) {
	// 1. Descomponemos el string con las instrucciones
	try {
		getPalabras(instruccion);
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return false;
	}
	getSemanticValue();

	cout << "TIPOS" << endl;
	cout << "Tipo 1: " << tipo1 << endl;
	cout << "Tipo 2: " << tipo2 << endl;
	// Si la instruccion es de una palabra
	if (palabra2 == "") {
		if (tipo1 == "comando")
			//ejecutaComando();
			return true;
		else
			cout << msg2 << endl;
		return false;
	}

	// Si la instruccion es de dos palabras
	if (tipo1 == "agregar" && tipo2 == "objeto") {
		//personaje.addItem(item);
		return true;
	}

	if (tipo1 == "soltar" && tipo2 == "objeto") {
		//personaje.dropItem(item);
		return true;
	}

	if (tipo1 == "interactuar" && tipo2 == "objeto") {
		cout << item->interactuar() << endl;
		return true;
	}

	if (tipo1 == "descripcion" && tipo2 == "objeto") {
		cout << item->getDesc() << endl;
		return true;
	}

	if (tipo1 == "desplazamiento" && tipo2 == "lugar") {
		int dir = 0;
		if (palabra2 == "norte") dir = 0;
		if (palabra2 == "este") dir = 1;
		if (palabra2 == "sur") dir = 2;
		if (palabra2 == "oeste") dir = 3;
		personaje->desplazar(dir);
		return true;
	}

	cout << msg1 << endl;
	return false;
}

void Parser::getPalabras(string str) {

	if (str == "" || str.size() == 0) {
		throw invalid_argument(msg1);
	}
	palabra1 = "";
	palabra2 = "";
	string instruccion = toLower(str);
	istringstream ss(instruccion);
	cout << "PALABRAS" << endl;
	ss >> palabra1;
	ss >> palabra2;
	ss.ignore();
	cout << palabra1 << endl;
	cout << palabra2 << endl;
}

bool Parser::exist(string palabra, vector<string> listaPalabras) {
	for (string str : listaPalabras) {
		if (toLower(str) == toLower(palabra))
			return true;
	}
	return false;
}

void Parser::getSemanticValue() {
	tipo1 = "";
	tipo2 = "";
	// Busca en todos los comandos del juego
	for (int i = 0; i < palabras.getLista().size(); ++i) {
		if (exist(palabra1, palabras.getLista()[i]))
			tipo1 = palabras.getTipos()[i];
		if (exist(palabra2, palabras.getLista()[i]))
			tipo2 = palabras.getTipos()[i];
	}

	// Busca en los objetos que hay en la habitacion
	for (int i = 0; i < personaje->getHabitacion()->getItems().size(); ++i) {
		if (palabra1 == toLower(personaje->getHabitacion()->getItems()[i]->getNombre())) {
			tipo1 = "";
			tipo2 = "";
			return;
		}

		if (exist(palabra2, personaje->getHabitacion()->getItems()[i]->getPalabras())) {
			tipo1 = "";
			tipo2 = "";
			return;
		}

		if (exist(palabra1, personaje->getHabitacion()->getItems()[i]->getPalabras())) {
			tipo1 = "interactuar";

			if (palabra2 == toLower(personaje->getHabitacion()->getItems()[i]->getNombre())) {
				item = personaje->getHabitacion()->getItems()[i];
				tipo2 = "objeto";
			}
		}
	}

	// Busca en el inventario del personaje y en las palabras de interactuar de cada Item
	for (int i = 0; i < personaje->getInventario().size(); ++i) {
		if (palabra1 == toLower(personaje->getInventario()[i]->getNombre())) {
			tipo1 = "";
			tipo2 = "";
			return;
		}

		if (exist(palabra2, personaje->getInventario()[i]->getPalabras())) {
			tipo1 = "";
			tipo2 = "";
			return;
		}

		if (exist(palabra1, personaje->getInventario()[i]->getPalabras())) {
			tipo1 = "interactuar";

			if (palabra2 == toLower(personaje->getInventario()[i]->getNombre())) {
				item = personaje->getInventario()[i];
				tipo2 = "objeto";
			}
		}
	}
}

string Parser::toLower(string str) {
	string res;
	for (char c : str) {
		res += tolower(c);
	}
	return res;
}

void Parser::test(vector<string> str) {
	cout << "IMPRIMIENDO LISTA" << endl;
	for (string s : str) {
		cout << s << endl;
	}
}