#pragma once
#include"Personaje.h"
class Evento
{
public:
	Evento(string,int,string, string);
	bool Ejecutar(int, Personaje*);
	void test();
private:
	string descripcion;
	int nAcciones;
	string habitacion;
	string nombreItem;
};

Evento::Evento(string desc, int n, string hab, string nom) {
	descripcion = desc;
	nAcciones = n;
	habitacion = hab;
	nombreItem = nom;
}

bool Evento::Ejecutar(int n, Personaje *personaje) {
	if (n >= nAcciones && personaje->getHabitacion()->getNombre() == habitacion) {
		if (nombreItem == "none" || personaje->checkIfItemExists(nombreItem)) {
			cout << descripcion << endl;
			return true;
		}
	}
	return false;
}

void Evento::test() {
	cout << descripcion << endl;
	cout << "N = " + to_string(nAcciones) << endl;
	cout << "habitacion: " + habitacion << endl << endl;
}

/*
txt:

#Descripcion del evento
Descripcion

STOP #Señal que indica que ya se termino la descripcion del evento

#Condiciones para que el evento se lanze
nAcciones 
habitacion en la que tiene que estar ubicado el jugador
*/

