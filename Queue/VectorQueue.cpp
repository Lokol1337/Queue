#pragma once
#include "VectorQueue.h"

VectorQueue::VectorQueue() {}

void VectorQueue::enqueue(const ValueType& value)
{
	pushBack(value);
}

void VectorQueue::dequeue() {
	if (_hi != (MyVector::size()/3))
	{
		_hi++;
	}
	else
	{
		_hi++;
		this->erase(0, _hi);
		_hi = 0;
	}
}

const ValueType& VectorQueue::front() const {
	return (*this)[0+_hi];	
}

bool VectorQueue::isEmpty() const {
	if (this->MyVector::size() == 0)
		return true;
	return false;
}

size_t VectorQueue::size() const {
	//return _hi;
	return (MyVector::size() - _hi);
}


