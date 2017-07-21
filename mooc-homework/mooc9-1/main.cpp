#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
using namespace std;
class MyComplex {
private:
	double real;
	double image;
public:
	MyComplex() {
		this->real = real;
		this->image = image;
	}
	friend ostream &operator<<(ostream &stream, const MyComplex &complex);
	friend istream &operator>>(istream &stream, MyComplex &complex);
};
ostream &operator<<(ostream &stream, const MyComplex &complex) {
	stream << "(";
	stream.unsetf(std::ios::showpos); //ʵ��֮ǰ����ʾ������
	stream << complex.real;
	stream.setf(std::ios::showpos); //����֮ǰ��ʾ������
	stream << complex.image << "i" << ")" ;
	return stream;
}
istream &operator>>(istream &stream, MyComplex &complex) {
	stream >> complex.real >> complex.image;
	return stream;
}
int main() {
	MyComplex z1, z2;
	cin >> z1;
	cin >> z2;
	cout << z1 << " " << z2 << endl;  //z1��z2֮����1���ո�
									  // GCC��VC�������ڵ���ģʽ�»���ͣ�����ڲ鿴���н��
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif
	return 0;
}