#ifndef __PRIORITY_NODE_H_
#define __PRIORITY_NODE_H_

template < typename T>
class Priority_Node
{
private :
	T item; // A data item
	float priority;
	Priority_Node<T>* next; // Pointer to next node
public :
	Priority_Node();
	Priority_Node( const T & r_Item, float p);	//passing by const ref.
	Priority_Node( const T & r_Item, Priority_Node<T>* nextNodePtr, float p);
	void setItem( const T & r_Item);
	void setNext(Priority_Node<T>* nextNodePtr);
	void setPriority( float p);
	T getItem() const ;
	Priority_Node<T>* getNext() const ;
	float getPriority() const ;
}; // end Node


template < typename T>
Priority_Node<T>::Priority_Node() 
{
	next = nullptr;
	priority = -1;
} 

template < typename T>
Priority_Node<T>::Priority_Node( const T& r_Item, float p)
{
	item = r_Item;
	next = nullptr;
	priority = p;
} 

template < typename T>
Priority_Node<T>::Priority_Node( const T& r_Item, Priority_Node<T>* nextNodePtr, float p)
{
	item = r_Item;
	next = nextNodePtr;
	priority = p;
}

template < typename T>
void Priority_Node<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void Priority_Node<T>::setNext(Priority_Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
T Priority_Node<T>::getItem() const
{
	return item;
} 

template < typename T>
Priority_Node<T>* Priority_Node<T>::getNext() const
{
	return next;
}

template < typename T>
void Priority_Node<T>::setPriority(float p)
{
	priority = p;
}

template < typename T>
float Priority_Node<T>::getPriority() const
{
	return priority;
}


#endif