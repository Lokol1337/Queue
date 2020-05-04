#pragma once
#include "DoubleListQueue.h"

DoubleListQueue::DoubleListQueue() {}

void DoubleListQueue::enqueue(const ValueType& value) {
	pushFront(value);
}

void DoubleListQueue::dequeue() {
	this->removeBack();
}

const ValueType& DoubleListQueue::front() const {
	return getNode(size()-1)->value;
}

bool DoubleListQueue::isEmpty() const {
	if (LinkedList2::size() == 0)
		return true;
	return false;

}
size_t DoubleListQueue::size() const {
	return this->LinkedList2::size();
}