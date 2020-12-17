#pragma once
#include<iostream>
#include"Generic_DS/Node.h"

using namespace std;
template <class T>
class Stack
{
	Node* TopPtr;
	 Node*CurrPtr;
public:
	Stack();
	bool IsEmpty();
	void Push(T);
	void pop(T&);
		void Peek(T&);
};

