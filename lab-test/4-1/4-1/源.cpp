#include<iostream>
#include<cmath>
using namespace std;

class CircleGroup {
private:
	double radius_;
public:
	CircleGroup() {}
	virtual double Area() = 0;    //´¿Ðéº¯Êý
	virtual double Volume() = 0;
	double getRadius() {
		return radius_;
	}
	void setRaidus(double radius) {
		radius_ = radius;
	}
};

class Ball :public CircleGroup {

public:
	Ball(double radius) {
		setRaidus(radius);
	}
	double Area() {
		return 4 * 3.14*getRadius()*getRadius();
	}
	double Volume() {
		return 4 / 3 * 3.14*getRadius()*getRadius()*getRadius();
	}
};

class Cone :public CircleGroup {
private:
	double generatrix_;   //Ä¸Ïß
public:
	Cone(double radius, double generatrix) {
		generatrix_ = generatrix;
		setRaidus(radius);
	}
	double Area() {
		return 3.14*(getRadius()*generatrix_ + getRadius()*getRadius());
	}
	double Volume() {
		return 1 / 3 * 3.14*getRadius()*getRadius()*sqrt(generatrix_*generatrix_ - getRadius()*getRadius());
	}
};

class Cylinder :public CircleGroup {
private:
	double height_;
public:
	Cylinder(double radius, double height) {
		setRaidus(radius);
		height_ = height;
	}
	double Area() {
		return 2 * 3.14*getRadius()*getRadius() + 3.14 * 2 * getRadius()*height_;
	}
	double Volume() {
		return 3.14*getRadius()*getRadius()*height_;
	}
};


int main() {
	Ball ball(5.5);
	Cylinder cylinder(5.0, 3.0);
	Cone cone(6.3, 7.8);
	cout << "BALL:" << ball.Area() << " " << ball.Volume() << endl;
	cout << "CYLINDER:" << cylinder.Area() << " " << cylinder.Volume() << endl;
	cout << "CONE:" << cone.Area() << " " << cone.Volume() << endl;
	return 0;
}
