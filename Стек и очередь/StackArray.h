#pragma once
#include <iostream>
#include "Stack.h"
#include "StackOverFlow.h"
#include "StackUnderFlow.h"
#include "WrongStackSize.h"

template <class T>
class StackArray : public Stack<T>
{
public:
	StackArray(size_t size);
	StackArray(StackArray<T>&& tmp);
	~StackArray()override;

	void push(const T& value) override;
	T pop() override;
	bool isEmpty() override;
	void print();
	const T& top()override;

private:
	T* array_;
	size_t size_;
	size_t top_;
	void replace(StackArray<T>& tmp);
};


template<class T>
StackArray<T>::StackArray(size_t size)
{
	size_ = size + 1;
	top_ = 0;
	if (size_ < 1)
	{
		throw WrongStackSize<T>("size of stack is invalid(small)!");
	}
	try
	{
		array_ = new T[size_];
		for (int i = 0; i < size_; ++i)
		{
			array_[i] = NULL;
		}
	}
	catch (...)
	{
		throw WrongStackSize<T>("size of stack is invalid(huge)!");
	}
}

template<class T>
StackArray<T>::StackArray(StackArray<T>&& tmp)
{
	this->replace(tmp);
}

template<class T>
StackArray<T>::~StackArray()
{
	delete[] array_;
}

template<class T>
void StackArray<T>::push(const T& value)
{
	if (top_ == size_) { throw StackOverflow<T>("the stack is full!"); }
	array_[++top_] = value;
}

template<class T>
T StackArray<T>::pop()
{
	if (isEmpty()) { throw StackUnderflow<T>("the stack is empty!"); }
	array_[top_] = NULL;
	return array_[top_--];
}


template<class T>
bool StackArray<T>::isEmpty()
{
	if (top_ == 0) { return 1; }
	else { return 0; }
}


template<class T>
void StackArray<T>::replace(StackArray<T>& tmp)
{
	std::swap(array_, tmp.array_);
	std::swap(size_, tmp.size_);
	std::swap(top_, tmp.top_);
}

template<class T>
void StackArray<T>::print()
{
	for (int i = 1; i < size_; ++i)
	{
		std::cout << array_[i] << std::endl;
	}
}

template<class T>
const T& StackArray<T>::top()
{
	return array_[top_];
}