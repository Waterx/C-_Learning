//Stack.h
#ifndef STACK_H
#define STACK_H
#include<cassert>

template<typename T, int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;   //栈顶位置（数组下标）
public:
	Stack();
	void push(const T &item);
	T pop();
	void clear();
	const T &peek() const;
	bool isEmpty() const;
	bool isFull() const;
};

template<typename T, int SIZE>//构造函数，栈顶初始化为-1
Stack<T, SIZE>::Stack() :top(-1) {
	//top = 1;
}
template<typename T, int SIZE>//把元素压入栈，如果栈满了则报错(assert()函数)
void Stack<T, SIZE>::push(const T &item) {
	assert(!isFull());
	
	list[++top] = item;
}
template<typename T, int SIZE>//将栈顶元素弹出栈，如果栈为空则报错
T Stack<T, SIZE>::pop() {
	assert(!isEmpty());
	return list[top--];
}
template<typename T, int SIZE>//访问栈顶元素，如果栈为空则报错
const T &Stack<T, SIZE>::peek() const {
	assert(!isEmpty());
	return list[top];
}
template<typename T, int SIZE>//测试栈是否为空
bool Stack<T, SIZE>::isEmpty() const {
	return top == -1;
}
template<typename T, int SIZE>//测试是否满栈
bool Stack<T, SIZE>::isFull() const {
	return top == SIZE - 1;
}
template<typename T, int SIZE>//清空栈
void Stack<T, SIZE>::clear() {
	top = -1;
}

#endif // !STACK_H
