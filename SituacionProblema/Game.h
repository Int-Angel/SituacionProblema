#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

#include"Evento.h"
#include"Personaje.h"
#include"Habitacion.h"
#include"Item.h"
#include"ItemConsumible.h"
#include"ItemPickable.h"
#include"ItemStatic.h"



/*

TODO:
	- Crear archivos de texto
		habitaciones
		items
		eventos

	[-] clase eventos
	- metodo crear items
	- metodo crear habitaciones
	[-] metodo crear eventos
	- metodo crear jugador


*/

class Game
{
public:
	Game();
	void crearJuego();
	void crearEventos();
	void crearJugador();
	void crearHabitaciones();
	void play();

private:
	int nEvento;
	vector<Evento*>evento;

	int nAcciones;

	Personaje* personaje;

	Habitacion* habitacion[4];
};

Game::Game() {
	nAcciones = 0;
	nEvento = 0;
	crearJuego();
}

void Game::crearJuego() {
	crearEventos();
	crearHabitaciones();
	crearJugador();
}

void Game::crearEventos() {
	int cont = 0;
	string linea;
	ifstream archivo;

	while (true) {
		archivo.open("evento" + to_string(cont) + ".txt");
		if (!archivo)break;

		string desc = "";
		int n = -1;
		string hab;

		while (getline(archivo,linea)) {
			if (linea == "STOP") {
				getline(archivo, linea);
				n = stoi(linea);
				getline(archivo, linea);
				hab = linea;
				break;
			}
			desc += linea + "\n";
		}
		evento.push_back(new Evento(desc, n, hab));
		archivo.close();
		cont++;
	}
}

void Game::crearHabitaciones() {
	string habitacionTxt[4] = { "taller.txt","cocina.txt","sala.txt","recamara.txt" };
	string linea;
	ifstream archivo;

	for (int i = 0; i < 4; i++) {
		archivo.open(habitacionTxt[i]);

		string nombre;
		string descripcion = "";
		bool cerrada;
		string nombreLlave = "";
		vector<string> itemsTxt;

		getline(archivo, nombre);

		while (getline(archivo, linea)) {
			if (linea == "STOP")break;
			descripcion += linea + "\n";
		}

		getline(archivo, linea);
		if (linea == "1") {
			cerrada = true;
			getline(archivo, nombreLlave);
		}
		else {
			cerrada = false;
		}

		while (getline(archivo, linea)) {
			itemsTxt.push_back(linea);
		}
		archivo.close();
		//TODO leer archivos de los items y agregar a las habitaciones

		habitacion[i] = new Habitacion(nombre, descripcion, cerrada, nombreLlave);
		//TODO agregar items
	}
	//TODO agregar salidas a las habitaciones

}

void Game::crearJugador() {

}

void Game::play() {

}

