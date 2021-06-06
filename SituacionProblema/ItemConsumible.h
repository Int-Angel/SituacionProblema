#pragma once
class ItemConsumible: public Item
{
public:
	ItemConsumible(string, string, vector<string>,int,string);
	string interactuar();
	int getCantidad();
	void setCantidad(int);
private:
	bool inventario;
	int cantidad;
	string accion;
	vector<string> palabrasAccion;
};

ItemConsumible::ItemConsumible(string desc_, string nombre_, vector<string> palabras_,int n,string accion_):Item(desc_, nombre_, palabras_) {
	cantidad = n;
	accion = accion_;
	inventario = false;
}
string ItemConsumible::interactuar() {
	return inventario ? accion : "Agregado al inventario";
}
int ItemConsumible::getCantidad() {
	return cantidad;
}
void ItemConsumible::setCantidad(int n) {
	cantidad = n;
}

/*
txt:
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
consumible
cantidad
accion
#lista palabras para la accion
*/