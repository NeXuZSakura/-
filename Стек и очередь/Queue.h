#pragma once
#include <iostream>
#include <string>

template <class T>
class Queue
{
public:
	virtual ~Queue(){}
	virtual void enQueue(const T& value) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;

	class QueueException
	{
	public:
		QueueException(const std::string& message) : message_(message) {}
		virtual ~QueueException(){}
		std::string getMessage() const { return message_; }
	private:
		std::string message_;
	};
};