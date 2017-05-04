
//book_8-11

#include<iostream>
#include<string>
#include<typeinfo>
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
	virtual int getVertexCount() const;
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
	else {
		return -1;
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
	/*double r, length, width;
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
	cout << endl;*/

//---------------------------------------
	
	Shape* shape = new Square(6.6);
	Square* square = new Square(5.5);
	square = dynamic_cast<Square*>(shape);
	cout << "In dynamic_cast mode:" << square->getVertexCount() << endl;

	Shape* shape1 = new Rectangle(5, 4);
	Rectangle* rectangle1 = new Rectangle(6, 7);
	cout << "In typeid mode:" << typeid(rectangle1->getVertexCount()).name() << endl;
	
	

//----------------------------------------
	
	return 0;
}