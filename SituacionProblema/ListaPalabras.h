#pragma once
#include <vector>
#include <map>
using namespace std;

/*
	Clase que contiene la lista de todas las palabras globales del juego
	Estas palabras son las listas de:
		[0] addItem -> agregar objetos
		[1] dropItem -> soltar los objetos
		[2] desc -> descripcion de los items
		[3] command -> comandos de la aplicacion
		[4] desplazamiento -> palabras para desplazar al usuario
*/

class ListaPalabras
{
public:
	ListaPalabras();
	ListaPalabras(vector<vector<string>>&);
	vector<vector<string>> getLista();
	void setLista(vector<vector<string>>&);
private:
	vector<vector<string>> lista;
};

ListaPalabras::ListaPalabras() { }

ListaPalabras::ListaPalabras(vector<vector<string>>& lista) {
	this->lista = lista;
}

vector<vector<string>> ListaPalabras::getLista() { return lista; }

void ListaPalabras::setLista(vector<vector<string>>& lista) {
	this->lista = lista;
}