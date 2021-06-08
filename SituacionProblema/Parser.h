#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Personaje.h"
#include "ListaPalabras.h"
#include "Habitacion.h"
using namespace std;

// Necesito tambien a todas las habitaciones

// Mensajes del Parser
const char* msg1 = "Todas las instrucciones deben tener menos de 3 palabras";
const char* msg2 = "Solo los comandos son instrucciones de una sola palabra. Verifique que la instruccion tecleada sea un comando";
const char* msg3 = "Revisa denuevo las palabras escritas. Al menos una palabra no es admitida por el juego";

class Parser
{
public:
	Parser(Personaje&, ListaPalabras&, Habitacion*);

	// El metodo procesa Comando se encarga de realizar toda la interaccion con el comando
	void procesaComando(string);
private:
	vector<string> getPalabras(string);
	bool exist(string, vector<string>);
	Personaje personaje;
	ListaPalabras palabras;
	Habitacion* habitaciones;
};

Parser::Parser(Personaje& personaje, ListaPalabras& palabras, Habitacion* habitaciones) {
	this->personaje = personaje;
	this->palabras = palabras;
	this->habitaciones = habitaciones;
}

void Parser::procesaComando(string instruccion) {
	// 1. Descomponemos el arreglo y verificamos que sea de la dimension correcta
	vector<string> str = getPalabras(instruccion);

	// Si size de str es 1, es un comando de sistema
	if (str.size() == 1) {
		// Buscamos en los comandos de sistema
		if (exist(str[0], palabras.getLista()[3])) {
			// Ejecutar el comando

		}
		else {
			cout << msg2 << endl;
		}
		return;
	} 

	// Si size de str es 2, es un comando de dos palabras
	if (str.size() == 2) {
		bool primer = false, segunda = false;

		// 2. Buscar que existan las palabras en la base de datos, tanto str[0] como str[1]
		for (int i = 0; i < palabras.getLista().size(); ++i) {
			if (exist(str[0], palabras.getLista()[i]))
				primer = true;
			if (exist(str[1], palabras.getLista()[i]))
				segunda = true;
		}

		// Busca tambien en todos los objetos que existen en el mundo
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < habitaciones[i].getItems().size(); ++i) {
				if (str[0] == habitaciones[i].getItems()[j]->getNombre())
					primer = true;
				if (exist(str[0],habitaciones[i].getItems()[j]->getPalabras()))
					primer = true;
				if (str[1] == habitaciones[i].getItems()[j]->getNombre())
					segunda = true;
				if (exist(str[1], habitaciones[i].getItems()[j]->getPalabras()))
					segunda = true;
			}
		}

		// Busca en el inventario del personaje y en las palabras de interactuar de cada Item
		for (int i = 0; i < personaje.getInventario().size(); ++i) {
			if (str[0] == personaje.getInventario()[i]->getNombre())
				primer = true;
			if (exist(str[0], personaje.getInventario()[i]->getPalabras()))
				primer = true;
			if (str[1] == personaje.getInventario()[i]->getNombre())
				segunda = true;
			if (exist(str[1], personaje.getInventario()[i]->getPalabras()))
				segunda = true;
		}

		if (!(primer && segunda)) {
			cout << msg3 << endl;
			return;
		}

		// Revisa la  forma semantica de la oracion

		// 4. 
		// Si str[1] es una palabra de desplazamiento
		//		Si str[0] es una palabra de ir a algun lugar como desplazar, ir, dirigete, etc:
		//			Ejecuta el desplazamiento
		//		Sino
		//			Retorna que la forma en la que esta escrito el comando es incorrecta
		// Si str[1] es una palabra objeto
		//		Si el objeto se encuentra en la habitacio o en el inventario del usuario:
		//			Si str[0] es una palabra de descripcion:
		//				Ejecuta objeto->getDesc()
		//			Si str[0] es una palabra de tomar:
		//				Si str[1] es un objeto pickable:
		//					Ejecuta personaje->addItem()
		//				Sino 
		//					Retorna que ese objeto no se puede tomar
		//			Si str[0] es una palabre de soltar:
		//				Si str[1] es un objeto pickable:
		//					Ejecuta personaje->dropItem()
		//				Sino
		//					Retorna que eses objeto no se puede soltar
		//			Si str[0] es una palabra de interactuar:
		//				Ejecuta personaje->Interactuar
		//		Sino
		//			Retorna que no existe el objeto en la habitacion o en el inventario

		return;
	}

	cout << msg1 << endl;
	return;
}

// Metodo que se encarga de separar las palabras y devolverlas ya separadas
vector<string> Parser::getPalabras(string instruccion) {
	string palabra;
	vector<string> palabras;
	stringstream ss(instruccion);
	while (ss >> palabra) palabras.push_back(palabra);
	return palabras;
}

bool Parser::exist(string palabra, vector<string> listaPalabras) {
	for (string str : listaPalabras) {
		if (str == palabra)
			return true;
	}
	return false;
}