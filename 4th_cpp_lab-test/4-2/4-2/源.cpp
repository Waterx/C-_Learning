
//main.cpp

#include"Person.h"
#include"Student.h"
#include"Teacher.h"
int main() {
	Student stu;
	stu.InputInfo();
	stu.DisInfo();
	Teacher teacher;
	teacher.InputInfo();
	teacher.DisInfo();
	return 0;
}
