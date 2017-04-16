
//mooc5-3

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Screen;
class MyRectangle;

class Screen {
public:
	~Screen();
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	static Screen* getInstance(int width = 640, int height = 480); //注意是静态！！题目要求！！这导致主函数中非静态成员引用必须与特定对象相对的问题！
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
	Screen::objNum--;       //析构函数里要记得减计数器！！
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

class MyRectangle {
private:
	int x1_, y1_, x2_, y2_;
	Screen* screen_;
	int R, G, B;
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
		screen_ = screen;
		R = G = B = 255;
		cout << "myrectangle" << endl;
	}

	MyRectangle() {
		x1_ = y1_ = 10;
		x2_ = y2_ = 100;
		screen_ = 0;
		R = G = B = 255;
		cout << "myrectangle" << endl;
	}

	void setCoordinations(int x1, int y1, int x2, int y2) {
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
	}

	void setScreen(Screen& screen) {
		screen_ = &screen;
	}

	void Draw() {
		cout << x1_ << " " << y1_ << " " <<
			this->getWidth() << " " <<
			this->getHeight() << endl;
		cout << R << " " << G << " " << B << endl;
	}
	void setColor(int R, int G, int B);
};
void MyRectangle::setColor(int R, int G, int B) {
	this->R = R;
	this->G = G;
	this->B = B;
}
//-----------------------------------------------------------------------------
int main() {
	int width, height;
	int leftX, leftY, rightX, rightY;
	Screen *screen;

	cin >> width >> height;
	cin >> leftX >> leftY >> rightX >> rightY;

	screen = Screen::getInstance(width, height);
	MyRectangle myRectangle(leftX, leftY, rightX, rightY, screen);
	myRectangle.setColor(0, 0, 0xff);
	myRectangle.Draw();

	screen->deleteInstance();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}