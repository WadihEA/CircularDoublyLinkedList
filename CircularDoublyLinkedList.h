/* 
Title : Project1
Course : CSIS216 Fall 21-22
Version Information : Apache NetBeans 12.0
Date : 8 Nov  2021
Author: Wadih El Atie   A2010224

-- CircularDoublylinkedList.h --------------------------------------------------
 
  This header file defines the data type Circular Doubly linked List for 
  processing lists.
  Basic operations are:
     Constructor
     Copy constructor
     Destructor    
     Clear:   Deletes all nodes from the list but keeps the object in the memory
     isEmpty:  Check if list is empty
     size: get the number of nodes in the list
     searchFirstOccurence: return a pointer to the first node that holds a specific value
     insertAtBegining:   Insert a node at the beginning of the list
     insertAtEnd:   Insert a node at the end of the list
     insertAtPos:   Insert a node at a certain position in the list
     insertMBeforeN: Insert a node that contains m before the first node containing n
     deleteAtBeginnig: delete the node at the beginning of the list
     deleteAtEnd: delete the node at the end of the list
     deleteAtPos:   delete a node at a certain position in the list
     deleteN: delete the first node that contains n as data
     cutN: cut the first node that contains n as data returning a pointer to it
     display: displays the list
     << :      Output operator
-------------------------------------------------------------------------*/
#include "DNode.h"
#include <cassert>

#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

class CircularDoublyLinkedList {
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    CircularDoublyLinkedList();
    /*----------------------------------------------------------------------
    Construct a Circular Doubly Linked List object.

    Precondition:  None
    Postcondition: An empty Circular Doubly Linked List object has been 
       constructed; mySize is 0 and myFirst Null.
  -----------------------------------------------------------------------*/

    /***** Copy constructor *****/
    CircularDoublyLinkedList(const CircularDoublyLinkedList&);
    /*----------------------------------------------------------------------
     Construct a copy of a Circular Doubly Linked List object.

     Precondition:  A copy of a Circular Doubly Linked List is needed; it is a 
        const reference parameter. 
     Postcondition: A copy of Circular Doubly Linked List has been constructed.
   -----------------------------------------------------------------------*/
    
    /***** Class destructor *****/
    virtual ~CircularDoublyLinkedList();
    /*----------------------------------------------------------------------
     Destroys a Circular Doubly Linked List object.

     Precondition:  The life of a List object is over.
     Postcondition: The memory allocated by the constructor for the nodes has 
        been returned to the heap.
   -----------------------------------------------------------------------*/

    /***** Clear operationr *****/
    void clear();
    /*----------------------------------------------------------------------
     Delete the nodes of the Doubly Linked List object but keeps the object in 
        the memory.

     Precondition:  None.
     Postcondition: The memory allocated by the constructor for the nodes has 
        been returned to the heap but the object remain in the memory.
   -----------------------------------------------------------------------*/

    /***** is empty operation *****/
    bool isEmpty() const;
    /*----------------------------------------------------------------------
     Check if a list is empty.

     Precondition:  None
     Postcondition: true is returned if the list is empty, false if not.
   -----------------------------------------------------------------------*/

    /***** Size operation *****/
    int size() const;
    /*----------------------------------------------------------------------
     Get the number of node the list holds.

     Precondition:  None
     Postcondition: return the number of nodes as an int variable.
   -----------------------------------------------------------------------*/

    /***** Search first Occurence operation *****/
    DNodePtr searchFirstOccurence(const ElementType) const;
    /*----------------------------------------------------------------------
     Get the pointer of the first node holding a certain value.

     Precondition:  None.
     Postcondition: return a pointer to the first node holding a certain value. 
        Return Null if no node holds that value.
   -----------------------------------------------------------------------*/

    /***** insert at beginning operation *****/
    void insertAtBegining(const ElementType);
    /*----------------------------------------------------------------------
     Create a node holding a certain value and insert it at the beginning of 
        the list.

     Precondition:  Receive the certain value to be put in the node.
     Postcondition: Insert the node at the beginning of the list, increment size.
   -----------------------------------------------------------------------*/

    /***** insert at end operation *****/
    void insertAtEnd(const ElementType);
    /*----------------------------------------------------------------------
     Create a node holding a certain value and insert it at the end of 
        the list.

     Precondition:  Receive the certain value to be put in the node.
     Postcondition: Insert the node at the end of the list, increment size.
   -----------------------------------------------------------------------*/

    /***** insert at pos operation *****/
    bool insertAtPos(const ElementType, int);
    /*----------------------------------------------------------------------
     Create a node holding a certain value and insert it at a certain position  
        in the list.

     Precondition:  Receive the certain value to be put in the node at the position.
     Postcondition: Insert the node at correct position  the list, increment size.
        Return true if operation was a success false if not(Position not within 
        the range of the list).  
   -----------------------------------------------------------------------*/

    /***** insert m before n operation *****/
    bool insertMBeforeN(const ElementType, const ElementType);
    /*----------------------------------------------------------------------
     Create a node holding a certain value and insert it before a specific node  
        in the list.

     Precondition:  Receive the certain value to be put in the node and the 
        value of the node that it should be inserted before.
     Postcondition: Insert the node before the node containing a certain value, 
        increment size.Return true if operation was a success false if not(list 
        empty or node that holds the certain value was not found).
   -----------------------------------------------------------------------*/

    /***** delete at beginning operation *****/
    void deleteAtBeginning();
    /*----------------------------------------------------------------------
     Delete the node at the beginning of the list.

     Precondition:  List no empty.
     Postcondition: delete the first node of the list, decrement size.
   -----------------------------------------------------------------------*/

    /***** delete at end operation *****/
    void deleteAtEnd();
    /*----------------------------------------------------------------------
     Delete the node at the end of the list.

     Precondition:  List no empty.
     Postcondition: delete the last node of the list, decrement size.
   -----------------------------------------------------------------------*/

    /***** delete at pos operation *****/
    bool deleteAtPos(int);
    /*----------------------------------------------------------------------
     Delete the node at a certain position of the list.

     Precondition:  Receive the position to delete.
     Postcondition: delete the node at the certain position, decrement size.
     Return true if operation was a success false otherwise(list empty or 
        position out of range)
   -----------------------------------------------------------------------*/

    /***** delete n operation *****/
    bool deleteN(const ElementType);
    /*----------------------------------------------------------------------
     Delete the first node holding a certain value.

     Precondition:  Receive the value to delete, list not empty.
     Postcondition: delete the node holding a certain value, decrement size.
     Return true if operation was a success false otherwise(value not found)
   -----------------------------------------------------------------------*/

    /***** cut n operation *****/
    DNodePtr cutN(const ElementType);
    /*----------------------------------------------------------------------
     cut the first node holding a certain value.

     Precondition:  Receive the value to cut, list not empty.
     Postcondition: cut the node holding a certain value, decrement size.
     Return a pointer to the cut if the value was found null otherwise.
   -----------------------------------------------------------------------*/

    /***** display *****/
    ostream& display(ostream&) const;
    /*----------------------------------------------------------------------
     Display a list.

     Precondition: Receive an ostream object. 
     Postcondition: display the values of te nodes of the list in order. 
   -----------------------------------------------------------------------*/


private:
    /******** Data Members ********/
    int mySize; //size of the list; number of nodes in the list
    DNodePtr myFirst; // pointer to the first node of the list
}; //--- end of Circular doubly linked List class

//------ Prototype of output operator
ostream& operator<<(ostream&, const CircularDoublyLinkedList&);
#endif /* CIRCULARDOUBLYLINKEDLIST_H */

