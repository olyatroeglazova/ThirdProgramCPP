#pragma once

template<typename T>
struct Node {
public:
	T value;
	Node<T> *next;
	Node<T> *prev;
};

template<typename T>
class Iterator {
public:
	virtual void start() = 0;
	virtual T getValue() const = 0;
	virtual void next() = 0;
	virtual bool isFinished() const = 0;
	virtual Node<T>* getNode() = 0;
};

