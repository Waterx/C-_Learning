//Stack.h
#ifndef STACK_H
#define STACK_H
#include<cassert>

template<typename T, int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;   //ջ��λ�ã������±꣩
public:
	Stack();
	void push(const T &item);
	T pop();
	void clear();
	const T &peek() const;
	bool isEmpty() const;
	bool isFull() const;
};

template<typename T, int SIZE>//���캯����ջ����ʼ��Ϊ-1
Stack<T, SIZE>::Stack() :top(-1) {
	//top = 1;
}
template<typename T, int SIZE>//��Ԫ��ѹ��ջ�����ջ�����򱨴�(assert()����)
void Stack<T, SIZE>::push(const T &item) {
	assert(!isFull());
	
	list[++top] = item;
}
template<typename T, int SIZE>//��ջ��Ԫ�ص���ջ�����ջΪ���򱨴�
T Stack<T, SIZE>::pop() {
	assert(!isEmpty());
	return list[top--];
}
template<typename T, int SIZE>//����ջ��Ԫ�أ����ջΪ���򱨴�
const T &Stack<T, SIZE>::peek() const {
	assert(!isEmpty());
	return list[top];
}
template<typename T, int SIZE>//����ջ�Ƿ�Ϊ��
bool Stack<T, SIZE>::isEmpty() const {
	return top == -1;
}
template<typename T, int SIZE>//�����Ƿ���ջ
bool Stack<T, SIZE>::isFull() const {
	return top == SIZE - 1;
}
template<typename T, int SIZE>//���ջ
void Stack<T, SIZE>::clear() {
	top = -1;
}

#endif // !STACK_H
