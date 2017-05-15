
//book_9-6

#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>(int data, Node<T>* next) {
		this->data = data;
		this->next = next;
	}
};

template<typename T>
class Linklist {
public:
	int size ;
	Node<T>* front = 0, *rear = 0;
	Node<T>* Insert(int data, int position);
	void Linkprint();
	T Get(int position);
};
//template<typename T>
//int Linklist<T>::size = 0; //要在类外定义静态变量，不然会引起LNK2001error
template<typename T>
Node<T>* Linklist<T>::Insert(int data, int position) {
	if (front == 0 && rear == 0) {  //if a empty list
		Node<T>* node = new Node<T>(data, 0);
		front = node;
		rear = node;
		size++;
		return rear;
	}
	else if (position == size + 1) { //insert to rear of list
		Node<T>* node = new Node<T>(data, 0);
		rear->next = node;
		rear = node;
		size++;
		return rear;
	}
	else if (position == 1) {  //insert to head of list
		Node<T>* node = new Node<T>(data, front);
		front = node;
		size++;
		return rear;
	}
	else if (position > 0 && position < size + 1) { //insert to middle part
		Node<T>* t = front;
		for (int i = 0; i < position - 2; i++) {
			t = t->next;
		}
		Node<T>* node = new Node<T>(data, t->next);
		t->next = node;
		size++;
		return rear;
	}
	else {
		return 0;
	}
}

template<typename T>
void Linklist<T>::Linkprint() {
	Node<T>* t = front;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << t->data << endl;
		if (t->next != 0)
		{
			t = t->next;
		}
	}
	cout << endl;
}

template<typename T>
T Linklist<T>::Get(int position) {
	Node<T>* t = front;
	for (int i = 0; i < position - 1; i++) {
		t = t->next;
	}
	return t->data;
}
template<typename T>
class OrderList : public Linklist<T> {
public:
	Node<T>* insert(int data);
	Linklist<T> link;

};
template<typename T>
Node<T>* OrderList<T>::insert(int data) {

	if (Linklist<T>::front->data > data) {
		Node<T>* t = Linklist<T>::front;
		Node<T>* node = new Node<T>(data, t);
		Linklist<T>::front = node;
		Linklist<T>::size++;
		return Linklist<T>::rear;
	}
	else if (Linklist<T>::rear->data < data) {
		Node<T>* t = new Node<T>(data, 0);
		Linklist<T>::rear->next = t;
		Linklist<T>::rear = t;
		Linklist<T>::size++;
		return Linklist<T>::rear;
	}
	else {
		Node<T>* t = Linklist<T>::front;
		for (int i = 0; data > t->data; i++) {
			if (data <= t->next->data) {
				break;
			}
			t = t->next;
		}
		Node<T>* node = new Node<T>(data, t->next);
		t->next = node;
		Linklist<T>::size++;
		return Linklist<T>::rear;
	}
}
int main() {

	OrderList<int> a;
	
	a.Insert(20, 0);
	a.insert(50);
	a.insert(12);
	a.insert(15);
	a.insert(30);
	a.Linkprint();

	OrderList<int> b;
	b.Insert(31, 0);
	b.insert(89);
	b.insert(93);
	b.insert(14);
	b.insert(59);
	b.Linkprint();

	for (int i = 0; i < 5; i++) {
		a.insert(b.Get(i+1));
	}

	a.Linkprint();
	return 0;
}