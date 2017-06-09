//集中上机
#include<iostream>
#include<fstream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
};

class Bag {
public:
	virtual int Add(int data) = 0;
	virtual int Remove() = 0;
	virtual int Get() = 0;
	virtual int Put(int data) = 0;
	virtual int MakeEmpty() = 0;
	virtual int Full() = 0;
	virtual int Length() = 0;
};

class Stack :public Bag {
private:
	int numOfNode;
	Node* head;
	Node* rear;
public:
	int Add(int data);
	int Remove();
	int Get();
	int Put(int data);
	int MakeEmpty();
	int Full();
	int Length();
	void Read();
	int Write();
	int WrToFile();
	int ReadfrFile();
	void Display();
};

int Stack::Add(int data) {
	if (!head) {
		head = new Node(data, 0);
		rear = head;
		numOfNode++;
		return 1;
	}
	else {
		Node* t = new Node(data, rear);
		rear = t;
		numOfNode++;
		return 1;
	}
}
int Stack::Remove() {
	Node* t = rear;
	if (numOfNode > 1) {
		rear = rear->next;
		delete t;
		numOfNode--;
		return 1;
	}
	else if (numOfNode == 1) {
		delete head;
		head = 0;
		rear = 0;
		numOfNode--;
		return 1;
	}
	else {
		return 0;
	}

}
int Stack::Get() {
	if (rear) {
		return rear->data;
	}
	else
		return -1;
}
int Stack::Put(int data) {
	Node* t = new Node(data, rear);
	rear = t;
	numOfNode++;
	return 1;
}
int Stack::MakeEmpty() {
	int num = numOfNode;
	for (int i = 0; i <= num; i++) {
		Remove();
	}
	return 1;
}
int Stack::Full() {
	return head==0;
}
int Stack::Length() {
	return numOfNode;
}
void Stack::Read() {
	Node* t = rear;
	for (int i = 0; i < numOfNode; i++) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}
int Stack::Write() {
	cout << "Stack input numbers:";
	do {
		int t;
		cin >> t;
		Add(t);
	} while (getchar() != '\n');
	return 1;
}
int Stack::WrToFile() {
	ofstream output("stack.txt");
	if (head) {
		Stack s;
		Node* t = rear;
		for (int i = 0; i < numOfNode; i++) {
			s.Add(t->data);
			t = t->next;
		}
		t = s.rear;
		for (int i = 0; i < numOfNode; i++) {
			output << t->data << " ";
			t = t->next;
		}
		return 1;
	}
	output.close();
	return 0;
}
int Stack::ReadfrFile() {
	ifstream input("stack.txt");
	if (input.fail()) {
		return -1;
	}
	MakeEmpty();
	/*while (!input.eof()) {
		int t;
		input >> t;
		Add(t);
	}*/
	while (true) {
		int x;
		input >> x;
		if (input.eof()) break;
		Add(x);
	}
	input.close();
	return 1;

}
void Stack::Display() {
	cout << "--STACK--" << endl;
	cout << "Elements:";
	Read();
	cout << "Top:" << Get() << endl;
	cout << "Length:" << Length() << endl;
	cout << "IsEmpty:" << Full() << endl;
	cout << endl;
}
class Queue :public Bag {
private:
	int numOfNode;
	Node* head;
	Node* rear;
public:
	int Add(int data);
	int Remove();
	int Get();
	int Put(int data);
	int MakeEmpty();
	int Full();
	int Length();
	void Read();
	int Write();
	int WrToFile();
	int ReadfrFile();
	void Display();
};

int Queue::Add(int data) {
	if (!head) {
		head = new Node(data, 0);
		rear = head;
		numOfNode++;
		return 1;
	}
	else {
		Node* t = new Node(data, 0);
		rear->next = t;
		rear = t;
		numOfNode++;
		return 1;
	}
}

int Queue::Remove() {
	Node* t = head;
	if (numOfNode > 1) {
		head = head->next;
		delete t;
		numOfNode--;        
		return 1;
	}
	else if (numOfNode == 1) {
		delete head;
		head = 0;
		rear = 0;  
		numOfNode--;
		return 1;
	}
	else {
		return 0;
	}

}
int Queue::Get() {
	if (head) {
		return head->data;
	}
	else {
		return -1;
	}
}
int Queue::Put(int data) {
	Node* t = new Node(data, 0);
	rear->next = t;
	rear = t;
	numOfNode++;
	return 1;
}
int Queue::MakeEmpty() {
	int num = numOfNode;
	for (int i = 0; i < num; i++) {
		Remove();
	}
	return 1;
}
int Queue::Full() {
	return head == 0;
}
int Queue::Length() {
	return numOfNode;
}
void Queue::Read() {
	Node* t = head;
	for (int i = 0; i < numOfNode; i++) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}
int Queue::Write() {
	cout << "Queue input numbers:";
	do {
		int t;
		cin >> t;
		Add(t);
	} while (getchar() != '\n');
	return 1;
}
int Queue::WrToFile() {
	ofstream output("queue.txt");
	if (head) {
		Node *t = head;
		for (int i = 0; i < numOfNode; i++) {
			output << t->data << " ";
			t = t->next;
		}
		output.close();
		return 1;
	}
	return 0;
}
int Queue::ReadfrFile() {
	ifstream input("queue.txt");
	if (input.fail()) {
		return -1;
	}
	MakeEmpty();
	while (true) {
		int x;
		input >> x;
		if (input.eof()) break;
		Add(x);
	}
	input.close();
	return 1;
}
void Queue::Display() {
	cout << "--QUEUE--" << endl;
	cout << "Elements:";
	Read();
	cout << "Head:" << head->data << endl;
	cout << "Rear:" << rear->data << endl;
	cout << "Length:" << Length() << endl;
	cout << "IsEmpty:" << Full() << endl;
	cout << endl;
}

int main() {

	Stack s;
	s.Write();
	s.Display();
	s.WrToFile();
	s.ReadfrFile();
	s.Display();

	Queue q;
	q.Write();
	q.Display();
	q.WrToFile();
	q.ReadfrFile();
	q.Display();
	//Stack s;
	//Queue q;
	//s.ReadfrFile();
	//s.Display();
	//q.ReadfrFile();
	//q.Display();
	return 0;
}