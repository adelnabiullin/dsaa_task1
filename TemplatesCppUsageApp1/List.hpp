// List.hpp

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T> *next;
};

template <class T>
class List {
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	List();
	~List();
	int getSize();
	bool isEmpty();
	void push(T);
	T pop();
	void unshift(T);
	T shift();
	T operator[](int);
	void addValueAt(int, int);
	T deleteAt(int);
};

template <class T>
List<T>::List() {
	head = tail = nullptr;
	size = 0;
}

template <class T>
List<T>::~List() {
	Node<T> *tmp = nullptr;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
	size = 0;
	tmp = tail = nullptr;
}

template<class T>
int List<T>::getSize() {
	return size;
}

template<class T>
bool List<T>::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

template<class T>
void List<T>::push(T value) {
	Node<T> *tmp = new Node<T>;
	tmp->data = value;
	tmp->next = nullptr;
	size++;
	if (size == 1) {
		head = tail = tmp;
		return;
	}
	tail->next = tmp;
	tail = tmp;
}

template<class T>
T List<T>::pop() {
	T result = (T)0;
	if (head) {
		result = tail->data;
		delete tail;
		size--;
		if (size == 0) {
			head = tail = nullptr;
			return result;
		}
		tail = head;
		for (int i = 0; i < size - 1; i++) {
			tail = tail->next;
		}
		tail->next = nullptr;
	}
	return result;
}

template<class T>
void List<T>::unshift(T value) {
	Node<T> *tmp = new Node<T>;
	tmp->data = value;
	tmp->next = head;
	head = tmp;
	tmp = nullptr;
	if (!tail) {
		tail = head;
	}
	size++;
}

template<class T>
T List<T>::shift() {
	T result = nullptr;
	if (head) {
		Node<T> *tmp = head;
		result = head.data;
		head = head->next;
		delete tmp;
		if (!head) {
			tail = nullptr;
		}
		size--;
	}
	return result;
}

template<class T>
T List<T>::operator[](int index) {
	if (index < 0 || index > size - 1) {
		std::cout << "There are no Node with such index\n";
		return (T)0;
	}
	Node<T> *tmp = head;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}

template<class T>
void List<T>::addValueAt(int value, int index) {
	if (index < 0 || index > size) {
		std::cout << "Wrong index\n";
		return;
	}
	size++;
	Node<T> *tmp = new Node<T>;
	tmp->data = value;
	tmp->next = nullptr;
	if (size == 1) {
		head = tail = tmp;
		return;
	}
	if (index == 0) {
		tmp->next = head;
		head = tmp;
		return;
	}
	Node<T> *before = head;
	for (int i = 0; i < index - 1; i++) {
		before = before->next;
	}
	tmp->next = before->next;
	before->next = tmp;
	if (index == size - 1) {
		tail = tmp;
	}
}

template<class T>
T List<T>::deleteAt(int index) {
	if (index < 0 || index > size - 1) {
		std::cout << "There are no Node with such index\n";
		return nullptr;
	}
	if (index == 0) {
		return shift();
	}
	if (index == size - 1) {
		return pop();
	}
	Node<T> *before = head;
	for (int i = 0; i < index - 1; i++) {
		before = before->next;
	}
	Node<T> *tmp = before->next;
	T result = tmp->data;
	before->next = tmp->next;
	delete tmp;
	return result;
}

#endif
