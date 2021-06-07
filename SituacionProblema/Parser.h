#pragma once
#include <vector>
#include <string>
#include "Personaje.h"
#include "ListaPalabras.h"
using namespace std;

// Necesito tambien a todas las habitaciones

class Parser
{
public:
	Parser(Personaje&, ListaPalabras&);

	// El metodo procesa Comando se encarga de realizar toda la interaccion con el comando
	void procesaComando(string);
private:
	vector<string> getPalabras(string);
	Personaje personaje;
	ListaPalabras palabras;
};

Parser::Parser(Personaje& personaje, ListaPalabras& palabras) {
	this->personaje = personaje;
	this->palabras = palabras;
}

void Parser::procesaComando(string frase) {
	// 1. Descomponemos el arreglo y verificamos que sea de la dimension correcta

	vector<string> str = getPalabras(frase);

	// Si size de str es 1, es un comando de sistema
	if (str.size() == 1) {
	
		return;
	} 

	// Si size de str es 2, es un comando de dos palabras
	if (str.size() == 2) {

		// 2. Buscar que existan las palabras en la base de datos, tanto str[0] como str[1]
		// Para ambos casos busca en todas las listas de ListaPalabra
		// Busca tambien en todos los objetos que existen en el mundo
		// Busca tambien en la lista de palabras del personaje, es decir de desplazamiento
		// Si las dos estan prosigue al paso 3. Si alguna no esta, retorna que alguna palabra esta mal escrita

		// 3. Busca que str[1] sea un objeto o una palabra de desplazamiento como norte, sur, este, etc.
		// Si str[1] si es, sigue al paso 4. Si no, retorna que es incorrecta la forma en la que esta escrito el comando

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

	// El comando no puede ser de dimension 0 o mayor a 3 palabras
	// TODO: Terminar eso xd
	return;
}

// Metodo que se encarga de separar las palabras y devolverlas ya separadas
vector<string> Parser::getPalabras(string) {

}
