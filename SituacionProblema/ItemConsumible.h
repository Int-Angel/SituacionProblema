#pragma once
class ItemConsumible: public Item
{
public:
	ItemConsumible(string, string, vector<string>,int,string, vector<string>);
	string interactuar();
	int getCantidad();
	void setCantidad(int);
	void test()override;
private:
	bool inventario;
	int cantidad;
	string accion;
	vector<string> palabrasAccion;
};

ItemConsumible::ItemConsumible(string desc_, string nombre_, vector<string> palabras_,int n,string accion_, vector<string> palabrasAccion_):Item(desc_, nombre_, palabras_) {
	cantidad = n;
	accion = accion_;
	palabrasAccion = palabrasAccion_;
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

void ItemConsumible::test() {
	Item::test();
	cout << "Cantidad: " << cantidad << endl;
	cout << "Accion: " + accion << endl;
	cout << "Palabras accion: " << endl;
	for (int i = 0; i < palabrasAccion.size(); i++) {
		cout << palabrasAccion[i] << endl;
	}
	cout << "_______________________________________" << endl;
}

/*
txt:
consumible
#nombre una sola linea
#descropcion una sola linea
#lista de palabras
STOP
cantidad
accion
#lista palabras para la accion
*/