#include <iostream> 
#include <vector>
#include <limits>
using namespace std;
template<typename T>
class Array {
private:
	T* data_;  //存放数组中所有元素的内存的首地址
	int size_;  //数组中元素的数量
public:
	Array(vector<T> v);
	~Array();           // 析构函数，释放已经申请到的内存
	void sort();        // 排序，将数组中所有元素由小到大排序
	int seek(T key);    // 查找指定的元素key，返回其所在位置（位置编号从0开始）; 如果没有找到，则返回 -1
	void display();
};

template<typename T>
Array<T>::Array(vector<T> v) {
	size_ = v.size();
	data_ = static_cast<T*> (new T[size_]);
	for (int i = 0; i < size_; i++) {
		data_[i] = v[i];
	}
}
template<typename T>
void Array<T>::display() {
	int i;
	for (i = 0; i < size_; i++) {
		cout << data_[i];
		if (i != size_ - 1)
			cout << " ";  // 输出一个空格
	}
}
template<typename T>
Array<T>::~Array() {
	delete []data_;
}
template<typename T>
void Array<T>::sort() {
	int min;
	int temp;
	int i, j;
	T t;
	for (i = 0; i<size_ - 1; i++)
	{
		temp = i;
		for (j = i + 1; j < size_; j++)
		{
			if (data_[temp]>data_[j])
				temp = j;
		}
		if (i != temp)
		{
			t = data_[temp];
			data_[temp] = data_[i];
			data_[i] = t;
		}
	}
}
template<typename T>
int Array<T>::seek(T key) {
	int flag = 0;
	int i;
	for (i = 0; i < size_; i++) {
		if (key == data_[i]) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return i;
	}
	else {
		return -1;
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
