/*
Name: Emmanuel Rivas
ID: 
Class: Spring 2025, CSC 331H
Date:
Instructor:
Project #1: Doubly Linked List

Purpose: DoublyLinkedList class implementation file
Input: None
Output: None
*/

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

// DoublyLinkedList class methods' implementation:

// DoublyLinkedList constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : length(0), first(nullptr), last(nullptr) { }

// DoublyLinkedList copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : length(0), first(nullptr), last(nullptr) {
    copy(other);
}

// Overloads the assignment operator (=)
template <typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {    
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

// Searches the list for a given item
template <typename T>
bool DoublyLinkedList<T>::searchItem(T item) const {
    Node<T>* temp = nullptr;
    bool found = false;

    temp = first;

    while ((!found) && (temp != nullptr)) {
        if (temp->info == item) 
            found = true;
        else
            temp = temp->next;
    }

    return found;
}

// Inserts a given item at the front of the list
template <typename T>
bool DoublyLinkedList<T>::insertFirst(T newItem) {
    Node<T>* newNode = nullptr;
    bool inserted = false;

    newNode = new Node<T>(newItem);

    if (first == nullptr) {
        first = last = newNode;
    }
    else {
        first->prev = newNode;
        newNode->next = first;
        first = newNode;
    }

    inserted = true;
    length++;

    return inserted;
}

// Inserts a given item at the end of the list
template <typename T>
bool DoublyLinkedList<T>::insertLast(T newItem) {
    Node<T>* newNode = nullptr;
    bool inserted = false;

    newNode = new Node<T>(newItem);

    if (first == nullptr) {
        first = last = newNode;
    }
    else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    inserted = true;
    length++;

    return inserted;
}

// Deletes an item from the list
template <typename T>
void DoublyLinkedList<T>::deleteItem(T item) {
    Node<T>* temp = nullptr;
    temp = first;

    if (temp == nullptr) {  // Empty list check
        cout << "\nCannot delete, the list is empty!\n";
    }
    else if (temp->info == item) {  // Item to be deleted is the first node
        first = first->next;

        if (first == nullptr)
            last = nullptr;
        else
            first->prev = nullptr;

        length--;
        delete temp;
    }
    else {  // Check other nodes after the first
        while (temp != nullptr) {
            if (temp->info == item)
                break;
            else
                temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "\nItem to be deleted is not in the list!\n";
        }
        else {
            temp->prev->next = temp->next;

            if (temp == last)
                last = last->prev;
            else
                temp->next->prev = temp->prev;

            length--;
            delete temp;
        }
    }

    return;
}

// Checks if the list is empty
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    bool check = false;

    if (first == nullptr) check = true;
    
    return check;
}

// Returns the length of the list
template <typename T>
int DoublyLinkedList<T>::getLength() const { return length; }

// Displays the list
template <typename T>
void DoublyLinkedList<T>::printList() const {
    if (first == nullptr) {
        cout << "\nThe list is empty, nothing to print!\n";
    }
    else {
        Node<T>* current = first;
        cout << "\nList contents: ";

        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }

        cout << "\n";
    }

    return;
}

// Copies another list
template <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& other) {
    Node<T>* temp = nullptr;
    temp = other.first;

    while (temp != nullptr) {
        insertLast(temp->info);
        temp = temp->next;
    }

    return;
}

// Deletes the entire list
template <typename T>
void DoublyLinkedList<T>::destroy() {
    Node<T>* temp = nullptr;

    while (first != nullptr) {
        temp = first;
        first = first->next;

        delete temp;
    }

    last = nullptr;
    length = 0;

    return;
}

// DoublyLinkedList destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    destroy();
}


// ***********************************************************************************
// Iterator class implementation:
 
// Iterator constructor
template <typename T>
DoublyLinkedList<T>::Iterator::Iterator() : current(nullptr) { }

// Iterator overloaded constructor
template <typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node<T>* ptr) : current(ptr) { }

// Overloads the dereference operator (*)
template <typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
    T& temp = current->info;
    
    if (current == nullptr) throw runtime_error("\nAttempted to dereference a null pointer.\n");
        
    return temp;
}

// Overloads the arrow operator (->)
template <typename T>
T* DoublyLinkedList<T>::Iterator::operator->() const {
    T* ptr = nullptr;
    ptr = &current->info;
    
    return ptr;
}

// Overloads the pre-increment operator (++T)
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++() {
    Iterator temp = nullptr;

    if (current != nullptr) current = current->next;

    temp = *this;
    return temp;
}

// Overloads the pre-decrement operator (--T)
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--() {
    Iterator temp = nullptr;

    if (current != nullptr) current = current->prev;

    temp = *this;
    return temp;
}

// Overloads the post-increment operator (T++)
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
    Iterator temp = nullptr;
    temp = *this;

    if (current != nullptr) current = current->next;

    return temp;
}

// Overloads the post-decrement operator (T--)
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
    Iterator temp = nullptr;
    temp = *this;

    if (current != nullptr) current = current->prev;

    return temp;
}

// Overloads the equality operator (==)
template <typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    bool isEqual = false;

    if (current == other.current) isEqual = true;

    return isEqual;
}

// Overloads the inequality operator (!=)
template <typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    bool isEqual = false;

    if (current != other.current) isEqual = true;

    return isEqual;
}

// Iterator class destructor
template <typename T>
DoublyLinkedList<T>::Iterator::~Iterator() { }


// ***********************************************************************************
// DoublyLinkedList class iteration methods' implementation:

// Returns the starting point for traversing the list
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
    Iterator it = nullptr;
    it = Iterator(first);

    return it;
}

// Returns the endpoint for traversing the list
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
    Iterator it = nullptr;
    it = Iterator(nullptr);

    return it;
}

// Returns the starting point for traversing the list in reverse
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::revBegin() {
    Iterator it = nullptr;
    it = Iterator(last);

    return it;
}

// Returns the endpoint for traversing the list in reverse
template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::revEnd() {
    Iterator it = nullptr;
    it = Iterator(nullptr);

    return it;
}


// ***********************************************************************************

// Declaration to prevent unresolved external symbol(s) linker error (LNK2019)
template class DoublyLinkedList<int>;
