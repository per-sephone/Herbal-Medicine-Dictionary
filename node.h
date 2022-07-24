/*
Nora Luna
CS 202
Program 2
node.h

This file contails the function prototypes for the node template class.
This template has get/set next & get/set previous pointer functions.
It uses shared_ptr for the pointers. Each node contains the data,
next, and previous pointers. This class also has several functions
to retrieve the data within the node and display.
*/

#ifndef NODE_H
#define NODE_H

//#include <iostream>
#include <memory>

using namespace std;


template <typename TYPE>
class Node
{
    public:
        Node();
        Node(const TYPE& aData);
        Node(const Node& toCopy);
        ~Node();

        Node<TYPE>& operator=(const Node& aNode);
        shared_ptr<Node<TYPE>>& getNext(void);
        shared_ptr<Node<TYPE>>& getPrev(void);
        bool setNext(shared_ptr<Node<TYPE>> newNext);
        bool setPrev(shared_ptr<Node<TYPE>> newPrev);

        bool setData(TYPE& d);
        TYPE getData(void) const;
        bool getData(TYPE& get) const;
        bool display(void) const;
        
    protected:
        TYPE data;
        shared_ptr<Node<TYPE>> next;
        shared_ptr<Node<TYPE>> prev;
};

#include "node.tpp"
#endif
