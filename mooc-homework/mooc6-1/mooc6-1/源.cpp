
//mooc6-1

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
private:
	Screen(int newWidth, int newHeight);
	int width;
	int height;
	int exitWhenInvalidScreen(int width, int height);
	string enter;
	string leave;
	static Screen* instance;
};

Screen* Screen::instance = 0;
Screen::Screen(int newWidth, int newHeight) {
	if (Screen::instance == 0) {
		width = newWidth;
		height = newHeight;
		enter = "enter screen";
		leave = "leave screen";
		cout << enter << endl;
		exitWhenInvalidScreen(width, height);
		Screen::instance++;
	}
}
Screen::~Screen() {
	cout << leave << endl;
	Screen::instance--;       
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
	void Draw();
};
void MyShape::Draw() {
	cout << "[" << screen_->getWidth() << "X" << screen_->getHeight() << "]"
		<< type_ << "(" << R_ << "," << G_ << "," << B_ << ")" << endl;
}

//class MyRectangle {
//private:
//	int x1_, y1_, x2_, y2_;
//	
//	int R, G, B;
//	int getWidth() {
//		return x2_ - x1_;
//	}
//
//	int getHeight() {
//		return y2_ - y1_;
//	}
//public:
//	MyRectangle(int x1, int y1, int x2, int y2, Screen* screen) {
//		x1_ = x1;
//		y1_ = y1;
//		x2_ = x2;
//		y2_ = y2;
//		screen_ = screen;
//		R = G = B = 255;
//		cout << "myrectangle" << endl;
//	}
//
//	MyRectangle() {
//		x1_ = y1_ = 10;
//		x2_ = y2_ = 100;
//		screen_ = 0;
//		R = G = B = 255;
//		cout << "myrectangle" << endl;
//	}
//	void showScreen();
//	void setCoordinations(int x1, int y1, int x2, int y2) {
//		x1_ = x1;
//		y1_ = y1;
//		x2_ = x2;
//		y2_ = y2;
//	}
//
//	
//
//	void Draw() {
//		cout << x1_ << " " << y1_ << " " <<
//			this->getWidth() << " " <<
//			this->getHeight() << endl;
//		cout << R << " " << G << " " << B << endl;
//	}
//	void setColor(int R, int G, int B);
//};
//void MyRectangle::setColor(int R, int G, int B) {
//	this->R = R;
//	this->G = G;
//	this->B = B;
//}
//void MyRectangle::showScreen() {
//	cout << screen_->getWidth() << " " << screen_->getHeight() << endl;
//}
//
//class MyCircle {
//private:
//	int x_, y_, r_;
//	int R, G, B;
//	
//
//public:
//	MyCircle();
//	MyCircle(int x, int y, int r, Screen* screen);
//	MyCircle(const MyCircle &);   //vs里加不加const都可以运行，dev中不加const会error，why？
//	void setColor(int R, int G, int B);
//	void setCenter(int x, int y) {
//		x_ = x;
//		y_ = y;
//	}
//	void setRadius(int r) {
//		r_ = r;
//	}
//	void Draw() {
//		cout << x_ << " " << y_ << " " << r_ << endl;
//		cout << R << " " << G << " " << B << endl;
//	}
//	void showScreen() {
//		cout << screen_->getWidth() << " " << screen_->getHeight() << endl;
//	}
//	
//};
//MyCircle::MyCircle() {
//	x_ = 200;
//	y_ = 200;
//	r_ = 100;
//	R = G = B = 255;
//	cout << "mycircle" << endl;
//}
//MyCircle::MyCircle(int x, int y, int r, Screen* screen) {
//	x_ = x;
//	y_ = y;
//	r_ = r;
//	screen_ = screen;
//	R = G = B = 255;
//	cout << "mycircle" << endl;
//}
//MyCircle::MyCircle(const MyCircle &mycircle) {
//	x_ = mycircle.x_;
//	y_ = mycircle.y_;
//	r_ = mycircle.r_;
//	R = mycircle.R;
//	G = mycircle.G;
//	B = mycircle.B;
//	screen_ = mycircle.screen_;
//	cout << "copy mycircle" << endl;
//
//}
//void MyCircle::setColor(int R, int G, int B) {
//	this->R = R;
//	this->G = G;
//	this->B = B;
//}

//-----------------------------------------------------------------------------
int main() {
	int width, height;
	cin >> width >> height;

	Screen *screen = Screen::getInstance(width, height);

	MyShape shape1(screen);
	MyShape* shape2 = new MyShape();
	shape2->setScreen(*screen);
	shape2->setColor(0, 0, 0xff);

	shape1.Draw();
	shape2->Draw();

	delete shape2;
	screen->deleteInstance();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}