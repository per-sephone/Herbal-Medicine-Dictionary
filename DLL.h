/*
Nora Luna
CS 202
Program 2
DLL.h

This file contains the prototypes for my Double Linked List template
class. It uses shared_ptr from the STL, as well as a node template.
This template has member functions head pointer, tail pointer, and size.
This template has the ability to insert, search, remove, and display
all using recursive functions.
*/

#ifndef DLL_H
#define DLL_H

#include "node.h"


template <typename TYPE>
class DLL
{
    public:
        DLL();
        DLL(const DLL& aList);
        ~DLL();
        const DLL& operator=(const DLL& aList);
        void destroy(void);
        bool insert(const TYPE& toAdd);
        void remove(const TYPE& target);
        void remove(const string& target);
        shared_ptr<Node<TYPE>> search(const TYPE& target);
        shared_ptr<Node<TYPE>> search(const string& target);
        void display(void);


    protected:

        shared_ptr<Node<TYPE>> head;
        shared_ptr<Node<TYPE>> tail;
        int size;
        
        void destroy(shared_ptr<Node<TYPE>>& head);
        bool copy(shared_ptr<Node<TYPE>>& dest, shared_ptr<Node<TYPE>> source);
        bool insert(shared_ptr<Node<TYPE>>& head, const TYPE& data);
        void remove(shared_ptr<Node<TYPE>>& head, const TYPE& target);
        void remove(shared_ptr<Node<TYPE>>& head, const string& target);
        shared_ptr<Node<TYPE>> search(shared_ptr<Node<TYPE>>& head, 
                const TYPE& target);
        shared_ptr<Node<TYPE>> search(shared_ptr<Node<TYPE>>& head,
                const string& target);
        void display(shared_ptr<Node<TYPE>>& head);
};

#include "DLL.tpp"
#endif
