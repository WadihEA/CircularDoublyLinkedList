/*
Title : Project1
Course : CSIS216 Fall 21-22
Version Information : Apache NetBeans 12.0
Date : 8 Nov  2021
Author: Wadih El Atie   A2010224

-- CircularDoublyLinkedList.cpp-------------------------------------------------
 
   This file implements Circular Doubly Linked List member functions.

-------------------------------------------------------------------------*/


#include "CircularDoublyLinkedList.h"

//--- Definition of class constructor

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    mySize = 0;
    myFirst = NULL;
}

//--- Definition of class copy constructor

CircularDoublyLinkedList::CircularDoublyLinkedList(const CircularDoublyLinkedList& orig) {
    DNodePtr newNodePtr = orig.myFirst; //get a pointer to the first node
    this->mySize = orig.mySize; //set sizes to be equal
    if (!orig.isEmpty()) {
        for (int i = 0; i < mySize; i++) {
            insertAtEnd(newNodePtr->getData()); //insert node into the list 
            newNodePtr->setNext(newNodePtr->getNext()); // move to the next
        }
    } //check that orig is no empty
}

//--- Definition of class destructor

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
    DNodePtr tempPtr; //pointer used to delete node
    for (int i = 0; i < mySize; i++) {
        tempPtr = myFirst;
        myFirst = myFirst->getNext();
        delete tempPtr;
    }

}

//--- Definition of class clear()

void CircularDoublyLinkedList::clear() {
    while (myFirst->getNext() != myFirst)
        deleteAtBeginning();
    deleteAtBeginning();
    //delete all the nodes of the list but keep the object in the memory
}

//--- Definition of class isEmpty()

bool CircularDoublyLinkedList::isEmpty() const {
    return mySize == 0;
}

//--- Definition of class size()

int CircularDoublyLinkedList::size() const {
    return mySize;
}

//--- Definition of class searchFirstOccurence()

DNodePtr CircularDoublyLinkedList::searchFirstOccurence(const ElementType n) const {
    DNodePtr locPtr; //pointer to the location of n
    locPtr = myFirst;
    for (int i = 0; i < mySize; i++) {
        if (locPtr->getData() == n)
            return locPtr; //return pointer to the node if it's data is n
        //else
        locPtr = locPtr->getNext(); //move to next pointer
    }
    return NULL; //returned if n not found
}

//--- Definition of class insertAtBegining()

void CircularDoublyLinkedList::insertAtBegining(const ElementType n) {
    DNodePtr newPtr = new DNode(n); //pointer to the node that will be inserted
    if (isEmpty()) {
        myFirst = newPtr;
        myFirst->setNext(myFirst);
    } 
    else {
        newPtr->setNext(myFirst); //set new pointer to point to myFirst
        myFirst->setPrevious(newPtr); //set previous of myFirst to point to new pointer
        myFirst = newPtr; //set myFirst to new pointer 
        DNodePtr lastPtr = myFirst; //pointer to the last node of the list
        for (int i = 0; i < mySize; i++) {
            lastPtr = lastPtr->getNext();
        }
        lastPtr->setNext(newPtr); //set last pointer to point to new pointer
        newPtr->setPrevious(lastPtr); //set the previous of new pointer to lastPtr
    }
    mySize++; //increment size
}

//--- Definition of class insertAtEnd()

void CircularDoublyLinkedList::insertAtEnd(const ElementType n) {
    DNodePtr newPtr = new DNode(n); //pointer to the node that will be inserted
    if (isEmpty()) {
        myFirst = newPtr;
        myFirst->setNext(myFirst);
    } 
    else {
        newPtr->setNext(myFirst); //set new pointer to point to myFirst
        myFirst->setPrevious(newPtr); //set previous of myFirst to point to new pointer
        DNodePtr lastPtr = myFirst; //pointer to the last node of the list
        while (lastPtr->getNext() != myFirst) {
            lastPtr = lastPtr->getNext();
        }
        lastPtr->setNext(newPtr); //set last pointer to point to new pointer
        newPtr->setPrevious(lastPtr); //set the previous of new pointer to lastPtr
    }
    mySize++; //increment size
}

//--- Definition of class insertAtPos()

bool CircularDoublyLinkedList::insertAtPos(const ElementType n, int pos) {
    if (pos >= 1 && pos <= mySize + 1) { //check if position is valid
        pos = pos - 1; //get position in a 0 based format
        if (pos == 0) {
            insertAtBegining(n); //if pos is 0 call insert at beginning method
        } 
        else if (pos == mySize) {
            insertAtEnd(n); //if pos is equal to mySize call insert at end method
        } 
        else {
            DNodePtr newPtr = new DNode(n); //pointer to the node that will be inserted
            DNodePtr predPtr = myFirst; //pointer to the node that we will add new node after
            for (int i = 0; i < pos - 1; i++) {
                predPtr = predPtr->getNext();
            }
            newPtr->setNext(predPtr->getNext()); //set next of the newPtr to the of its predecessor
            newPtr->setPrevious(predPtr); //set previous of the newPtr to its predecessor
            predPtr->setNext(newPtr); //set next of the predecessor to the newPtr
            (newPtr->getNext())->setPrevious(newPtr); //set previous of the node after newPtr to newPtr
            mySize++; //increment size
        }

        return true;
    }
    return false; //returned if size is not valid
}

//--- Definition of class insertMBeforeN()

bool CircularDoublyLinkedList::insertMBeforeN(const ElementType m, const ElementType n) {
    DNodePtr loc = searchFirstOccurence(n); //get location of n
    if (loc == NULL)
        return false; //returned if n not found
    if (loc == myFirst) {
        insertAtBegining(m); //if n was the first node call method to insert m at the beginning
    } 
    else {
        DNodePtr newPtr = new DNode(m); //node to be inserted
        newPtr->setNext(loc); //set next of the new node to n
        newPtr->setPrevious(loc->getPrevious()); //set previous of the new node to the previous of n
        (loc->getPrevious())->setNext(newPtr); //set net of the node before n to m
        loc->setPrevious(newPtr); //set previous of n to m
        mySize++; //increment size
    }

    return true;
}

//--- Definition of class deleteAtBeginning()

void CircularDoublyLinkedList::deleteAtBeginning() {
    assert(!isEmpty()); //quit if the list is empty
    (myFirst->getNext())->setPrevious(myFirst->getPrevious()); //set 2nd node to point to the last
    (myFirst->getPrevious())->setNext(myFirst->getNext()); //set last node to point to the second
    DNodePtr tempPtr = myFirst; //pointer that point to first 
    myFirst = myFirst->getNext(); //set myFirst to the 2nd node
    delete tempPtr; //delete the original myFirst
    mySize--; //decrement size
}

//--- Definition of class deleteAtEnd()

void CircularDoublyLinkedList::deleteAtEnd() {
    assert(!isEmpty()); //quit if the list is empty
    DNodePtr lastPtr = myFirst; //pointer to the last node
    for (int i = 0; i < mySize - 1; i++) {
        lastPtr = lastPtr->getNext();
    }
    myFirst->setPrevious(lastPtr->getPrevious()); //set previous of the first to the previous of the last node
    (lastPtr->getPrevious())->setNext(myFirst); //set the next of the node before the last to first
    DNodePtr tempPtr = lastPtr; //pointer that point to last
    lastPtr = lastPtr->getPrevious(); // let lastPtr become the pointer before the last
    delete tempPtr; //delete the original lastPtr
    mySize--; //decrement size
}

//--- Definition of class deleteAtPos()

bool CircularDoublyLinkedList::deleteAtPos(int pos) {
    if (!isEmpty()) {
        if (pos >= 1 && pos <= mySize + 1) { //check if position is valid
            pos = pos - 1; //get position in a 0 based format
            if (pos == 0) {
                deleteAtBeginning(); //if pos is 0 call delete at beginning method
            } 
            else {
                DNodePtr locPtr = myFirst; //pointer to the node that will be deleted
                for (int i = 0; i < pos; i++) {
                    locPtr = locPtr->getNext();
                }
                if (locPtr->getNext() == myFirst) {
                    deleteAtEnd(); //if the pointer was to the last node call delete at end method
                } 
                else {
                    (locPtr->getPrevious())->setNext(locPtr->getNext()); //set the next of the previous node to the next of current node
                    (locPtr->getNext())->setPrevious(locPtr->getPrevious()); //set the previous of the next node to the previous of current node
                    delete locPtr; //delete pointer
                    mySize--; //decrement size
                }
            }

            return true;
        }
    }
    return false; //if empty or invalid position
}

//--- Definition of class deleteN()

bool CircularDoublyLinkedList::deleteN(const ElementType n) {
    assert(!isEmpty()); //quit if the list is empty
    DNodePtr locPtr = searchFirstOccurence(n); //find node to be deleted
    if (locPtr != NULL) {
        if (locPtr == myFirst) {
            deleteAtBeginning(); //if the pointer was the first call delete at beginning method
        } 
        else if (locPtr->getNext() == myFirst) {
            deleteAtEnd(); //if the pointer was to the last node call delete at end method
        } 
        else {
            (locPtr->getPrevious())->setNext(locPtr->getNext()); //set the next of the previous node to the next of current node
            (locPtr->getNext())->setPrevious(locPtr->getPrevious()); //set the previous of the next node to the previous of current node
            delete locPtr; //delete pointer
            mySize--; //decrement size
        }
        return true;
    }
    return false; //if n not found
}
//--- Definition of class cutN()

DNodePtr CircularDoublyLinkedList::cutN(const ElementType n) {
    assert(!isEmpty()); //quit if the list is empty
    DNodePtr locPtr = searchFirstOccurence(n);
    DNodePtr retPtr = new DNode(locPtr->getData()); // pointer to be returned
    if (locPtr != NULL) {
        if (locPtr == myFirst) {
            deleteAtBeginning();
        } 
        else {
            DNodePtr lastPtr = myFirst;
            while (lastPtr->getNext() != myFirst)
                lastPtr = lastPtr->getNext();
            if (locPtr == lastPtr) {
                deleteAtEnd();
            } 
            else {
                deleteN(locPtr->getData());
            }
        }
        return retPtr;
    }

    return NULL; //if n not found
}

//--- Definition of class display()

ostream& CircularDoublyLinkedList::display(ostream& out) const {
    if (isEmpty())
        out << "Empty List";
    else {
        DNodePtr lPtr = myFirst; //pointer to the first node used to get to all the nodes of the list
        cout << "The list is: \n";
        for (int i = 0; i < mySize; i++) {
            out << lPtr->getData() << ((lPtr->getNext() != myFirst) ? " -> " : ".");
            //print the data of the nodes and print . after the last node
            lPtr = lPtr->getNext(); //get the next node
        }
    }
    return out; //return ostream object
}

//--- Definition of output operator

ostream& operator<<(ostream& out, const CircularDoublyLinkedList& l) {
    l.display(out); //call method display
    return out;
}
