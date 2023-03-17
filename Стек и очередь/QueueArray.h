#pragma once
#include <iostream>
#include <string>
#include "Queue.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"
#include "WrongQueueSize.h"

template <class T>
class QueueArray : public Queue<T>
{
public:
	QueueArray(size_t size);
	QueueArray(QueueArray<T>&& tmp);
	~QueueArray() override;

	void enQueue(const T& value) override;
	T deQueue() override;
	bool isEmpty() override;
	void print();

private:
	T* array_;
	size_t head_ = 0;
	size_t tail_ = 0;
	size_t size_;
	void replace(QueueArray<T>& tmp);
};

template<typename T>
QueueArray<T>::QueueArray(size_t size)
{
	size_ = size;
	head_ = 0;
	tail_ = 0;
	if (size_ < 1)
	{
		throw WrongQueueSize<T>("queue size is invalid (small)!");
	}
	try
	{
		array_ = new T[size_ + 1];
	}
	catch (...)
	{
		throw WrongQueueSize<T>("queue size is invalid (huge) !");
	}
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& tmp)
{
	this->replace(tmp);
}

template<typename T>
QueueArray<T>::~QueueArray()
{
	delete[] array_;
}

template<typename T>
void QueueArray<T>::enQueue(const T& value)
{
	if (head_ == tail_ + 1 || (tail_ == size_ && head_ == 0))
	{
		throw QueueOverflow<T>(" the queue is full! ");
	}
	array_[tail_] = value;
	tail_++;
}

template<typename T>
T QueueArray<T>::deQueue()
{
	if (isEmpty())
	{
		throw QueueUnderflow<T>("queue is empty!");
	}
	array_[head_] = NULL;;
	for (int i = 0; i < size_; ++i)
	{
		array_[i] = array_[i + 1];
	}
	tail_--;
	array_[tail_] = NULL;
	array_[size_] = NULL;
	return *array_;
}

template<typename T>
bool QueueArray<T>::isEmpty()
{
	return head_ == tail_;
}

template<typename T>
void QueueArray<T>::replace(QueueArray<T>& tmp)
{
	std::swap(array_, tmp.array_);
	std::swap(size_, tmp.size_);
	std::swap(head_, tmp.head_);
	std::swap(tail_, tmp.tail_);
}

template<typename T>
void QueueArray<T>::print()
{
	for (int i = 0; i < size_; ++i)
	{
		std::cout << array_[i] << std::endl;
	}
}