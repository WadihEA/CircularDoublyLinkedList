/*
Title : Project1
Course : CSIS216 Fall 21-22
Version Information : Apache NetBeans 12.0
Date : 8 Nov  2021
Author: Wadih El Atie   A2010224
-- DNode.cpp--------------------------------------------------------------------
 
   This file implements DNode member functions.

-------------------------------------------------------------------------*/

#include "DNode.h"

//--- Definition of class constructor

DNode::DNode(ElementType n) {
    data = n;
    previous = NULL;
    next = NULL;
}

//--- Definition of getData()

ElementType DNode::getData() {
    return data;
}

//--- Definition of getNext()

DNodePtr DNode::getNext() {
    return next;
}

//--- Definition of getPrevious()

DNodePtr DNode::getPrevious() {
    return previous;
}

//--- Definition of setData()

void DNode::setData(ElementType n) {
    data = n;
}

//--- Definition of setNext()

void DNode::setNext(DNodePtr next) {
    this->next = next;
}

//--- Definition of setPrevious()

void DNode::setPrevious(DNodePtr previous) {
    this->previous = previous;
}

