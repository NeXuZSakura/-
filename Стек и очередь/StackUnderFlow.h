#pragma once
#include <string>
#include "Stack.h"

template <class T>
class StackUnderflow : public Stack<T>::StackException
{
public:
	StackUnderflow(const std::string& message) : Stack<T>::StackException(" StackUnderflow: " + message + "\n\n") {}
};