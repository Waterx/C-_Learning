
//mooc5-2

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Screen;

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
	Screen::instance--;  //析构函数里要记得减数器
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
//-----------------------------------------------------------------------------
int main() {
	int width, height;
	Screen *screen1, *screen2;

	std::cin >> width >> height;

	screen1 = Screen::getInstance(width, height);
	screen2 = Screen::getInstance();
	if (screen1 != screen2) {
		std::cout << "two instances" << std::endl;
	}

	std::cout << screen2->getWidth() << ' ' << screen2->getHeight() << std::endl;
	screen2->deleteInstance();

	screen1 = Screen::getInstance(2 * width, 2 * height);
	std::cout << screen1->getWidth() << ' ' << screen1->getHeight() << std::endl;
	screen1->deleteInstance();

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}