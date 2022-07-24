/*
Nora Luna
CS 202
Program 2
DLL.tpp

This file contains the implementation of my Double Linked List template
class.
This template has the ability to insert in sorted order, remove by search
string or by search object, search by search string or by search object, 
and display. 
The protected data members are head pointer, tail pointer, and size.
The pointers in this array are shared_ptr from the STL. 
This template also uses a node template.
*/

#ifndef DLL_TPP
#define DLL_TPP
//#include "DLL.h"
#include <iostream>

//constructor
template<typename TYPE>
DLL<TYPE>::DLL() : head(nullptr), tail(nullptr), size(0)
{

}

//copy constructor
template<typename TYPE>
DLL<TYPE>::DLL(const DLL& aList)
{
    if(head)
    {
        destroy();    
    }

    //exception handling
    if(aList.size == 0) //nothing to copy
        throw(aList);
                
    
    copy(head, aList.head);
}

//destructor
template<typename TYPE>
DLL<TYPE>::~DLL()
{
    destroy();
}

//destroys the list- wrapper function
template<typename TYPE>
void DLL<TYPE>::destroy()
{
    destroy(head);
}

//destroys the list- recursive function
template<typename TYPE>
void DLL<TYPE>::destroy(shared_ptr<Node<TYPE>>& head)
{
    if(head == tail)
    {
        return;
    }
    destroy(head->getNext());
    head.reset();
}

//recursive copy function- copies the list to a new list
template<typename TYPE>
bool DLL<TYPE>::copy(shared_ptr<Node<TYPE>>& dest, shared_ptr<Node<TYPE>> source)
{
    if(!source)
    {
        dest = nullptr;
        return true;
    }
    dest = shared_ptr<Node<TYPE>>(new Node<TYPE>(source.data));
    dest.prev = source.prev;
    dest.next = source.next;
    return copy(dest->getNext(), source->getNext());
}

//insert a new element into the list-  wrapper function
template<typename TYPE>
bool DLL<TYPE>::insert(const TYPE& toAdd)
{
    if(size == 0)
    {
        shared_ptr<Node<TYPE>> newNode(new Node<TYPE>(toAdd));

        head = newNode;
        tail = newNode;
        size++;
        return true;
    }

    return insert(head, toAdd);
}

//insert a new element into the list- recursive function
template<typename TYPE>
bool DLL<TYPE>::insert(shared_ptr<Node<TYPE>>& head, const TYPE& data)
{

    
    TYPE comp;
    head->getData(comp);

    if(data <= comp) 
        //data is less than or equal to head -> insert into list
        //or at the end of the list
    {
        shared_ptr<Node<TYPE>> toAdd(new Node<TYPE>(data));


        if(!head->getPrev()) //real head
        {
            //make as new head
            head->setPrev(toAdd); //head->prev = toAdd
            toAdd->setNext(head); //toAdd->next = head
            head = toAdd;
        }
        else //middle of the list
        {
            //insert node in front of current node
            shared_ptr<Node<TYPE>> temp(head->getPrev()); //temp = head->prev

            toAdd->setPrev(temp); //add->prev = temp
            toAdd->setNext(head); //add->prev = head
            head->setPrev(toAdd); //head->prev = add
            temp->setNext(toAdd); //temp->next = add

        }
        size++;
        return true;
    }

    if(!head->getNext())// end of the list
    {
        shared_ptr<Node<TYPE>> toAdd(new Node<TYPE>(data));

        //make new tail
        toAdd->setPrev(tail); //add->prev = tail
        tail->setNext(toAdd); //tail->next = add
        tail = toAdd; 
        size++;
        return true;
    }



    return insert(head->getNext(), data);

}

//remove an element from the list- wrapper function
template<typename TYPE>
void DLL<TYPE>::remove(const TYPE& target)
{
    if(size == 0)
        throw head;

    remove(head, target);
}

//remove an element from the list- recursive function
template<typename TYPE>
void DLL<TYPE>::remove(shared_ptr<Node<TYPE>>& head, const TYPE& target)
{
    TYPE comp;
    head->getData(comp);
    
    
    //base case
    if(comp == target)
    {
        if(!head->getPrev()) //real head
        {

            if(size == 1)
            {
                head.reset();
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                shared_ptr<Node<TYPE>> temp(head);

                head = head->getNext();
                temp.reset();
                head->setPrev(nullptr);
            }

        }
        else if(head == tail) //tail
        {
            shared_ptr<Node<TYPE>> temp(tail);

            tail = head->getPrev();
            temp.reset();
            tail->setNext(nullptr);
        }
        else //middle of the list
        {
            shared_ptr<Node<TYPE>> temp(head);

            head->getPrev()->setNext(head->getNext());
            head->getNext()->setPrev(head->getPrev());
            temp.reset();
        }

        size--;
        return;

    }

    //exception handling- if target does not match anything
    if(head == tail && comp != target)
        throw target;

    remove(head->getNext(), target);
}


//remove by string name, wrapper function
template<typename TYPE>
void DLL<TYPE>::remove(const string& target)
{
    if(size == 0)
        throw head;

    remove(head, target);
}

//remove by string name, recursive function
template<typename TYPE>
void DLL<TYPE>::remove(shared_ptr<Node<TYPE>>& head, const string& target)
{
    TYPE comp;
    head->getData(comp);

        //base case
    if(comp == target)
    {
        if(!head->getPrev()) //real head
        {
            if(size == 1)
            {
                head.reset();
                head = nullptr; 
                tail = nullptr;
    
            }
            else
            {
                shared_ptr<Node<TYPE>> temp(head);

                head = head->getNext();
                temp.reset();
                head->setPrev(nullptr);
            }

        }
        else if(head == tail) //tail
        {
            shared_ptr<Node<TYPE>> temp(tail);

            tail = head->getPrev();
            temp.reset();
            tail->setNext(nullptr);
        }
        else //middle of the list
        {
            shared_ptr<Node<TYPE>> temp(head);

            head->getPrev()->setNext(head->getNext());
            head->getNext()->setPrev(head->getPrev());
            temp.reset();
        }

        size--;
        return;

    }

    //exception handling- if target does not match anything
    if(head == tail && comp != target)
        throw target;

    remove(head->getNext(), target);
}


//search function wrapper function
template<typename TYPE>
shared_ptr<Node<TYPE>> DLL<TYPE>::search(const TYPE& target)
{
    if(size == 0)
        throw head;

    return search(head, target);
}

//search function- recursive function
template<typename TYPE>
shared_ptr<Node<TYPE>> DLL<TYPE>::search(shared_ptr<Node<TYPE>>& head, 
        const TYPE& target)
{
    TYPE comp;
    head->getData(comp);

    if(comp == target)
        return head;

    //exception handling- if target does not match anything
    if(head == tail && comp != target)
        throw target;


    return search(head->getNext(), target);
}

//search by string, wrapper function
template<typename TYPE>
shared_ptr<Node<TYPE>> DLL<TYPE>::search(const string& target)
{
    if(size == 0)
        throw head;

    return search(head, target);

}

//search by string, recursive function
template<typename TYPE>
shared_ptr<Node<TYPE>> DLL<TYPE>::search(shared_ptr<Node<TYPE>>&
        head, const string& target)
{
    TYPE comp;
    head->getData(comp);

    if(comp == target)
        return head;

    //exception handling- if target does not match anything
    if(head == tail && comp != target)
        throw target;


    return search(head->getNext(), target);

}

//display list- wrapper function
template<typename TYPE>
void DLL<TYPE>::display(void)
{
    if(size == 0)
        throw head;

    display(head);
}

//display list- recursive function
template<typename TYPE>
void DLL<TYPE>::display(shared_ptr<Node<TYPE>>& head)
{
    head->display();

    //base case
    if(!head->getNext())
        return;

     display(head->getNext());
}

#endif
