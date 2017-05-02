
//8-6

#include<iostream>
using namespace std;

class Shape {
public:
	virtual double getArea() = 0;
	virtual double getPerim() = 0;
};
class Rectangle :public Shape{
private:
	double length;
	double width;
public:
	Rectangle(double nlength = 0,double nwidth = 0):length(nlength),width(nwidth){}
	double getArea() {
		return length*width;
	}
	double getPerim() {
		return 2 * (length + width);
	}
};
class Circle :public Shape{
private:
	double radius;
public:
	Circle(double nradius = 0) :radius(nradius) {}
	double getArea() {
		return 3.14*radius*radius;
	}
	double getPerim() {
		return 6.28*radius;
	}
};

int main() {
	double r, length, width;
	cin >> r >> length >> width;
	Circle circle(r);
	cout << "Circle Area:" << circle.getArea() << endl;
	cout << "Circle Perim:" << circle.getPerim() << endl;
	cout << endl;
	Rectangle rectangle(length, width);
	cout << "Rectangle Area:" << rectangle.getArea() << endl;
	cout << "Rectangle Perim:" << rectangle.getPerim() << endl;
	cout << endl;
	system("pause");
	return 0;
}