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
#include"Parser.h"
#include"ListaPalabras.h"

class Game
{
public:
	Game();
	void play();

private:
	int nEvento;
	vector<Evento*>evento;
	int nAcciones;
	Personaje* personaje;
	Habitacion* habitacion[4];
	ListaPalabras palabras;
	Parser parser;

	void crearJuego();
	void crearEventos();
	void crearJugador();
	void crearHabitaciones();
	void crearListaPalabras();
	vector<Item*>crearItems(vector<string>);
	ItemStatic* crearItemStatic(string);
	ItemConsumible* crearItemConsumible(string);
	ItemPickable* crearItemPickable(string);
};

Game::Game() {
	nAcciones = 0;
	nEvento = 0;
	crearJuego();
}

void Game::crearJuego() {
	crearEventos();
	crearHabitaciones();
	crearListaPalabras();
	crearJugador();

	parser = Parser(personaje, palabras);
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
		string nomItem;

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
		getline(archivo, nomItem);
		evento.push_back(new Evento(desc, n, hab,nomItem));
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

		habitacion[i] = new Habitacion(nombre, descripcion, cerrada, nombreLlave);
		habitacion[i]->setItems(crearItems(itemsTxt));
	}
	
	habitacion[0]->setSalidas(habitacion[2], habitacion[1], NULL, NULL);
	habitacion[1]->setSalidas(habitacion[0], NULL, NULL, NULL);
	habitacion[2]->setSalidas(NULL, habitacion[0], NULL, habitacion[3]);
	habitacion[3]->setSalidas(NULL, NULL, habitacion[2], NULL);

	for (int i = 0; i < 4; i++) {
		habitacion[i]->test();
	}
}

vector<Item*> Game::crearItems(vector<string> itemsTxt) {
	vector<Item*> items;
	string linea;
	ifstream archivo;

	for (int i = 0; i < itemsTxt.size(); i++) {
		archivo.open(itemsTxt[i]);
		getline(archivo, linea);
		archivo.close();

		if (linea == "static") {
			items.push_back(crearItemStatic(itemsTxt[i]));
		}
		else if (linea == "consumible") {
			items.push_back(crearItemConsumible(itemsTxt[i]));
		}
		else if (linea == "pickable") {
			items.push_back(crearItemPickable(itemsTxt[i]));
		}
		else {
			cout << "No se pudo identificar el item: " + itemsTxt[i] << endl;
		}
	}

	return items;
}

ItemStatic* Game::crearItemStatic(string itemTxt) {
	string linea;
	ifstream archivo;
	archivo.open(itemTxt);

	string desc, nombre;
	vector<string> palabras;

	getline(archivo, linea);
	getline(archivo, nombre);
	getline(archivo, desc);

	while (getline(archivo, linea)) {
		if (linea == "STOP") break;
		palabras.push_back(linea);
	}

	//////////////////////////////////////////////

	string estados[2];
	getline(archivo, estados[0]);
	getline(archivo, estados[1]);

	archivo.close();
	return new ItemStatic(desc, nombre, palabras, estados);
}

ItemConsumible* Game::crearItemConsumible(string itemTxt) {
	string linea;
	ifstream archivo;
	archivo.open(itemTxt);

	string desc, nombre;
	vector<string> palabras;

	getline(archivo, linea);
	getline(archivo, nombre);
	getline(archivo, desc);

	while (getline(archivo, linea)) {
		if (linea == "STOP") break;
		palabras.push_back(linea);
	}

	//////////////////////////////////////////////

	int n;
	string accion;
	vector<string> palabras2;

	getline(archivo, linea);
	n = stoi(linea);
	getline(archivo, accion);

	while (getline(archivo, linea)) {
		palabras2.push_back(linea);
	}

	archivo.close();
	return new ItemConsumible(desc, nombre, palabras, n, accion, palabras2);
}

ItemPickable* Game::crearItemPickable(string itemTxt) {
	string linea;
	ifstream archivo;
	archivo.open(itemTxt);

	string desc, nombre;
	vector<string> palabras;

	getline(archivo, linea);
	getline(archivo, nombre);
	getline(archivo, desc);

	while (getline(archivo, linea)) {
		if (linea == "STOP") break;
		palabras.push_back(linea);
	}

	//////////////////////////////////////////////

	string accion;
	vector<string> palabras2;

	getline(archivo, accion);

	while (getline(archivo, linea)) {
		palabras2.push_back(linea);
	}

	archivo.close();
	return new ItemPickable(desc, nombre, palabras, accion, palabras2);
}

void Game::crearJugador() {
	string nom;
	cout << "Ingresa tu nombre: ";
	cin >> nom;
	cin.ignore();
	personaje = new Personaje(nom, habitacion[0]);
}

void Game::crearListaPalabras() {
	
	vector<string> instruccionesTxt{ "agregar.txt","comandos.txt","desc.txt","desplazamiento.txt", "lugar.txt", "soltar.txt" };
	vector<vector<string>> instrucciones(instruccionesTxt.size());
	string linea;
	ifstream archivo;

	for (int i = 0; i < instruccionesTxt.size(); i++) {
		archivo.open("instrucciones/"+instruccionesTxt[i]);
		while (getline(archivo, linea)) {
			instrucciones[i].push_back(linea);
		}
		archivo.close();
	}
	palabras.setLista(instrucciones);
	palabras.setTipos(vector<string>{"agregar", "comandos", "descripcion", "desplazamiento", "lugar", "soltar" });
	// palabras.test();
}

void Game::play() {
	string instruccion;

	while (true) {
		getline(cin, instruccion);
		parser.procesaComando(instruccion);
	}
}

