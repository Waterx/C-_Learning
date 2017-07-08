#include <iostream>
#include <limits>
#include <string>
#include <fstream>

using namespace std;

class Screen {
private:
	static int width_;
	static int height_;
	static Screen* instance;
	// 在Screen类中获取/释放图形窗口资源，是一种RAII方法
	//   关于RAII，可以参见异常处理单元的材料
	Screen() {

		// 如果启用了图形库，则将初始化图形模式的函数置于此处
		// initgraph(width_, height_);
	};
	~Screen() {
		// 如果启用了图形库，则将关闭图形模式的函数置于此处
		// closegraph();
		delete instance;
	}

public:
	unsigned int getWidth() {
		return width_;
	}
	unsigned int getHeight() {
		return height_;
	}
	static Screen* getInstance(unsigned int width = 640, unsigned int height = 480) {
		if (instance == 0) {
			width_ = width;
			height_ = height;
			instance = new Screen();
		}
		return instance;

	}
};

Screen* Screen::instance = 0;
int Screen::height_ = 0;
int Screen::width_ = 0;

int main() {
	int width, height;
	Screen* screen = 0;
	
	//-------------------------------------------------------
	//The following content is the 7-2 test answer
	string file_name = "screen.txt";
	fstream fs;
	fs.open(file_name, ios::in | ios::out | ios::binary);
	if (fs.fail()) {
		cout << "Can not open file in in&out mode: " << file_name << endl;
		fs.open(file_name, ios::out | ios::binary);
		fs.close();
		fs.open(file_name, ios::in | ios::out | ios::binary);
	}
	fs << width << height;
	if (!width || !height) {
		cin >> width >> height;
		fs.clear();
	}
	
	screen = Screen::getInstance(width, height);
	screen = Screen::getInstance();
	//fs.seekp(ios::beg);
	fs >> screen->getWidth() >> " " >> screen->getWidth();
	if (fs.fail()) {
		cout << "Writing to file failed" << endl;
		return -1;
	}
	fs.seekp(ios::beg);
	//fs <<

	

	cout << screen->getWidth() << " " <<
		screen->getHeight() << endl;

		// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif

	return 0;
}
