
//Student.h

#pragma once
//#include<string>
#include"Person.h"
using namespace std;
class Student :public Person {
private:
	string id;
	string clas;
	int grade;
public:
	Student();
	void InputInfo();
	void DisInfo();

};

