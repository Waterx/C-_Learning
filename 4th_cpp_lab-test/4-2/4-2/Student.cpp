
//Student.cpp

#include"Student.h"
#include<iostream>
using namespace std;
Student::Student() {
	id = "";
	clas = "";
	grade = 0;
}
void Student::InputInfo() {
	Person::InputInfo();
	cout << "Input id:";
	cin >> id;
	cout << endl;
	cout << "Input class:";
	cin >> clas;
	cout << endl;
	cout << "Input grade:";
	cin >> grade;
	cout << endl;
}
void Student::DisInfo() {
	Person::DisInfo();
	cout << "Id:" << id << endl;
	cout << "Class:" << clas << endl;
	cout << "Grade" << grade << endl;
}