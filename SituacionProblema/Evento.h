#pragma once



class Evento
{
public:
	Evento(string,int,string);
	bool Ejecutar(int, string);
	void test();
private:
	string descripcion;
	int nAcciones;
	string habitacion;
};

Evento::Evento(string desc, int n, string hab) {
	descripcion = desc;
	nAcciones = n;
	habitacion = hab;
}

bool Evento::Ejecutar(int n, string hab) {
	//TODO
	return true;
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

