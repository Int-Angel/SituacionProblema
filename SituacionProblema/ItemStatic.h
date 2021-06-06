#pragma once
#include "ItemPickable.h"
class ItemStatic: public Item
{
public:
	ItemStatic(string, string, vector<string>,string[2]);
	string getDesc();
	string interactuar(Item*[10]);
private:
	int estado;
	string estados[2];
};

ItemStatic::ItemStatic(string desc_, string nombre_, vector<string> palabras_,string estados_[2]):Item(desc_,nombre_,palabras_) {
	estado = 0;
	estados[0] = estados_[0];
	estados[1] = estados_[1];
}
string ItemStatic::getDesc() {
	return getDesc();
}
string ItemStatic::interactuar(Item* inv[10]) {
	return estados[estado];
}

/*
txt:
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
static
#lista de estados
*/