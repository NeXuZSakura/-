#pragma once
#include <string>
#include "Queue.h"

template <class T>
class QueueUnderflow : public Queue<T>::QueueException
{
public:
	QueueUnderflow(const std::string& message) : Queue<T>::QueueException(" QueueUnderflow:  " + message + "\n\n") {}
};