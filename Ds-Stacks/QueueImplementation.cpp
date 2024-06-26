
#include "QueueImplementation.h"
#include <iostream>
#include <assert.h>

template <class T>
QueueImplementation<T>::QueueImplementation()
{
	size = 5;
	count = 0;
	front = back = -1;
	arr = new T[size];
}

template <class T>
int QueueImplementation<T>::length()
{
	return count;
}

template <class T>
void QueueImplementation<T>::enqueue(T val)
{
	assert(!full());



	if (count == 0)
		front = 0;
	back = (back + 1) % size;
	arr[back] = val;
	count++;
}

template <class T>
void QueueImplementation<T>::dequeue()
{
	assert(!empty());
	if (count == 1)
		front = back = -1;
	else
		front = (front + 1) % size;
	count--;
}

template <class T>
T QueueImplementation<T>::Front()
{
	assert(!empty());
	return arr[front];
}

template <class T>
bool QueueImplementation<T>::full()
{
	return (count == size);
}

template <class T>
bool QueueImplementation<T>::empty()
{
	return (count == 0);
}
template <class T>
void QueueImplementation<T>::clear() {
	while (!empty()) {
		dequeue();
	}
}
template <class T>
QueueImplementation<T>::~QueueImplementation(void)
{
	delete[] arr;
}