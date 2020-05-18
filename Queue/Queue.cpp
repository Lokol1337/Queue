#pragma once
#include "Queue.h"
#include "QueueImplementation.h"
#include "VectorQueue.h"
#include "ListQueue.h"
#include "DoubleListQueue.h"
#include <iostream>
#include <stdexcept>

Queue::Queue(QueueContainer container)
	: _containerType(container)
{
	switch (container) 
	{
	case QueueContainer::List: {
		_pimpl = new ListQueue();	// конкретизируйте под ваши конструкторы, если надо
		break;	
	}
	case QueueContainer::Vector: {
		_pimpl = new VectorQueue();	// конкретизируйте под ваши конструкторы, если надо
		break;
	}
	case QueueContainer::DoubleList : {
		_pimpl = new DoubleListQueue();
		break;
	}
	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}
}


Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container)

    : _containerType(container)
    {
    switch (container)
    {
        case QueueContainer::List: {
			_pimpl = new ListQueue();// конкретизируйте под ваши конструкторы, если надо	
        break;
       }

        case QueueContainer::Vector: {
			_pimpl = new VectorQueue(); // конкретизируйте под ваши конструкторы, если надо
        break;
        }
		case QueueContainer::DoubleList: {
			_pimpl = new DoubleListQueue();
			break;
		}
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
        }
	for (size_t i = 0; i < arraySize; i++)
	{
		_pimpl->enqueue(valueArray[i]);
	}
    }

Queue::Queue(const Queue& copyStack)
{
	_containerType = copyStack._containerType;
	switch (_containerType)
	{
	case QueueContainer::List: {
		_pimpl = new ListQueue(*(static_cast<ListQueue*>(copyStack._pimpl)));// конкретизируйте под ваши конструкторы, если надо	
		break;
	}

	case QueueContainer::Vector: {
		_pimpl = new VectorQueue(*(static_cast<VectorQueue*>(copyStack._pimpl))); // конкретизируйте под ваши конструкторы, если надо
		break;
	}
	case QueueContainer::DoubleList: {
		_pimpl = new DoubleListQueue(*(static_cast<DoubleListQueue*>(copyStack._pimpl)));
		break;
	}
	default:
		throw std::runtime_error("Unknown type");
	}
}

Queue& Queue::operator=(const Queue& copyStack) {
	int copySize = copyStack.size();
	delete _pimpl;
	if(copyStack._containerType == QueueContainer::List)
	{
		_pimpl = new ListQueue();// конкретизируйте под ваши конструкторы, если надо
	}
	if(copyStack._containerType == QueueContainer::Vector)
	{
		_pimpl = new VectorQueue();    // конкретизируйте под ваши конструкторы, если надо
	}
	if (copyStack._containerType == QueueContainer::DoubleList)
	{
		_pimpl = new DoubleListQueue();
	}
	ValueType* array = new ValueType[copySize];
	for (int i = 0; i < copySize; i++) 
	{
		array[i] = copyStack._pimpl->front();
		//std::cout<< copyStack._pimpl->front()<<std::endl;
		copyStack._pimpl->dequeue();
	}
	for (int i = copySize-1; i >=0; i--)
	{
		_pimpl->enqueue(array[i]);
		copyStack._pimpl->enqueue(array[i]);
	}
	delete[] array;
	return *this;
	// TODO: вставьте здесь оператор return
}

Queue::~Queue()
{
	delete _pimpl;		// композиция!
}

void Queue::enqueue(const ValueType& value)
{
	// можно, т.к. enqueue определен в интерфейсе
	_pimpl->enqueue(value);
}

void Queue::dequeue()
{
	_pimpl->dequeue();
}

const ValueType& Queue::front() const
{
	return _pimpl->front();
}

bool Queue::isEmpty() const
{
	return _pimpl->isEmpty();
}

size_t Queue::size() const
{
	return _pimpl->size();
}

/*int main() {
	Queue s1(QueueContainer::Vector);
	s1.enqueue(1);
	s1.enqueue(2);
	s1.enqueue(3);

	Queue s2(QueueContainer::Vector);
	s2 = s1;
	size_t b = s2.size();
	//std::cout << s1.size() << std::endl; 
	for (int i = 0; i < b; i++)
	{
		std::cout << s2.front();
		s2.dequeue();
	}
	for (int i = 0; i < b; i++)
	{
		std::cout << s1.front();
		s1.dequeue();
	}

	//return 0;
}*/

