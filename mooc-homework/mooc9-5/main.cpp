#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

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
		try {
			if (radius <= 0) {
				stringstream ss;
				ss << "Radius underflow: " << radius;
				throw underflow_error(ss.str());
			}
			radius_ = radius;
		}
		catch(int){}
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
	try {
		if (index == 0)
			return x_;
		else if (index == 1)
			return y_;
		else if (index == 2)
			return radius_;
		else {
			stringstream ss;
			ss << "Index exceeds scope: " << index;
			throw range_error(ss.str());
		}
	}
	catch (int) {};
}


int main() {
	int r1 = 0, r2 = 0;
	cin >> r1 >> r2;
	MyCircle c1, c2;
	try {
		c1.setRadius(r1);
		c2.setRadius(r2);
		for (int i = 0; i <= 3; i++) {
			cout << c1[i] << endl;
		}
	}
	catch (underflow_error& e) {
		cout << e.what() << endl;
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	try {
		c2[r1 / (r2 == 0 ? 1 : r2)] = 321;
		for (int i = 3; i >= 0; i--) {
			cout << c2[i - 1] << endl;
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif
	return 0;
}
