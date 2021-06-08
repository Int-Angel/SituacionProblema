#pragma once
class ItemPickable:public Item
{
public:
	ItemPickable(string, string, vector<string>,string);
	string getDesc();
	string interactuar() override;
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
	//return inventario ? accion : "Agregado al inventario";
	cout << "Accion " + accion << endl;
	return accion;
}

void ItemPickable::test() {
	Item::test();
	cout << "Accion: " + accion << endl;
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
*/
