#pragma once
#include <string>

template <class T>
class Stack
{
public:
	virtual ~Stack(){}
	virtual  void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
	virtual const T& top() = 0;

	class StackException
	{
	public:
		StackException(const std::string& message) : message_(message) {}
		virtual ~StackException() {}
		std::string getMessage() const { return message_; }
	private:
		std::string message_;
	};
};