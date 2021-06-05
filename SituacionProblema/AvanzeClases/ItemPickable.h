#pragma once
class ItemPickable:public Item
{
public:
	ItemPickable(string);
	string getDesc();
	virtual string interactuar();
private:
	string accion;
};

ItemPickable::ItemPickable(string d) {
	accion = d;
}
string ItemPickable::getDesc() {

}
string ItemPickable::interactuar() {

}
