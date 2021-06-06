#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Item
{
public:
	Item();
	virtual string getDesc();
	virtual string interuactar();
private:
	string desc;
	string nombre;
	vector<string> palabras;
};

Item::Item() {
}
string Item::getDesc() {
	return desc;
}
string Item::interuactar() {
	return "";
}
