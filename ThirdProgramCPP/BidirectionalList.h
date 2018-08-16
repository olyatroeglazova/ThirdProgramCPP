#include "List.h"

template<typename T>
class BidirectionalList : public List<T> {
private:

	Node<T> *buffer;
		int size;

public:
		template<typename T>
	class ListIterator : public Iterator<T> {
		friend class BidirectionalList<T>;
	private:
		Node<T> *buffer;
		Node<T> *current;

	public:

		ListIterator(Node<T> *node)
			: buffer(node), current(node->next) {}

		Node<T> *getNode() {
			return current;
		}
		void start() override {
			current = buffer->next;
		}

		T getValue() const override {
			return current->value;
		}

		void next() override {
			current = current->next;
		}

		bool isFinished() const override {
			return current == buffer;
		}

	};

	BidirectionalList() {
		buffer = new Node<T>;
		buffer->value = 0;
		buffer->next = buffer;
		buffer->prev = buffer;
		size = 0;
	}

	BidirectionalList(const BidirectionalList<T>& list) {
		buffer = new Node<T>;
		buffer->value = 0;
		buffer->next = buffer;
		buffer->prev = buffer;
		if (!list.isEmpty()) {
			for (Node<T> *node = list->buffer->next; node != &list->buffer; node = node->next)
				push(node->value);
		}
	}

	BidirectionalList(BidirectionalList<T>&& list) 
	: buffer(list.buffer), size(list.length()) {
		list.buffer = nullptr;
		list.size = 0;
	}

	BidirectionalList& operator= (const BidirectionalList& list) {
		if (list.buffer != this->buffer) {
			doEmpty();
			Node<T> *tmp = list.buffer->next;
			while (tmp != list.buffer) {
				push(tmp->value);
				tmp = tmp->next;
			}
		}
		return *this;
	}
	BidirectionalList& operator= (BidirectionalList&& list) {
		if (list.buffer != this->buffer) {
			doEmpty();
			buffer = list.buffer;
			size = list.size;
		}
		return *this;
	}
	
	~BidirectionalList() override {
		doEmpty();
		delete buffer;
	}
	void push(Iterator<T> *iter, T value) override {
		Node<T> *curr = iter->getNode();
		Node<T> *newNode = new Node<T>;
		newNode->value = value;
		newNode->prev = curr->prev;
		newNode->next = curr;
		curr->prev->next = newNode;
		curr->prev = newNode;
		size++;

	}
	void remove(Iterator<T> *iter) override {
		Node<T> *curr = iter->getNode();
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
		size--;

	}
	ListIterator<T>* findFirst(T elem) {
		ListIterator<T>* listIter = iteratorToFirst();
		listIter->start();
		while (!listIter->isFinished()) {
			if (listIter->getValue() == elem) {
				return listIter;
			}
			else {
				listIter->next();
			}
		}
		return nullptr;
	}

	void doEmpty() override {
		Node<T> *tmp = buffer->next;
		while (tmp != buffer) {
			Node<T> *temp = tmp->next;
			delete tmp;
			tmp = temp;
		}
		buffer->next = buffer;
		buffer->prev = buffer;

		size = 0;
	}
	bool isEmpty() const override {
		return size == 0;
	}
	int length() const override {
		return size;
	}
	ListIterator<T> *iteratorToFirst() const override {
		return new ListIterator<T>(this->buffer);
	}
};
