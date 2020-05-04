#pragma once
#include "QueueImplementation.h"
#include "../Vector/MyVector.h"
 // меняете на include вашего вектора

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class VectorQueue : public QueueImplementation, public MyVector
{
	public	:

	VectorQueue();
	void enqueue(const ValueType& value);
	void realdequeue();
	void dequeue();
	const ValueType& front() const;
	bool isEmpty() const;
	size_t size() const;
	private :
		size_t _hi = 0;
};

