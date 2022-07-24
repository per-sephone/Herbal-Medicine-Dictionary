/*
Nora Luna
CS 202
Program 2
node.tpp

This file contains the implementation of my node template class. 
This template has get/set next & get/set previous pointer functions.
It has several functions to retrieve the data from the node. It also
has a display function, as well as the necessary constructors and 
destructor.
*/

#ifndef NODE_TPP
#define NODE_TPP
//#include "node.h"
#include <iostream>

template<typename TYPE>
Node<TYPE>::Node() : next(nullptr) , prev(nullptr)
{

}

template<typename TYPE>
Node<TYPE>::Node(const TYPE& toCopy)
{
    data = toCopy;
    next = nullptr;
    prev = nullptr;
}

template<typename TYPE>
Node<TYPE>::Node(const Node& toCopy)
{
    data = toCopy.data;
    next = toCopy.next;
    prev = toCopy.prev;
}

template<typename TYPE>
Node<TYPE>::~Node()
{
    next = nullptr;
    prev = nullptr;
}

template<typename TYPE>
Node<TYPE>& Node<TYPE>::operator=(const Node& aNode)
{
    if(this == &aNode)
    {
        return *this;
    }
   

    data = aNode.data;
    
    if(aNode.next)
    {
        next = aNode.next;
    }
    else
    {
        next = nullptr;
    }

    if(aNode.prev)
    {
        prev = aNode.prev;
    }
    else
    {
        prev = nullptr;
    }

    return *this;
}

template<typename TYPE>
shared_ptr<Node<TYPE>>& Node<TYPE>::getNext(void)
{
    return next;
}

template<typename TYPE>
shared_ptr<Node<TYPE>>& Node<TYPE>::getPrev(void)
{
    return prev;
}

template<typename TYPE>
bool Node<TYPE>::setNext(shared_ptr<Node<TYPE>> newNext)
{
    next = newNext; 
    return true;
}

template<typename TYPE>
bool Node<TYPE>::setPrev(shared_ptr<Node<TYPE>> newPrev)
{
    prev = newPrev;
    return true;
}

template<typename TYPE>
bool Node<TYPE>::setData(TYPE& d)
{
    data = d;
    return true;
}

template<typename TYPE>
TYPE Node<TYPE>::getData(void) const
{
    return data;
}

template<typename TYPE>
bool Node<TYPE>::getData(TYPE& get) const
{
    get = data;
    return true;
}

template<typename TYPE>
bool Node<TYPE>::display(void) const
{
    cout << data << endl;
    return true;
}

#endif
