#include<iostream>
#include<list>
#include<deque>
#include<algorithm>
#include<string>
#include<sstream>
#include<iterator>
using namespace std;

bool isOdd(int n) {
	return n % 2 != 0;
}
int main() {
	deque<int> dq;
	list<int> list1;
	list<int> list2;
	/*string sentence = "And I feel fine...";
	istringstream iss(sentence);
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		ostream_iterator<string>(cout, "\n"));*/
	
	int t;
	while (cin.get() != '\n') {
		cin.unget();
		cin >> t;
		if (isOdd(t)) {
			dq.push_front(t);
		}
		else {
			dq.push_back(t);
		}
	}
	deque<int>::reverse_iterator dqp = dq.rbegin();//
	
	for (; dqp != dq.rend(); dqp++) {
		list1.push_back(*dqp);
	}
	deque<int>::iterator dqp2 = dq.begin();
	list<int>::iterator lp1 = list1.begin();
	list<int>::iterator lp2 = list2.begin();
	for (; dqp2 != dq.end(); dqp2++) {
		lp1++;
		int sum = *lp1 + *dqp2;
		list2.push_back(sum);
		cout << sum << " ";
	}

	return 0;
}