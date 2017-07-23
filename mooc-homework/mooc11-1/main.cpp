#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> intVector;
	int t;
	while (cin >> t) {
		intVector.push_back(t);
	}
	sort(intVector.begin(), intVector.end());
	vector<int>::iterator p;

	for (p = intVector.begin(); p != intVector.end(); p++)
	{
		cout << *p << endl;
	}
	return 0;
}