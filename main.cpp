/*
Name: Emmanuel Rivas
ID: 
Class: Spring 2025, CSC 331H
Date:
Instructor: 
Project #1: Doubly Linked List

Purpose: To test the DoublyLinkedList class
Input: User's choice from the program's menu
Output: Menu of choices and results of user-selected operations
*/

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

namespace {
    // Displays the options menu
    int displayMenu() {
        int choice = 0;

        cout << "\n****************** MENU ******************\n"
            << "1. Add a number to the front of the list.\n"
            << "2. Add a number to the back of the list.\n"
            << "3. Search the list for a given number.\n"
            << "4. Delete a number from the list.\n"
            << "5. Check if the list is empty.\n"
            << "6. Get the number of items in the list.\n"
            << "7. Print the list.\n"
            << "8. Test the iterator.\n"
            << "9. Test the reverse iterator.\n"
            << "10. Quit the program.\n"
            << "******************************************\n";
        
        cout << "\nEnter your choice here: ";
        cin >> choice;

        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return choice;
    }
}

// Menu-driven program to test DoublyLinkedList class
int main() {
    DoublyLinkedList<int> list1;
    DoublyLinkedList<int> list2;
    DoublyLinkedList<int>::Iterator it = nullptr;
    int choice = 0;
    int item = 0;

    cout << "Hi! This program is designed to test a Doubly Linked List class.\n"
        << "A list for integers (list #1) has already been created.\n"
        << "To avoid issues with scope, the overloaded assignment operator\n"
        << "and copy constructor are tested before the program terminates.\n"
        << "\nTo get started, please select an option from the menu below and press enter.\n";

    choice = displayMenu();

    while (choice != 10) {
        switch (choice) {
        case 1:
            cout << "\nEnter the number to add to the front of the list: ";
            cin >> item;

            list1.insertFirst(item);

            cout << "\nThe number " << item << " has been inserted.\n";
            break;

        case 2:
            cout << "\nEnter the number to add to the back of the list: ";
            cin >> item;

            list1.insertLast(item);

            cout << "\nThe number " << item << " has been inserted.\n";
            break;

        case 3:
            cout << "\nEnter the number to search for: ";
            cin >> item;

            if (list1.searchItem(item))
                cout << "\nThe number " << item << " is in the list.\n";
            else
                cout << "\nThe number " << item << " is not in the list.\n";

            break;

        case 4:
            cout << "\nEnter the number to delete: ";
            cin >> item;

            list1.deleteItem(item);

            cout << "\nThe number " << item << " has been deleted from list #1.\n";
            break;

        case 5:
            cout << "\nList #1 is ";

            if (list1.isEmpty())
                cout << "empty.\n";
            else
                cout << "not empty.\n";

            break;

        case 6:
            cout << "\nThe number of items in the list is: " << list1.getLength() << "\n";
            break;

        case 7:
            cout << "\nPrinting out list #1...";
            list1.printList();

            break;

        case 8:
            cout << "\nUsing the iterator to print list #1: ";

            for (it = list1.begin(); it != list1.end(); it++)
                cout << *it << " ";

            cout << "\n";
            break;

        case 9: 
            cout << "\nUsing the reverse iterator to print list #1 in reverse: ";

            for (it = list1.revBegin(); it != list1.revEnd(); it--)
                cout << *it << " ";

            cout << "\n";
            break;

        case 10:
            break;

        default:
            cout << "\nInvalid choice! Please choose a number from the menu below and try again.\n";
            break;
        }

        choice = displayMenu();
    }

    // Testing the overloaded assignment operator (=)
    cout << "\nTesting the overloaded assignment operator:\n";

    list1.insertLast(2);
    list1.insertLast(88);
    list1.insertLast(19);

    cout << "Added the numbers 2, 88 and 19 to list #1.\n"
        << "\nList #1";

    list1.printList();

    list2 = list1;
    cout << "\nList #1 has been assigned to list #2.\n";

    list2.insertLast(55);
    cout << "Added the number 55 to the back of list #2.\n"
        << "\nList #2";

    list2.printList();

    // Testing the copy constructor
    cout << "\nTesting the copy constructor:\n"
        << "Initializing list #3 by copying list #2.\n";

    DoublyLinkedList<int>* list3 = nullptr;
    list3 = new DoublyLinkedList<int>(list2);

    cout << "\nList #3";
    list3->printList();

    delete list3;

    cout << "\nExiting program. Goodbye!\n";

    return 0;
}
