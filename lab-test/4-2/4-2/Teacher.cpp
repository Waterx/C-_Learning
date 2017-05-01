
//Teacher.cpp

#include"Teacher.h"
#include<iostream>
using namespace std;
void Teacher::InputInfo() {
	Person::InputInfo();
	cout << "Input id:";
	cin >> id;
	cout << endl;
	cout << "Input level:";
	cin >> level;
	cout << endl;
	cout << "Input depart:";
	cin >> depart;
	cout << endl;
}
void Teacher::DisInfo() {
	Person::DisInfo();
	cout << "Id:" << id << endl;
	cout << "Level:" << level << endl;
	cout << "Department" << depart << endl;
}