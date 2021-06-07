#pragma once

#include <iostream>
#include "Item.h"
using namespace std;
class Habitacion
{
public:
	Habitacion(string,string,bool);
	Habitacion(string, string, bool,string);
	Item getItem(int);
	void setItem(int Item);
	Item quitarItem(int);
	string getDescripcion();
	void setItems(vector<Item*>);
	void setDescripcion(string);
	void test();
private:
	string nombre;
	string descripcion;
	vector<Item*> item;
	Habitacion *salidas[4];
	bool cerrada;
	string nombreLlave;
};

Habitacion::Habitacion(string nombre_,string des, bool cerrada_) {
	nombre = nombre_;
	descripcion = des;
	cerrada = cerrada_;
	nombreLlave = "";
}

Habitacion::Habitacion(string nombre_, string des, bool cerrada_,string nombreLlave_) {
	nombre = nombre_;
	descripcion = des;
	cerrada = cerrada_;
	nombreLlave = nombreLlave_;
}

void Habitacion::setItems(vector<Item*> item_) {
	item = item_;
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

void Habitacion::test() {
	cout << nombre << endl;
	cout << descripcion << endl;
	cout << cerrada << endl;
	cout << nombreLlave << endl << endl;
	cout << "ITEMS: " + to_string(item.size())<< endl;
	for (int i = 0; i < item.size(); i++) {
		item[i]->test();
	}
	cout << endl << endl;
}

/*
txt:

#nombre 1 sola linea
#descripcion
STOP #señal que termino la descripcion
0 o 1 #bool cerrada   0-> false   1->true
#lista de nombres de txt que son los items de la habitacion
*/

