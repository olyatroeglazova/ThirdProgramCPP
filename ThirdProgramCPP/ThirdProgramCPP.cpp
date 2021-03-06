#include "stdafx.h"
#include <iostream>
#include "List.h"
#include "BidirectionalList.h"

int main() {
	BidirectionalList<int> *list = new BidirectionalList<int>();
	Iterator<int> *iter = list->iteratorToFirst();
	for (int i = 0; i < 5; i++) {
		list->push(iter, i);
	}
	std::cout << "List: "<<std::endl;
	iter->start();
	while (!iter->isFinished()) {
		std::cout << iter->getValue() << " ";
		iter->next();
	}
	std::cout << std::endl;


	BidirectionalList<int>* copy(list);
	Iterator<int> *it = copy->iteratorToFirst();
	std::cout << "Copy of list: " << std::endl;
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;


	iter = list->findFirst(3);
	list->push(iter, 3);
	std::cout << "Push 3 in list: " << std::endl;
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;

	iter = list->findFirst(1);
	list->remove(iter);
	std::cout << "Removed 1 from list: ";
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;


	iter = list->findFirst(2);
	list->remove(iter);
	std::cout << "Removed 2 from list: ";
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;


	iter = list->findFirst(3);
	list->remove(iter);
	std::cout << "Removed first 3 from list: ";
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;


	list->doEmpty();
	std::cout << "Erased list: ";
	it->start();
	while (!it->isFinished()) {
		std::cout << it->getValue() << " ";
		it->next();
	}
	std::cout << std::endl;


	system("pause");

	return 0;
}