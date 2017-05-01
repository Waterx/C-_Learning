
//Person.h

#pragma once
#include<string>
using namespace std;
class Person {
private:
	string name;
	int age;
public:
	Person();
	void InputInfo();
	void DisInfo();
};