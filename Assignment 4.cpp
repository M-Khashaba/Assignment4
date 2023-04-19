#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
    int numIntegers;
    vector<int> integers;

    // Prompt user to enter number of integers
    cout << "Enter the number of integers: ";
    cin >> numIntegers;

    // Prompt user to enter the integers and store them in a vector
    cout << "Enter " << numIntegers << " integers: ";
    for (int i = 0; i < numIntegers; i++)
    {
        int integer;
        cin >> integer;
        integers.push_back(integer);
    }

    // Create a linked list from the vector of integers
    LinkedList linkedList;
    linkedList.createListFromVector(integers);

    int firstValue, secondValue;
    // Prompt user to enter two integers
    cout << "Enter the first integer: ";
    cin >> firstValue;
    cout << "Enter the second integer: ";
    cin >> secondValue;

    // Insert the second integer after the first integer in the linked list
    linkedList.insertAfter(firstValue, secondValue);

    // Print the contents of the linked list
    cout << "Linked list: ";
    linkedList.printList();

    // Get the sum of all the nodes in the linked list
    int sum = linkedList.getSum();
    cout << "Sum of all nodes: " << sum << endl;

    return 0;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::addNode(int value)
{
    // Create a new node with the given value and add it to the end of the linked list
    Node* newNode = new Node;
    newNode->value = value;
    newNode->count = 1;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeNode(int value)
{
    Node* current = head;
    Node* prev = nullptr;

    // Traverse the linked list until the node with the given value is found
    while (current != nullptr && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    // If the node was not found, return
    if (current == nullptr)
    {
        return;
    }

    // If the node has a count greater than 1, decrement the count and return
    if (current->count > 1)
    {
        current->count--;
        return;
    }

    // If the node is the head, update the head to point to the next node
    if (prev == nullptr)
    {
        head = current->next;
    }
    else {
        // Otherwise, update the previous node's next pointer to skip the current node
        prev->next = current->next;
    }

    // Delete the current node
    delete current;
}

void LinkedList::printList() const
{
    // Traverse the linked list and print each node's value and count
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->value << "(" << current->count << ") ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::createListFromVector(const vector<int>& v)
{
    // Loop through the vector of integers and add each unique value to the linked list
    for (int i = 0; i < v.size(); i++)
    {
        int value = v[i];
        Node* current = head;
        bool found = false;
        // Check if the current value already exists in the linked list and increment its count if it does
        while (current != nullptr)
        {
            if (current->value == value)
            {
                current->count++;
                found = true;
                break;
            }
            current = current->next;
        }
        // If the value doesn't exist in the linked list, add it as a new node
        if (!found) {
            addNode(value);
        }
    }
}

void LinkedList::insertAfter(int firstValue, int secondValue)
{
    Node* current = head;
    // Loop through the linked list to find the node with the first value
    while (current != nullptr)
    {
        // If the node is found, add a new node with the second value after it
        if (current->value == firstValue)
        {
            Node* newNode = new Node;
            newNode->value = secondValue;
            newNode->count = 1;
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
        // If the node isn't found, move on to the next node in the linked list
        else {
            current = current->next;
        }
    }
}

int LinkedList::getSum() const
{
    Node* current = head;
    int sum = 0;
    // Loop through the linked list and add up the values multiplied by their counts
    while (current != nullptr)
    {
        sum += current->value * current->count;
        current = current->next;
    }
    // Return the total sum of all nodes in the linked list
    return sum;
}
