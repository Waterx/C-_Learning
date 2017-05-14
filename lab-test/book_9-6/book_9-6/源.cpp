
//book_9-6

#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next);
};
template<typename T>
Node<T>::Node(T data, Node<T>* next) {
	this->data = data;
	this->next = next;
}

template<typename T>
class Linklist {
public:
	int size;
	int position;
	Node<T>* front; Node<T>* rear;
	Node<T>* InsertList(Node<T> node, int newposition);
};
template<typename T>
Node<T>* Linklist<T>::InsertList(Node<T> node, int newposition) {
	if()
}