#include <iostream> 
#include <vector>
#include <limits>
using namespace std;

template<typename T>
class Array
{
public:
	Array(vector<T> v);
	void sort()
	{
		T temp;
		for (int i = 1; i<size_; i++)
		{
			temp = data_[i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (temp<data_[j])
				{
					data_[j + 1] = data_[j];
				}
				else
					break;

			}
			data_[j + 1] = temp;
		}
	}
	int seek(T key)
	{
		for (int i = 0; i<size_; i++)
		{
			if (data_[i] == key)
				return i;
		}
		return -1;
	}
	void display() {
		int i;
		for (i = 0; i < size_; i++) {
			cout << data_[i];
			if (i != size_ - 1)
				cout << " ";  // 输出一个空格
		}
	}
	~Array()
	{
		delete data_;
	}

private:
	int size_;
	T* data_;
};

template<typename T>
Array<T>::Array(vector<T> v)
{
	size_ = v.size();
	data_ = static_cast<T*> (new T[size_]);
	for (int i = 0; i < size_; i++) {
		data_[i] = v[i];
	}
}


int main() {
	vector<int> vi;
	int ti;
	vector<double> vd;
	double td;
	vector<char> vc;
	char tc;

	while (cin.get() != '\n') {
		cin.unget();
		cin >> ti;
		vi.push_back(ti);
	}


	while (cin.get() != '\n') {
		cin.unget();
		cin >> td;
		vd.push_back(td);
	}


	while (cin >> tc) {
		vc.push_back(tc);
	}



	Array<int> ai(vi);
	Array<double> ad(vd);
	Array<char> ac(vc);

	cout << ai.seek(10) << endl;
	cout << ad.seek(10.0) << endl;
	cout << ac.seek('a') << endl;

	ai.sort();
	ad.sort();
	ac.sort();

	ai.display();
	cout << endl;
	ad.display();
	cout << endl;
	ac.display();

	// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif
	return 0;
}