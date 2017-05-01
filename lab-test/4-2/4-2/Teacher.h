
//Teacher.h

#pragma once
//#include<string>
#include"Person.h"
using namespace std;
class Teacher :public Person {
private:
	string id;
	string level;
	string depart;
public:
	void InputInfo();
	void DisInfo();
};