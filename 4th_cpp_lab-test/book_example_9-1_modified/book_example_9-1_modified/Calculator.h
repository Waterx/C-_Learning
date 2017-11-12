//Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"Stack.h"
class Calculator {
private:
	Stack<double>s;
	Stack<char>c;  //save operator
	bool getTwoOperands(double &opnd1, double &opnd2);
	char getOperator();
	void enter(double num);
	void compute(char op);
public:
	void run();
	void clear();
};


#endif // !CALCULATOR_H
