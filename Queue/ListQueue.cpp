#pragma once
#include "ListQueue.h"

ListQueue::ListQueue() {}

void ListQueue::enqueue(const ValueType& value) {
	pushFront(value);
}

void ListQueue::dequeue() 
{
	this->removeBack();
}

const ValueType& ListQueue::front() const{
	return getNode(size()-1)->value;
}
bool ListQueue::isEmpty() const {
	if (LinkedList::size() == 0)
		return true;
	return false;
}
size_t ListQueue::size() const {
	return this->LinkedList::size();
}