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
	return rear->data;
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
	return 1;
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
	Node* beforerear;
	int num = numOfNode;
	if (numOfNode > 1) {
		for (int i = 0; i < num - 2; i++) {
			t = t->next;
		}
		beforerear = t;
		t = t->next;
		numOfNode--;        //×öµ½Õâ
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

int main() {
	Stack s;
	s.Add(4);
	s.Add(6);
	s.Add(9);
	//s.Remove();
	//s.Remove();

	//s.Remove();
	s.MakeEmpty();
	return 0;
}