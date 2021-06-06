#pragma once
class ItemPickable:public Item
{
public:
	ItemPickable(string, string, vector<string>,string);
	string getDesc();
	virtual string interactuar();
private:
	bool inventario;
	string accion;
	vector<string> palabrasAccion;
};

ItemPickable::ItemPickable(string desc_, string nombre_, vector<string> palabras_, string d):Item(desc_,nombre_,palabras_) {
	accion = d;
	inventario = false;
}
string ItemPickable::getDesc() {
	return getDesc();
}
string ItemPickable::interactuar() {
	return inventario ? accion : "Agregado al inventario";
}

/*
txt:
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
pickable
accion
#lista palabras para la accion
*/
