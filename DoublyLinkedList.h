/*
Name: Emmanuel Rivas
ID: 15310887
Class: Spring 2025, CSC 331H
Date:
Instructor: Prof. Salvati
Project #1: Doubly Linked List

Purpose: DoublyLinkedList class header file
Input: None
Output: None
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Structure declaration for nodes
template <typename T>
struct Node {
    T info;
    Node<T>* next;
    Node<T>* prev;

    // Constructor
    Node(const T& item) : info(item), next(nullptr), prev(nullptr) { }
};

// DoublyLinkedList class declaration
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* first;
    Node<T>* last;
    int length;

    // Copies another list
    void copy(const DoublyLinkedList<T>&);

    // Deletes the entire list
    void destroy();

public:
    // Constructor
    DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<T>&);

    // Overloads the assignment operator (=)
    const DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);

    // Searches the list for a given item
    bool searchItem(T) const;

    // Inserts a given item at the front of the list
    bool insertFirst(T);

    // Inserts a given item at the end of the list
    bool insertLast(T);

    // Deletes a given item from the list
    void deleteItem(T);

    // Checks if the list is empty
    bool isEmpty() const;

    // Returns the length of the list
    int getLength() const;

    // Displays the list
    void printList() const;

    // DoublyLinkedList class destructor
    ~DoublyLinkedList();

    // Iterator class declaration
    class Iterator {
    private:
        Node<T>* current;

    public:
        // Constructor
        Iterator();

        // Overloaded constructor
        Iterator(Node<T>*);

        // Overloads the dereference operator (*)
        T& operator*() const;

        // Overloads the arrow operator (->)
        T* operator->() const;

        // Overloads the pre-increment operator (++T)
        Iterator operator++();

        // Overloads the pre-decrement operator (--T)
        Iterator operator--();

        // Overloads the post-increment operator (T++)
        Iterator operator++(int);

        // Overloads the post-decrement operator (T--)
        Iterator operator--(int);

        // Overloads the equality operator (==)
        bool operator==(const Iterator&) const;

        // Overloads the inequality operator (!=)
        bool operator!=(const Iterator&) const;

        // Iterator class destructor
        ~Iterator();
    };

    // Returns the starting point for traversing the list
    Iterator begin();

    // Returns the endpoint for traversing the list
    Iterator end();

    // Returns the starting point for traversing the list in reverse
    Iterator revBegin();

    // Returns the endpoint for traversing the list in reverse
    Iterator revEnd();
};

#endif
