#pragma once
#include"Item.h"
class ItemPickable:public Item
{
public:
	ItemPickable(string, string, vector<string>,string);
	string getDesc();
	virtual string interactuar();
	void test()override;
private:
	bool inventario;
	string accion;
};

ItemPickable::ItemPickable(string desc_, string nombre_, vector<string> palabras_, string d):Item(desc_,nombre_,palabras_) {
	accion = d;
	inventario = false;
}
string ItemPickable::getDesc() {
	return Item::getDesc();
}
string ItemPickable::interactuar() {
	return inventario ? accion : "Agregado al inventario";
}

void ItemPickable::test() {
	Item::test();
	cout << "Accion: " + accion << endl;
	cout << "Palabras accion: " << endl;
	cout << "_______________________________________" << endl;
}

/*
txt:
pickable
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
accion
#lista palabras para la accion
*/
