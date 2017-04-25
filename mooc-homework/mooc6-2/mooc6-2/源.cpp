
//mooc6-2

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Screen;
class MyRectangle;
class MyCircle;
class MyShape;

class Screen {
public:
	~Screen();
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	static Screen* getInstance(int width = 640, int height = 480);
	static void deleteInstance();
	static int isSimpleObj(int objNum);


private:
	Screen(int newWidth, int newHeight);
	int width;
	int height;
	int exitWhenInvalidScreen(int width, int height);
	string enter;
	string leave;
	static Screen* instance;
	static int objNum;
};

int Screen::objNum = 0;
Screen* Screen::instance = 0;
Screen::Screen(int newWidth, int newHeight) {
	if (isSimpleObj(Screen::objNum)) {
		width = newWidth;
		height = newHeight;
		enter = "enter screen";
		leave = "leave screen";
		cout << enter << endl;
		exitWhenInvalidScreen(width, height);
		Screen::objNum++;
	}
}
Screen::~Screen() {
	cout << leave << endl;
	Screen::objNum--;       
}
int Screen::exitWhenInvalidScreen(int width, int height) {
	if (width > 0 && height > 0 && width <= 1000 && height <= 1000)
	{
		return 1;
	}
	else
	{
		cout << "invalid screen size";
		exit(0);
	}
}
Screen* Screen::getInstance(int width, int height) {
	if (instance == 0) {
		return instance = new Screen(width, height);
	}
	else {
		return instance;
	}
}
void Screen::deleteInstance() {
	delete instance;
	instance = 0;
}
int Screen::isSimpleObj(int objNum) {
	if (objNum == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

class MyShape {
private:
	int R_, G_, B_;
	Screen* screen_;
	string type_;
public:
	MyShape(Screen* screen = 0) {
		R_ = G_ = B_ = 255;
		type_ = "myshape";
		screen_ = screen;
	}
	void setColor(int R, int G, int B) {
		R_ = R;
		G_ = G;
		B_ = B;
	}
	void setScreen(Screen& screen) {
		screen_ = &screen;
	}
	void setType(string string) {
		type_ = string;
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
	void showShape();
};
void MyShape::showShape() {
	cout << "[" << screen_->getWidth() << "X" << screen_->getHeight() << "]"
		<< type_ << "(" << R_ << "," << G_ << "," << B_ << ")" << endl;
}

class MyRectangle :public MyShape {
private:
	int x1_, y1_, x2_, y2_;
	int getWidth() {
		return x2_ - x1_;
	}

	int getHeight() {
		return y2_ - y1_;
	}
public:   
	MyRectangle(int x1, int y1, int x2, int y2, Screen* screen) {
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
		setScreen(*screen);
		setColor(255, 255, 255);
		setType("myrectangle");

	}

	MyRectangle() {
		x1_ = y1_ = 10;
		x2_ = y2_ = 100;
		
		setColor(255, 255, 255);
		setType("myrectangle");
	}

	void setCoordinations(int x1, int y1, int x2, int y2) {
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
	}

	void Draw() {
		showShape();
		cout << x1_ << " " << y1_ << " " <<
			this->getWidth() << " " <<
			this->getHeight() << endl;
		//cout << getR() << " " << getG() << " " << getB() << endl;
	}
	
};



class MyCircle :public MyShape {
private:
	int x_, y_, r_;

public:
	MyCircle();
	MyCircle(int x, int y, int r, Screen* screen);
	//MyCircle(const MyCircle &);   

	void setCenter(int x, int y) {
		x_ = x;
		y_ = y;
	}
	void setRadius(int r) {
		r_ = r;
	}
	void Draw() {
		showShape();
		cout << x_ << " " << y_ << " " << r_ << endl;
		//cout << getR() << " " << getG() << " " << getB() << endl;
	}

	
};
MyCircle::MyCircle() {
	x_ = 200;
	y_ = 200;
	r_ = 100;
	setType("mycircle");
	setColor(255, 255, 255);

}
MyCircle::MyCircle(int x, int y, int r, Screen* screen) {
	x_ = x;
	y_ = y;
	r_ = r;
	setScreen(*screen);
	setType("mycircle");
	setColor(255, 255, 255);
}
//MyCircle::MyCircle(const MyCircle &mycircle) {
//	x_ = mycircle.x_;
//	y_ = mycircle.y_;
//	r_ = mycircle.r_;
//	R = mycircle.R;
//	G = mycircle.G;
//	B = mycircle.B;
//	screen_ = mycircle.screen_;
//	cout << "copy mycircle" << endl;
//}


//-----------------------------------------------------------------------------

template <typename T>
struct Helper
{
	typedef char SmallType;
	typedef int LargeType;

	template <typename U>
	static char Test(U(*)[1]);
	template <typename U>
	static int Test(...);

	const static bool Result = sizeof(Test<T>(NULL)) == sizeof(LargeType);
};

int main() {
	int width, height;
	cin >> width >> height;

	Screen *screen = Screen::getInstance(width, height);

	if (!Helper<MyShape>::Result) cout << endl;
	MyShape *s1, *s2;

	s1 = new MyRectangle();
	s1->setScreen(*screen);
	s1->setColor(0, 0, 0xff);

	s2 = new MyCircle(100, 110, 50, screen);

	s1->Draw();
	s2->Draw();

	delete s1, s2;
	screen->deleteInstance();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}