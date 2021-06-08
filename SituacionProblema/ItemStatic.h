#pragma once
#include "Item.h"
class ItemStatic: public Item
{
public:
	ItemStatic(string, string, vector<string>,string[2]);
	string getDesc();
	string interactuar(Item*[10]);
	void test()override;
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
	return Item::getDesc();
}
string ItemStatic::interactuar(Item* inv[10]) {
	return estados[estado];
}

void ItemStatic::test() {
	Item::test();
	cout << "Estados" << endl;
	cout << estados[0] << endl;
	cout << estados[1] << endl;
	cout << "_______________________________________" << endl;
}

/*
txt:
static
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
#lista de estados
*/