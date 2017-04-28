
//mooc6-3

#include"graphics.h"
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



private:
	Screen(int newWidth, int newHeight);
	int width;
	int height;
	int exitWhenInvalidScreen(int width, int height);
	const char* enter;
	const char* leave;
	static Screen* instance;
};

Screen* Screen::instance = 0;
Screen::Screen(int newWidth, int newHeight) {
	if (Screen::instance == 0) {
		width = newWidth;
		height = newHeight;
		initgraph(width,height);
		enter = "enter screen";
		leave = "leave screen";
		xyprintf(10, 10, "%s", enter);
		exitWhenInvalidScreen(width, height);
		Screen::instance++;
	}
}
Screen::~Screen() {
	xyprintf(10, 10, "leave");
	Screen::instance--;       
}
int Screen::exitWhenInvalidScreen(int width, int height) {
	if (width > 0 && height > 0 && width <= 1000 && height <= 1000)
	{
		return 1;
	}
	else
	{
		xyprintf(10, 10, "invalid screen size");
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

class MyShape {
private:
	int R_, G_, B_;
	Screen* screen_;
	const char* type_;
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
	void setType(const char* string) {
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
	//cout << "[" << screen_->getWidth() << "X" << screen_->getHeight() << "]"
	//	<< type_ << "(" << R_ << "," << G_ << "," << B_ << ")" << endl;
	xyprintf(10, 10, "[%dX%d]%s(%d,%d,%d)", screen_->getWidth(), screen_->getHeight(), type_, R_, G_, B_);
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
		//cout << x1_ << " " << y1_ << " " <<
		//	this->getWidth() << " " <<
		//	this->getHeight() << endl;
		xyprintf(10, 10, "%d %d %d %d", x1_, y1_, this->getWidth(), this->getHeight());		
		setfillcolor(EGERGB(getR(), getG(), getB()));
		bar(x1_, y1_, x2_, y2_);		//用bar的原因是ege库里的rectangle()不能填充颜色，bar可以 

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
		//cout << x_ << " " << y_ << " " << r_ << endl;
		xyprintf(10, 10, "%d %d %d", x_, y_, r_);
		setcolor(EGERGB(getR(), getG(), getB()));
		setfillcolor(EGERGB(getR(), getG(), getB()));
		fillellipse(x_, y_, r_, r_);		//不用circle()的原因同rectangle()	 

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
	initgraph(640, 480);
	width = getInteger("Screen width");
	height = getInteger("Screen height");

	Screen *screen = Screen::getInstance(width, height);

	//if (!Helper<MyShape>::Result) cout << endl;
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
	ege::getch();
	return 0;
}
