#pragma once

#include <iostream>
#include "Item.h"
using namespace std;
class Habitacion
{
public:
	Habitacion(string, Item* [4], Habitacion* [4]);
	Item getItem(int);
	void setItem(int Item);
	Item quitarItem(int);
	string getDescripcion();
	void setDescripcion(string);
private:
	string descripcion;
	Item *item[4];
	Habitacion *salidas[4];
	bool cerrada;
};

Habitacion::Habitacion(string des, Item* items_[4], Habitacion* salidas_[4]) {
	descripcion = des;
	*item = *items_;
	*salidas = *salidas_;
}

Item Habitacion::getItem(int n) {
	return *item[n];
}

void Habitacion::setItem(int Item) {

}

Item Habitacion::quitarItem(int n) {
	return *item[n];
}

string Habitacion::getDescripcion() {
	return descripcion;
}

void Habitacion::setDescripcion(string d) {

}

