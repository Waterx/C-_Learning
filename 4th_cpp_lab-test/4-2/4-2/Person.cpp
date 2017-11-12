
//Person.cpp

#include"Person.h"
#include<iostream>
using namespace std;
Person::Person() {
	name = "";
	age = 0;
}
void Person::InputInfo() {
	cout << "Input name:";
	cin >> name;
	cout << endl;
	cout << "Input age:";
	cin >> age;
	cout << endl;
}
void Person::DisInfo() {
	cout << "Name:" << name << endl;
	cout << "Age:" << age << endl;
}