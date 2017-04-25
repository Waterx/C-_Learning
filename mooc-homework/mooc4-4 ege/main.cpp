#include"graphics.h"
#include<cstdlib>
using namespace std;
class Screen;
class MyRectangle;

class Screen {
public:
	Screen();
	Screen(int newWidth,int newHeight);
	~Screen(){
		closegraph();
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	int setWidth(int width)   //return width
	{
		this->width = width;
		return width;
	}
	int setHeight(int height) //return height
	{
		this->height = height;
		return height;
	}
private:
	int width;
	int height;
	int exitWhenInvalidScreen(int width, int height);
};
Screen::Screen() {
	width = 640;
	height = 480;
	initgraph(width,height);
	outtextxy(10,10,"screen");
}
Screen::Screen(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
	exitWhenInvalidScreen(width, height);
	initgraph(width,height);
	outtextxy(10,10,"screen");
}
int Screen::exitWhenInvalidScreen(int width, int height) {
	if (width > 0 && height > 0 && width <= 1000 && height <= 1000)
	{
		return 1;
	}
	else
	{
		outtextxy(10,10,"invalid screen size");
		exit(0);
	}
}
//---------------------------------------------------------------------------------------------
class MyRectangle {
public:
	MyRectangle();
	MyRectangle(int x1, int y1, int x2, int y2, Screen* screen);
	void setCoordinations(int nx1, int ny1, int nx2, int ny2);    
	int setScreen(Screen& screen);
	void Draw();
private:
	Screen* screen_;
	int x1, y1, x2, y2;
};
MyRectangle::MyRectangle() {
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	outtextxy(10,30,"myrectangle");
}
MyRectangle::MyRectangle(int x1, int y1, int x2, int y2, Screen* screen) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	screen_ = screen;
	outtextxy(10,30,"myrectangle");
}
void MyRectangle::setCoordinations(int nx1, int ny1, int nx2, int ny2) {
	x1 = nx1;
	x2 = nx2;
	y1 = ny1;
	y2 = ny2;
}
int MyRectangle::setScreen(Screen& screen) {
	screen_ = &screen;
	return 1;
}

void MyRectangle::Draw() {
	int rwidth = x2 - x1;
	int rheight = y2 - y1;;
	if (rwidth <= 0 || rheight <= 0||rwidth>=screen_->getWidth()||rheight>=screen_->getHeight()) {  
		outtextxy(10,50,"invalid myrectangle");
	}
	else if (x1 == 0 || y1 == 0 || x2 == screen_->getWidth() || y2 == screen_->getHeight()) {
		outtextxy(10,50,"invalid myrectangle");
	}
	else {
		rectangle(x1,y1,x2,y2);
		xyprintf(10,50,"%d,%d,%d,%d",x1,y1,rwidth,rheight);
	}
}

//--------------------------------------------------------------------------------------
int main() {
	int width = 640, height = 480;
	initgraph(width,height);
	width = getInteger("Screen width");
	height = getInteger("Screen height");
	Screen  screen(width,height);

	int leftX, leftY, rightX, rightY;
	leftX = getInteger("leftX");
	leftY = getInteger("leftY");
	rightX = getInteger("rightX");
	rightY = getInteger("rightY");
	MyRectangle myRectangle1(leftX, leftY, rightX, rightY, &screen);
	
	myRectangle1.Draw();
	
	ege::getch();
	return 0;
}
