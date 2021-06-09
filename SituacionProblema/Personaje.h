#pragma once

#include<iostream>
#include<vector>
#include "Habitacion.h"
#include "ItemPickable.h"
using namespace std;

class Personaje
{
public:
	Personaje();
	Personaje(string,Habitacion*);
	void Parser();
	Habitacion* getHabitacion();
	void setHabitacionActual(Habitacion*);
	void addItem(ItemPickable*);
	ItemPickable* dropItem(int);
	void eliminarItem(int);
	vector<ItemPickable*> getInventario();
	ItemPickable* itemExist(string nombre);
	bool checkIfItemExists(string nombre);
	void desplazar(int);

private:
	string nombre;
	Habitacion *habActual;
	int numeroMovimientos;
	int maxInventario;
	vector<ItemPickable*> inventario;
};

Personaje::Personaje() { }

Personaje::Personaje(string nombre_ , Habitacion* hab) {
	nombre = nombre_;
	habActual = hab;
	maxInventario = 3;
}

void Personaje::Parser() {

}

Habitacion* Personaje::getHabitacion() {
	return habActual;
}

void Personaje::setHabitacionActual(Habitacion* hab) {
	habActual = hab;
	cout << habActual->getDescripcion() << endl;
}

void Personaje::addItem(ItemPickable *item) {
	inventario.push_back(item);
	if (habActual->quitarItem(item)) {
		cout << "Se elimino el item de la habitacion" << endl;
	}
	else {
		cout << "Error al eliminar el item de la habitacion" << endl;
	}

	cout << "Imprimiendo lista de items " << endl;
	for (int i = 0; i < inventario.size(); ++i) {
		cout << inventario[i]->getNombre() << endl;
	}
}

ItemPickable* Personaje::dropItem(int n) {
	return inventario[n];
}

void Personaje::eliminarItem(int n) {

}

vector<ItemPickable*> Personaje::getInventario() {
	return inventario;
}

ItemPickable* Personaje::itemExist(string nombre) {
	for (int i = 0; i < inventario.size(); ++i) {
		if (nombre == inventario[i]->getNombre())
			return inventario[i];
	}
	return NULL;
}

bool Personaje::checkIfItemExists(string nombre) {
	for (int i = 0; i < inventario.size(); ++i) {
		if (nombre == inventario[i]->getNombre())
			return true;
	}
	return false;
}

void Personaje::desplazar(int dir) {
	if (habActual->getSalida(dir) != NULL)
		habActual = habActual->getSalida(dir);
	else
		cout << "No existe esa habitacion " << endl;


	cout << "El personaje se movio" << endl;
	cout << habActual->getNombre() << endl;
	cout << habActual->getDescripcion() << endl;
}