#pragma once

template <class T>
struct Node {
	T data;
	Node *next;
};

template <class T>
class List {
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	List ();
	~List ();
	int getSize();
	bool isEmpty();
	void push(T);
	T pop();
	void unshift(T);
	T shift();
	T &operator[](int);
	void addValueAt(int, int);
	T deleteAt(int);
};
