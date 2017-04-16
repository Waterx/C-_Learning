
//mooc5-1

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Screen;

class Screen {
public:
	Screen(int newWidth, int newHeight);
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
	static Screen* getInstance(int width = 640, int height = 480); //注意是静态！！题目要求！！这导致主函数中非静态成员引用必须与特定对象相对的问题！
	static int isSimpleObj(int objNum);
private:
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
Screen::Screen(int newWidth, int newHeight){
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
int Screen::isSimpleObj(int objNum) {
	if (objNum == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
//-----------------------------------------------------------------------------
int main() {
	int width, height;
	Screen *screen1, *screen2;

	std::cin >> width >> height;

	screen1 = Screen::getInstance(width, height);  //想class::函数()这样使用的话要保证函数是静态函数;
	screen2 = Screen::getInstance();

	std::cout << screen1->getWidth() << ' ' << screen1->getHeight() << std::endl;
	std::cout << screen2->getWidth() << ' ' << screen2->getHeight();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}