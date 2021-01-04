#pragma once
#include "Priority_Node.h"

template <typename T>
class Priority_Queue
{
private:
	Priority_Node<T>* backPtr;
	Priority_Node<T>* frontPtr;

public:
	Priority_Queue()
	{
		backPtr=nullptr;
		frontPtr=nullptr;
	}

	bool isEmpty() const 
	{
		if(frontPtr==nullptr)
			return true;
		else
			return false;
	}

	bool enqueue(const T& newEntry,float priority)
	{
		Priority_Node<T> * searchptr=new Priority_Node<T> ();
		Priority_Node<T> * prevptr=new Priority_Node<T>();
		prevptr=frontPtr;
		searchptr=frontPtr;
		Priority_Node<T> * newptr=new Priority_Node<T> (newEntry, priority);
		if(!this)	
			return false;
		if(this->isEmpty())
		{
			frontPtr=newptr;
			return true;
		}
		else
		{
			while(searchptr)
			{
				if(newptr->getPriority() > searchptr->getPriority())
				{
					if(searchptr == frontPtr)
					{
						newptr->setNext(frontPtr);
						frontPtr=newptr;
						return true;
					}
					else
					{
						newptr->setNext(prevptr->getNext());
						prevptr->setNext(newptr);
						return true;
					}
				}
				prevptr=searchptr;
				searchptr=searchptr->getNext();
			}
			prevptr->setNext(newptr);
			newptr->setNext(nullptr);
			backPtr=newptr;
			return true;
		}
		return false;
	}

	bool dequeue(T& frntEntry)			//NOTE: There's no need to return the priority value.
	{
		if(isEmpty())
		return false;

	Priority_Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr ;	
		
	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;
	return true;
	}

	bool peekFront(T& frntEntry)  const
	{
		if(isEmpty())
		return false;
		frntEntry = frontPtr->getItem();
		return true;
	}


	~Priority_Queue()
	{
	}
};