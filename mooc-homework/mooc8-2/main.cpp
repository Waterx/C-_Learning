#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class MyShape {
protected:
	int R_, G_, B_;

	string colorToString() {
		stringstream ss;
		ss << R_ << " " << G_ << " " << B_;
		return ss.str();
	}
public:
	void setColor(int R, int G, int B) {
		R_ = R; G_ = G, B_ = B;
	}
	int getR() {
		return R_;
	}
	int getG() {
		return G_;
	}
	int getB() {
		return B_;
	}
	virtual void Draw() = 0;
	MyShape() {
		R_ = 255; G_ = 255, B_ = 255;
	}
};

class MyCircle : public MyShape {
private:
	int x_, y_, radius_;
	//int min_int = INT_MIN; //That can used in vs but not dev
	int min_int = numeric_limits<int>::min();
public:
	MyCircle(int x, int y, int radius) {
		x_ = x;
		y_ = y;
		radius_ = radius;
	}

	MyCircle() {
		x_ = y_ = 200;
		radius_ = 100;
	}

	MyCircle(MyCircle& aCircle) {
		x_ = aCircle.x_;
		y_ = aCircle.y_;
		radius_ = aCircle.radius_;
		R_ = aCircle.getR();
		G_ = aCircle.getG();
		B_ = aCircle.getB();
	}
	void setCenter(int x, int y) {
		x_ = x;
		y_ = y;
	}

	void setRadius(int radius) {
		radius_ = radius;
	}

	void Draw() {
	}

	//----在此处添加关系运算符  >、<、>=、<=、==、!=  的重载原型声明
	bool operator>(MyCircle &secondMyCircle);
	bool operator<(MyCircle &secondMyCircle);
	bool operator>=(MyCircle &secondMyCircle);
	bool operator<=(MyCircle &secondMyCircle);
	bool operator==(MyCircle &secondMyCircle);
	bool operator!=(MyCircle &secondMyCircle);
	int& operator[](const int &index);
};

//----在此处添加关系运算符的重载定义
bool MyCircle::operator>(MyCircle &secondMyCircle) {
	return this->radius_ > secondMyCircle.radius_;
}
bool MyCircle::operator<(MyCircle &secondMyCircle) {
	return this->radius_ < secondMyCircle.radius_;
}
bool MyCircle::operator>=(MyCircle &secondMyCircle) {
	return this->radius_ >= secondMyCircle.radius_;
}
bool MyCircle::operator<=(MyCircle &secondMyCircle) {
	return this->radius_ <= secondMyCircle.radius_;
}
bool MyCircle::operator==(MyCircle &secondMyCircle) {
	return this->radius_ == secondMyCircle.radius_;
}
bool MyCircle::operator!=(MyCircle &secondMyCircle) {
	return this->radius_ != secondMyCircle.radius_;
}
int& MyCircle::operator[](const int &index) {
	if (index == 0)
		return x_;
	else if (index == 1)
		return y_;
	else if (index == 2)
		return radius_;
	else
		return min_int;
}
int main() {
	int x, y, r = 0;
	cin >> x >> y >> r;
	MyCircle c1(x, y, r);
	MyCircle c2;
	c2[2] = x;
	for (int i = 0; i <= 3; i++) {
		cout << c1[i] << endl;
		cout << c2[i - 1] << endl;
	}

	return 0;
}