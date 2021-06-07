#pragma once

#include<iostream>
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
private:
	string nombre;
	Habitacion *habActual;
	int numeroMovimientos;
	ItemPickable *inventario[10];
};

Personaje::Personaje() { }

Personaje::Personaje(string nombre_ , Habitacion* hab) {
	nombre = nombre_;
	habActual = hab;
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