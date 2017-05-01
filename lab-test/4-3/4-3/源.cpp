#include <iostream>
#include<string>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person() {
		name = "";
		age = 0;
		cout << "*Person ctor is invoked" << endl;
	}
	void InputInfo() {
		cout << "Input name:";
		cin >> name;
		cout << "Input age:";
		cin >> age;
	}
	void DisInfo() {
		cout << "Name:" << name << endl;
		cout << "Age:" << age << endl;
	}
};

class Leader :virtual public Person {
protected:
	string position;
	string depart;
public:
	Leader() {
		position = "";
		depart = "";
		cout << "*Leader ctor is invoked" << endl;
	}
	void InputInfo() {
		Person::InputInfo();
		cout << "Input position:";
		cin >> position;
		cout << "Input depart:";
		cin >> depart;
	}
	void DisInfo() {
		Person::DisInfo();
		cout << "Position:" << position << endl;
		cout << "Depart" << depart << endl;
		cout << endl;
	}
};
class Engineer :virtual public Person {
protected:
	string skill;
	string depart;
public:
	Engineer() {
		skill = "";
		depart = "";
		cout << "*Engineer ctor is invoked" << endl;
	}
	void InputInfo() {
		Person::InputInfo();
		cout << "Input skill:";
		cin >> skill;
		cout << "Input depart:";
		cin >> depart;
	}
	void DisInfo() {
		Person::DisInfo();
		cout << "Skill:" << skill << endl;
		cout << "Depart" << depart << endl;
		cout << endl;
	}
};
class Chairman :public Leader, public Engineer {
public:
	Chairman() {
		cout << "*Chairman ctor is invoked" << endl;
	}
	void InputInfo() {
		Person::InputInfo();
		cout << "Input skill:";
		cin >> skill;
		cout << "Input depart:";
		cin >> Leader::depart;
		Engineer::depart = Leader::depart;
		cout << "Input position:";
		cin >> position;
	}
	void DisInfo() {
		Person::DisInfo();
		cout << "Skill:" << skill << endl;
		cout << "Depart:" << Leader::depart << endl;
		cout << "Position:" << position << endl;
		cout << endl;
	}
};
int main() {
	Engineer engineer;
	engineer.InputInfo();
	engineer.DisInfo();
	Leader leader;
	leader.InputInfo();
	leader.DisInfo();
	Chairman chairman;
	chairman.InputInfo();
	chairman.DisInfo();
	return 0;
}
