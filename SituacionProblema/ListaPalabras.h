#pragma once
#include <vector>
#include <map>
using namespace std;

/*
	Clase que contiene la lista de todas las palabras del juego
	Estas listas funcionan como base para la clase command para conocer que palabras son correctas y cuales no
*/

class ListaPalabras
{
public:
	ListaPalabras();
	ListaPalabras(map<string, bool>&, map<string, bool>&, map<string, bool>&, map<string, bool>&);
	map<string, bool> getlistaAdd();
	void setlistaAdd(map<string, bool>&);
	map<string, bool> getListaDrop();
	void setListaDrop(map<string, bool>&);
	map<string, bool> getListaDesc();
	void setListaDesc(map<string, bool>&);
	map<string, bool> getListaCommand();
	void setListaCommand(map<string, bool>&);
private:
	map<string, bool> listaAdd;
	map<string, bool> listaDrop;
	map<string, bool> listaDesc;
	map<string, bool> listaCommand;
};

ListaPalabras::ListaPalabras() { }

ListaPalabras::ListaPalabras(map<string, bool>& add, map<string, bool>& drop, map<string, bool>& desc, map<string, bool>& command) {
	listaAdd = add;
	listaDrop = drop;
	listaDesc = desc;
	listaCommand = command;
}

map<string, bool> ListaPalabras::getlistaAdd() { return listaAdd; }

void ListaPalabras::setlistaAdd(map<string, bool>& add) {
	listaAdd = add;
}

map<string, bool> ListaPalabras::getListaDrop() { return listaDrop; }

void ListaPalabras::setListaDrop(map<string, bool>& drop) {
	listaDrop = drop;
}

map<string, bool> ListaPalabras::getListaDesc() { return listaDesc; }

void ListaPalabras::setListaDesc(map<string, bool>& desc) {
	listaDesc = desc;
}

map<string, bool> ListaPalabras::getListaCommand() { return listaCommand; }

void ListaPalabras::setListaCommand(map<string, bool>& command) {
	listaCommand = command;
}