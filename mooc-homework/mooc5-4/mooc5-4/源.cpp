
//mooc5-4

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Screen;
class MyRectangle;
class MyCircle;

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
	void showScreen();
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
void MyRectangle::showScreen() {
	cout << screen_->getWidth() << " " << screen_->getHeight() << endl;
}

class MyCircle {
private:
	int x_, y_, r_;
	int R, G, B;
	Screen* screen_;
	
public:
	MyCircle();
	MyCircle(int x, int y, int r, Screen* screen);
	MyCircle(const MyCircle &);   //vs��Ӳ���const���������У�dev�в���const��error��why���𰸼��ʼǱ����嵥Ԫ
	void setColor(int R, int G, int B);
	void setCenter(int x, int y) {
		x_ = x;
		y_ = y;
	}
	void setRadius(int r) {
		r_ = r;
	}
	void Draw() {
		cout << x_ << " " << y_ << " " << r_ << endl;
		cout << R << " " << G << " " << B << endl;
	}
	void showScreen() {
		cout << screen_->getWidth() << " " << screen_->getHeight() << endl;
	}
	void setScreen(Screen& screen) {
		screen_ = &screen;

	}
};
MyCircle::MyCircle() {
	x_ = 200;
	y_ = 200;
	r_ = 100;
	R = G = B = 255;
	cout << "mycircle" << endl;
}
MyCircle::MyCircle(int x, int y, int r, Screen* screen){
	x_ = x;
	y_ = y;
	r_ = r;
	screen_ = screen;
	R = G = B = 255;
	cout << "mycircle" << endl;
}
MyCircle::MyCircle(const MyCircle &mycircle) {
	x_ = mycircle.x_;
	y_ = mycircle.y_;
	r_ = mycircle.r_;
	R = mycircle.R;
	G = mycircle.G;
	B = mycircle.B;
	screen_ = mycircle.screen_;
	cout << "copy mycircle" << endl;

}
void MyCircle::setColor(int R, int G, int B) {
	this->R = R;
	this->G = G;
	this->B = B;
}
//-----------------------------------------------------------------------------
int main() {
	int width, height;
	cin >> width >> height;

	int leftX, leftY, rightX, rightY;
	cin >> leftX >> leftY >> rightX >> rightY;

	int centerX, centerY, radius;
	cin >> centerX >> centerY >> radius;

	Screen *screen = Screen::getInstance(width, height);

	MyRectangle myRectangle(leftX, leftY, rightX, rightY, screen);
	myRectangle.setColor(0, 0, 0xff);
	myRectangle.showScreen();
	myRectangle.Draw();

	// ����Բ�ζ�������
	//// ��һ��Ԫ��ʹ���������󣨵��ô��ι��캯������ʼ��
	//// �ڶ���Ԫ��ʹ���������󣨵���Ĭ�Ϲ��캯������ʼ�� 
	MyCircle myCircles[2] = { MyCircle(centerX, centerY, radius, screen) };

	// ���ö��������еڶ���Ԫ�ص����ԡ�ע����ʳ�Ա�����Ĳ�ͬ���� 
	(myCircles + 1)->setCenter(centerX + 10, centerY + 20);
	myCircles[1].setRadius(radius + 30);
	(*(myCircles + 1)).setColor(0x00, 0x00, 0x00);
	myCircles[1].setScreen(*screen);

	for (int i = 0; i <= 1; i++) {
		myCircles[i].showScreen();
		(myCircles + i)->Draw();
	}

	// ���ÿ������캯����myCircles�����еĵڶ���Ԫ��Ϊģ�崴���¶��� 
	MyCircle yourCircle(myCircles[1]);

	yourCircle.showScreen();
	(&yourCircle)->Draw();

	screen->deleteInstance();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}