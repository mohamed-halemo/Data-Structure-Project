#include "Stack.h"
#include"Generic_DS/Node.h"
template <class T>
Stack<T>::Stack() :TopPtr = NULL;

template <class T>
bool Stack<T>::IsEmpty()
{
	if (TopPtr == NULL)
	{
		return true;
	}
	else
		return false;
}
template <class T>

void Stack<T>::Peek(T& Top)
{
	if (IsEmpty())
		cout << "there is nothing in the stack";
	else
	{
		Top = TopPtr->getItem();
	}
}

template <class T>

void Stack<T>::pop(T& Top)
{
	if (IsEmpty())
		cout << "No Items in the stack";
	else
	{
		Top = TopPtr->getItem();
			Node<T> * temp = TopPtr;
		TopPtr = TopPtr->getNext();
		temp->getNext() = NULL;
		delete temp;
	}
}

template<class T>
void Stack<T>::Push(T Item)
{
	Node<T>* newPtr = new Node;
	if (newPtr == NULL)
		cout << "Stack push cannot allocate memory";
	else
	{
		Node<T>* newPtr = new StackNode;
		if (newPtr == NULL)
			cout << "Stack push cannot allocate memory";
		else
		{
			newPtr->setItem(Item);
			newPtr->setNext(TopPtr);
			TopPtr = newPtr;
		}
	}
}
///////////////////////DONE BY ABDELHALEM