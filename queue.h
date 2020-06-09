#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "SinglyLinkedList.h"

template <typename T>
class Queue : public SinglyLinkedList<T>
{
    public:
        /*
        template<typename T>
        void enQueue();

        put data into the Queue

        Pre:	T data
        Post:	None.
        Return:	None.
		*/
        void enQueue(T);

        /*
        template<typename T>
        T deQueue();

        remove and return data from the Queue

        Pre:	None.
        Post:	throw exception if queue is empty.
        Return:	the first data from the queue.
		*/
        T deQueue();

        /*
        template<typename T>
        void display()

        display the Queue

        Pre:	None.
        Post:	None.
        Return:	None.
		*/
        void display();

        /*
        template<typename T>
        T peekFront();

        peek at what is in the front of the queue

        Pre:	None.
        Post:	None.
        Return:	None.
		*/
        T peekFront();
        
        /*
        template<typename T>
        T peekRear();

        peek at what is in the rear of the queue

        Pre:	None.
        Post:	None.
        Return:	None.
		*/
        T peekRear();

        // constructor
        Queue();
        // destructor
        ~Queue();
};

template <typename T>
void Queue<T>::enQueue(T data)
{
   this->append(data);
}

template <typename T>
T Queue<T>::deQueue()
{
    T temp = peekFront();
    this->removeFirst();
    return temp;
}

template <typename T>
void Queue<T>::display()
{
  this->printList();
}

template <typename T>
T Queue<T>::peekFront()
{
    return this->getStart();
}
template <typename T>
T Queue<T>::peekRear()
{
    return this->getEnd();
}

template <typename T>
Queue<T>::Queue()
{
    SinglyLinkedList<T>();
}
template <typename T>
Queue<T>::~Queue()
{
    this->clearList();
}


#endif