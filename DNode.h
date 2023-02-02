/*
This programs aims to implement the given of the project.
Title : Project1
Course : CSIS216 Fall 21-22
Version Information : Apache NetBeans 12.0
Date : 8 nov  2021
Author: Wadih El Atie   A2010224

-- DNode.h ---------------------------------------------------------------------
 
  This header file defines the data type DNode a node with a data value and 
  two pointers
  Basic operations are:
     Constructor: set the data to a certain value and pointers to null 
     getData:  returns the data value of the Node
     getNext:  returns the pointer to the next node
     getPrevious: returns the pointer to the previous node
     setData:  sets the data value of the Node
     setNext:  set the pointer to the next node
     setPrevious: set the pointer to the previous node     
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef DNODE_H
#define DNODE_H

typedef int ElementType;

class DNode {
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    DNode(ElementType);
    /*----------------------------------------------------------------------
     Construct a DNode object.

     Precondition:  none
     Postcondition: A DNode object is constructed: data is set to the passed 
      value, both pointer point to null.
   -----------------------------------------------------------------------*/

    /***** get data operation *****/
    ElementType getData();
    /*----------------------------------------------------------------------
     Get the data value of the node.

     Precondition:  Node to be existing.
     Postcondition: Return the value the node holds.
   -----------------------------------------------------------------------*/

    /***** get next operation *****/
    DNode* getNext();
    /*----------------------------------------------------------------------
     Get the pointer to the next node.

     Precondition:  Node to be existing.
     Postcondition: Return a pointer that points to the next node.
   -----------------------------------------------------------------------*/

    /***** get previous operation *****/
    DNode* getPrevious();
    /*----------------------------------------------------------------------
     Get the pointer to the previous node.

     Precondition:  Node to be existing.
     Postcondition: Return a pointer that points to the previous node.
   -----------------------------------------------------------------------*/

    /***** set data operation *****/
    void setData(ElementType);
    /*----------------------------------------------------------------------
     Set the data of the node.

     Precondition:  Node to be existing, receive a data value.
     Postcondition: None.
   -----------------------------------------------------------------------*/

    /***** set next operation *****/
    void setNext(DNode*);
    /*----------------------------------------------------------------------
     Set the pointer to the next node.

     Precondition:  Node to be existing, receive a pointer to a node.
     Postcondition: None.
   -----------------------------------------------------------------------*/

    /***** set previous operation *****/
    void setPrevious(DNode*);
    /*----------------------------------------------------------------------
         Set the pointer to the previous node.

         Precondition:  Node to be existing, receive a pointer to a node.
         Postcondition: None.
       -----------------------------------------------------------------------*/
private:
    /******** Data Members ********/
    ElementType data; //data stored in the node
    DNode* previous; //a node pointer pointing to the previous node
    DNode* next; //a node pointer pointing to the next node
}; //--- end of List class
typedef DNode* DNodePtr;

#endif /* DNODE_H */

