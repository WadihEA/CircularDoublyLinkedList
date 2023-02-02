/*
Title : Project1
Course : CSIS216 Fall 21-22
Version Information : Apache NetBeans 12.0
Date : 8 Nov  2021
Author: Wadih El Atie   A2010224

-- main.cpp--------------------------------------------------------------------
 
   This file is a program for testing class CircularDoublyLinkedList. 

-------------------------------------------------------------------------*/

#include "CircularDoublyLinkedList.h"

int menu(); //prototype of menu method


int main(int argc, char** argv) {
    int choice; //choice of the user
    int data; // data to be entered
    int pos; //position to be entered at 
    int insertBefore; //data to be inserted before
    //int first; //first number in the list
    CircularDoublyLinkedList origin;
    do {
        choice = menu(); //call menu method to get user choice
        switch (choice) {
            case 1: if (origin.isEmpty())
                    cout << "The List is Empty";
                else
                    cout << "The List is Not Empty";
                break;

            case 2: cout << "The size of the list is: " << origin.size() << endl;
                break;

            case 3: cout << "Enter the value to insert at the beginning of the list: " << endl;
                cin >> data;
                origin.insertAtBegining(data);
                //first = data;
                cout << origin << endl;
                break;

            case 4: cout << "Enter the value to insert at the end of the list: " << endl;
                cin >> data;
                origin.insertAtEnd(data);
                cout << origin << endl;
                break;

            case 5: cout << "Enter value to insert in the list: " << endl;
                cin >> data;
                cout << "Enter position to be inserted at: " << endl;
                cin >> pos;
                if (origin.insertAtPos(data, pos))
                    cout << origin << endl;
                else
                    cout << "Operation failed";
                break;

            case 6: cout << "Enter value to insert in the list: " << endl;
                cin >> data;
                cout << "Enter value to be inserted before: " << endl;
                cin >> insertBefore;
                if (origin.insertMBeforeN(data, insertBefore))
                    cout << origin << endl;
                else
                    cout << "Operation failed";
                break;

            case 7: cout << "Enter the value to delete from the list: " << endl;
                cin >> data;
                if (origin.deleteN(data))
                    cout << origin << endl;
                else
                    cout << "Operation failed";
                break;

            case 8: cout << "Enter the position to delete from the list: " << endl;
                cin >> pos;
                if (origin.deleteAtPos(pos))
                    cout << origin << endl;
                else
                    cout << "Operation failed";
                break;

            case 9: origin.deleteAtBeginning();
                cout << origin << endl;
                break;

            case 10: origin.deleteAtEnd();
                cout << origin << endl;
                break;

            case 11: cout << origin << endl;
                break;

            case 12: cout << "Exiting list" << endl;
                break;

            default: cout << "\n Invalid selection";
                break;

        }
        cout << "\n";
    } while (choice != 12); //keep showing menu if choice is not to exit
    /*
     
     this part is not working
    
    DNodePtr x = origin.searchFirstOccurence(first);
    cout << "\n first is " << x->getData() << endl;
    ElementType nb;
    CircularDoublyLinkedList even;
    CircularDoublyLinkedList odd;
    
    for(int i = 0; i < origin.size(); i++){
        if((x->getData())%2 == 0) {          
            nb = origin.cutN((origin.searchFirstOccurence(x->getData()))->getData())->getData();
            even.insertAtBegining(nb);
        }
        else if((x->getData())%2 != 0){
            nb = origin.cutN((origin.searchFirstOccurence(x->getData()))->getData())->getData();
            odd.insertAtBegining(nb);
        }
        x = x->getNext();
        cout << "\n first is " << x->getData() << endl;
    }
    cout << "orig: " <<origin << endl;
    cout << "odd: " <<odd << endl;
    cout << "even: " <<even << endl;
    */
    return 0;
}

int menu() {
    int selection; //user choice
    do {
        cout << "Menu";
        cout << "\n================================================";
        cout << "\n 1 - Test if the list is empty\n";
        cout << "\n 2 - Get the size of the list\n";
        cout << "\n 3 - Insert at the beginning of the list\n";
        cout << "\n 4 - Insert at the end of the list\n";
        cout << "\n 5 - Insert a value at a certain position\n";
        cout << "\n 6 - Insert a value before another value\n";
        cout << "\n 7 - Delete the node with a certain value\n";
        cout << "\n 8 - Delete the node at a certain position\n";
        cout << "\n 9 - Delete a node from the beginning of the list\n";
        cout << "\n 10 - Delete a node form the end of the list\n";
        cout << "\n 11 - Display the list\n";
        cout << "\n 12 - To exit\n";
        cout << "\nPlease choose a number from the below menu \n";
        cin >> selection;
    } while (selection < 1 || selection > 12); //keep showing menu if choice is not valid

    return selection; //return choice
}

