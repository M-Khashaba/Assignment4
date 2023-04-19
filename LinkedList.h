#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;

// Define a struct to hold each node in the linked list
struct Node
{
    int value;       // value stored in the node
    int count;       // optional field to keep count of occurrences of the value
    Node* next;      // pointer to the next node in the list
};

class LinkedList
{
public:
    // Constructor and destructor for the LinkedList class
    LinkedList();
    ~LinkedList();

    // Add and remove nodes from the list
    void addNode(int value);
    void removeNode(int value);

    // Print the list and create a list from a vector
    void printList() const;
    void createListFromVector(const vector<int>& v);

    // Insert a node after a specified value and get the sum of all values in the list
    void insertAfter(int firstValue, int secondValue);
    int getSum() const;

private:
    Node* head;      // pointer to the first node in the list
};

#endif // LINKEDLIST_H
