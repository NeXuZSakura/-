#pragma once
#include <string>
#include "Queue.h"

template <class T>
class WrongQueueSize : public Queue<T>::QueueException
{
public:
	WrongQueueSize(const std::string& message) : Queue<T>::QueueException(" WrongQueueSize: " + message + "\n\n") {}
};