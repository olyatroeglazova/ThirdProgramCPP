#pragma once
#include "Iterator.h"

template<typename T>
class List {
public:
	virtual void push(Iterator<T>*,T ) = 0;
	virtual void remove(Iterator<T>*) = 0;
	virtual Iterator<T> *findFirst(T )  = 0;
	virtual void doEmpty() = 0;
	virtual bool isEmpty() const = 0;
	virtual int length() const = 0;
	virtual Iterator<T> *iteratorToFirst() const = 0;
	virtual ~List() {};
};