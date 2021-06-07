#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Item
{
public:
	Item(string, string, vector<string>);
	virtual string getDesc();
	virtual string interuactar();
	virtual void test();
private:
	string desc;
	string nombre;
	vector<string> palabras;
};

Item::Item(string desc_, string nombre_, vector<string> palabras_) {
	desc = desc_;
	nombre = nombre_;
	palabras = palabras_;
}
string Item::getDesc() {
	return desc;
}
string Item::interuactar() {
	return "";
}
void Item::test() {
	cout << "_______________________________________" << endl;
	cout << nombre << endl;
	cout << desc << endl;
	cout << "Palabras interactuar: " << endl;
	for (int i = 0; i < palabras.size(); i++) {
		cout << palabras[i] << endl;
	}
}