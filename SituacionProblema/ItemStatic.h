#pragma once
#include "ItemPickable.h"
class ItemStatic: public Item
{
public:
	ItemStatic(string[5],bool,ItemPickable);
	string getDesc();
	string interactuar(Item*[10]);
private:
	int estado;
	string estados[5];
	bool requirementActive;
	ItemPickable *item;
};

ItemStatic::ItemStatic(string estados_[5], bool estado_, ItemPickable i) {

}
string ItemStatic::getDesc() {
	return getDesc();
}
string ItemStatic::interactuar(Item* inv[10]) {
	return "TODO";
}