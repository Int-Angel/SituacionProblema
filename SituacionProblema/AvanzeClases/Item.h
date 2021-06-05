#pragma once
#include<iostream>
using namespace std;

class Item
{
public:
	Item();
	virtual string getDesc();
	virtual string interuactar();
private:
	string desc;
	map<string, string>palabras;
};

Item::Item() {

}
string Item::getDesc() {

}
string Item::interuactar() {

}
