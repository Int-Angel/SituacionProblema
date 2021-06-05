#pragma once
class ItemConsumible: public Item
{
public:
	ItemConsumible(int);
	string interactuar();
	int getCantidad();
	void setCantidad(int);
private:
	int cantidad;
};

ItemConsumible::ItemConsumible(int n) {
	cantidad = n;
}
string ItemConsumible::interactuar() {

}
int ItemConsumible::getCantidad() {
	return cantidad;
}
void ItemConsumible::setCantidad(int n) {
	cantidad = n;
}