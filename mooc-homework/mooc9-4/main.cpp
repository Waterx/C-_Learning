#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <stdexcept>
using namespace std;
class MyComplex {
private:
	double real;
	double image;
public:
	MyComplex(double real = 0, double image = 0) {
		this->real = real;
		this->image = image;
	}

	friend ostream &operator<<(ostream &stream, const MyComplex &complex);
	friend istream &operator >> (istream &stream, MyComplex &complex);
	MyComplex operator+(const MyComplex &complex);
	MyComplex operator-(const MyComplex &complex);
	MyComplex operator*(const MyComplex &complex);
	MyComplex operator/(const MyComplex &complex);
	double getReal() const {  //!!!
		return this->real;
	}
	double getImage() const {
		return this->image;
	}
};

class DivisionException : public runtime_error {
private:
	MyComplex divident;//被除数
	MyComplex divisor;//除数
public:
	DivisionException(string message, MyComplex divident, MyComplex divisor) :
		runtime_error(message) {
		this->divident = divident;
		this->divisor = divisor;
	}
	MyComplex getDivident() {
		return divident;
	}
	MyComplex getDivisor() {
		return divisor;
	}
};

ostream &operator<<(ostream &stream, const MyComplex &complex) {
	stream << "(";
	stream.unsetf(std::ios::showpos); //实数之前不显示正负号
	stream << complex.real;
	stream.setf(std::ios::showpos); //虚数之前显示正负号
	stream << complex.image << "i" << ")";
	return stream;
}
istream &operator >> (istream &stream, MyComplex &complex) {
	stream >> complex.real >> complex.image;
	return stream;
}
MyComplex MyComplex::operator+(const MyComplex &complex) {//!!!
	double r = real + complex.getReal();
	double i = image + complex.getImage();
	return MyComplex(r, i);
}
MyComplex MyComplex::operator-(const MyComplex &complex) {
	double r = real - complex.getReal();
	double i = image - complex.getImage();
	return MyComplex(r, i);
}
MyComplex MyComplex::operator*(const MyComplex &complex) {
	double r = real * complex.getReal() - image * complex.getImage();
	double i = real * complex.getImage() + image * complex.getReal();
	return MyComplex(r, i);
}
MyComplex MyComplex::operator/(const MyComplex &complex) {
	try {
		if (complex.getReal() == 0 && complex.getImage() == 0) {
			throw DivisionException ("Divisor is 0", *this, complex);
		}
		double r = (real*complex.getReal() + image*complex.getImage()) /
			(complex.getReal()*complex.getReal() + complex.getImage()*complex.getImage());
		double i = (image*complex.getReal() - real*complex.getImage()) /
			(complex.getReal()*complex.getReal() + complex.getImage()*complex.getImage());
		return MyComplex(r, i);
	}
	catch (int) {
	}
}

int main() {
	MyComplex z1, z2;
	cin >> z1;
	cin >> z2;
	try {
		cout << "z1 + z2 = " << z1 + z2 << endl;
		cout << "z1 - z2 + z1 = " << z1 - z2 + z1 << endl;
		cout << "z1 * z2 - z1 = " << z1 * z2 - z1 << endl;
		cout << "z1 / z2 + z1 = " << z1 / z2 + z1 << endl;
		cout << "z2 - z1 / z1 = " << z2 - z1 / z1 << endl;
		cout << "Finished";
	}
	catch (DivisionException& e) {
		cout << e.what() << ": " << e.getDivident() << "/" << e.getDivisor() << endl;
		cout << "Unexpected Error";
	}

	// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif
	return 0;
}
