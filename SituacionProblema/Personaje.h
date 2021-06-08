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
	void setHabitacionActual(Habitacion);
	void addItem(ItemPickable*);
	ItemPickable* dropItem(int);
	void eliminarItem(int);
	vector<ItemPickable*> getInventario();
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

void Personaje::setHabitacionActual(Habitacion hab) {

}

void Personaje::addItem(ItemPickable *item) {

}

ItemPickable* Personaje::dropItem(int n) {
	return inventario[n];
}

void Personaje::eliminarItem(int n) {

}

vector<ItemPickable*> Personaje::getInventario() {
	return inventario;
}