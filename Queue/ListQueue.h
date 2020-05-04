#pragma once

#include "QueueImplementation.h"
#include "../LinkedList/LinkedList1.h"
 // меняете на include вашего листа

// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListQueue : public QueueImplementation, public LinkedList
{

	public:
		ListQueue();

	void enqueue(const ValueType& value);
	// удаление с хвоста
	void dequeue();
	// посмотреть элемент в хвосте
	const ValueType& front() const;
	// проверка на пустоту
	bool isEmpty() const;
	// размер 
	size_t size() const;
};

