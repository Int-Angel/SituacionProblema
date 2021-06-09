#pragma once

#include <iostream>
#include "Item.h"
#include "Personaje.h"
using namespace std;
class Habitacion
{
public:
	Habitacion(string,string,bool);
	Habitacion(string, string, bool,string);
	Item getItem(int);
	void setItem(int Item);
	vector<Item*> getItems();
	void setItems(vector<Item>);
	bool quitarItem(Item*);
	string getDescripcion();
	string getNombre();
	void setItems(vector<Item*>);
	void setSalidas(Habitacion*, Habitacion*, Habitacion*, Habitacion*);
	Habitacion* getSalida(int n);
	Item* itemExist(string);
	bool isClosed();
	void setClosed(bool);
	string getNombreLlave();
	friend ostream& operator<<(ostream& salida, Habitacion* hab);
	bool quitarItem(Item*);

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

vector<Item*> Habitacion::getItems() {
	return item; 
}

bool Habitacion::quitarItem(Item* item_) {
	for (int i = 0; i < item.size(); ++i) {
		if (item_ == item[i]) {
			Item* aux = item[i];
			item.erase(item.begin() + i);
			return true;
		}
	}
	return false;
}

string Habitacion::getDescripcion() {
	string des = nombre + "\n";
	des += descripcion + "\n";
	des += "En esta habitacion puedes encontrar: \n";
	for (int i = 0; i < item.size(); ++i) {
		des += item[i]->getDesc() + "\n";
	}
	return des;
}

string Habitacion::getNombre() {
	return nombre;
}

void Habitacion::setSalidas(Habitacion* norte, Habitacion* sur, Habitacion* este, Habitacion* oeste) {

	salidas[0] = norte;
	salidas[1] = este;
	salidas[2] = sur;
	salidas[3] = oeste;
	/*
	Salidas:
	0 -> norte
	1 -> este
	2 -> sur
	3 -> oeste
	*/
}

Habitacion* Habitacion::getSalida(int n) {
	return salidas[n];
}

Item* Habitacion::itemExist(string nombre) {
	for (int i = 0; i < item.size(); ++i) {
		if (nombre == item[i]->getNombre())
			return item[i];
	}
	return NULL;
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

	for (int i = 0; i < 4; i++) {
		if (salidas[i] != NULL) {
			cout << salidas[i]->nombre << endl;
		}
	}
	cout << endl << endl << endl;
}

bool Habitacion::isClosed() {
	return cerrada;
}

void Habitacion::setClosed(bool c) {
	cerrada = c;
}

string Habitacion::getNombreLlave() {
	return nombreLlave;
}

ostream& operator<<(ostream& salida, Habitacion* hab) {
	salida << hab->getDescripcion();
	return salida;
}

bool Habitacion::quitarItem(Item* item_) {
	for (int i = 0; i < item.size(); ++i) {
		if (item_ == item[i]) {
			Item* aux = item[i];
			item.erase(item.begin() + i);
			return true;
		}
	}
	return false;
}


/*
txt:

#nombre 1 sola linea
#descripcion
STOP #se�al que termino la descripcion
0 o 1 #bool cerrada   0-> false   1->true
#lista de nombres de txt que son los items de la habitacion
*/

