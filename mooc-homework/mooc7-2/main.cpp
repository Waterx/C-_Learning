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
	// ��Screen���л�ȡ/�ͷ�ͼ�δ�����Դ����һ��RAII����
	//   ����RAII�����Բμ��쳣����Ԫ�Ĳ���
	Screen() {

		// ���������ͼ�ο⣬�򽫳�ʼ��ͼ��ģʽ�ĺ������ڴ˴�
		// initgraph(width_, height_);
	};
	~Screen() {
		// ���������ͼ�ο⣬�򽫹ر�ͼ��ģʽ�ĺ������ڴ˴�
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

		// GCC��VC�������ڵ���ģʽ�»���ͣ�����ڲ鿴���н��
#if ( defined(__DEBUG__) || defined(_DEBUG) )
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif

	return 0;
}
