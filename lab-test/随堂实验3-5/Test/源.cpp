#include <iostream>
#include <math.h>
using namespace std;

class Point {
public:

	Point(double x = 0, double y = 0);
	~Point();
	void Set(double x,double y);
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
private:
	double x;
	double y;
};
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
Point::~Point() {
	cout << "Delete" << endl;
}
void Point::Set(double x,double y) {
	this->x = x;
	this->y = y;
}

double Length(Point p[], int num) {    
	double length = 0.0;
	double a, b;
	for (int i = 0; i<num - 1; i++) {
		a = p[i].getX() - p[i + 1].getX();
		b = p[i].getY() - p[i + 1].getY();
		length += sqrt(a*a + b*b);
	}
	return length;
}
void Set(Point* ptr) {
	int x, y, i;
	for (i = 0; i < 10;i++) {
		cin >> x >> y;
		(ptr + i)->Set(x,y);
	}
}
void Display(Point* ptr) {
	for (int i = 0; i < 10; i++) {
		cout << "X:" << ptr[i].getX() << " " << "Y:" << ptr[i].getY() << endl;
	}
}
int main() {
	Point *ptr = new Point[10];
	Set(ptr);
	Display(ptr);
	cout << Length(ptr, 10) << endl;
	delete[] ptr;
	return 0;


}