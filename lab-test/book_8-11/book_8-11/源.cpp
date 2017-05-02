
//8-11

#include<iostream>
#include<string>
using namespace std;

class Shape {
private:
	string type;
public:
	Shape() {
		type = "Shape";
	}
	virtual double getArea() = 0;
	virtual double getPerim() = 0;
	int getVertexCount() const;
};
int Shape::getVertexCount() const {
	if (type == "Square") {
		return 4;
	}
	else if (type == "Rectangle") {
		return 4;
	}
	else if (type == "Circle") {
		return 0;
	}
	else if (type == "Shape") {
		return 0;
	}
}
class Rectangle :public Shape{
private:
	double length;
	double width;
	string type;
public:
	Rectangle(double nlength = 0, double nwidth = 0) :length(nlength), width(nwidth) {
		type = "Rectangle";
	}
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
	string type;
public:
	Circle(double nradius = 0) :radius(nradius) {
		type = "Circle";
	}
	double getArea() {
		return 3.14*radius*radius;
	}
	double getPerim() {
		return 6.28*radius;
	}
};
class Square :public Rectangle {
private:
	double length;
	string type;
public:
	Square(double nlength = 0) :length(nlength) {
		type = "Square";
	}
	double getArea() {
		return length*length;
	}
	double getPerim() {
		return 4 * length;
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
	Square square(length);
	cout << "Vertex count:" << square.getVertexCount() <<endl;
	cout << endl;

//---------------------------------------
	Square* s = new Square(5.5);
	Shape* sp = new Square(6.6);
	s = dynamic_cast<Square*>(sp);
	cout << s->getVertexCount() << endl;
	return 0;
}