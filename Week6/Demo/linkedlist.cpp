#include <iostream>
#include "linkedlist.hpp"

// constructor: tells the computer how to build your custom data type
Node::Node(int passed_value) {
    // setting its own "value" variable to the passed_value
    // 'this' is how an object refers to itself
    this->value = passed_value;
    this->next = nullptr;
}

// constructor: initializes an empty linked list
LinkedList::LinkedList() {
    this->size_ = 0;
    this->head_ = nullptr;
}

void LinkedList::InsertNode(const int value) {

    // create a new node on the heap
    Node* new_node = new Node(value);

    // if the list is empty, the new node becomes the head
    if (head_ == nullptr) {
        head_ = new_node;
        size_++;
        return;
    }

    // start at the beginning of the list
    Node* current_node = head_;

    // move until we reach the final node
    while (current_node->next != nullptr) {
        current_node = current_node->next;
    }

    // connect the final node to the new node
    current_node->next = new_node;

    // increase the number of nodes in the list
    size_++;
}

void LinkedList::PrintValues() const {

    Node* current_node = head_;

    // print every value in the list
    while (current_node != nullptr) {
        std::cout << current_node->value << " -> ";
        current_node = current_node->next;
    }

    std::cout << "nullptr" << std::endl;
}

// destructor: frees all dynamically allocated nodes
LinkedList::~LinkedList() {

    Node* current_node = head_;

    while (current_node != nullptr) {

        Node* next_node = current_node->next;

        delete current_node;

        current_node = next_node;
    }

    head_ = nullptr;
    size_ = 0;
}

// temporary main function used to test the linked list
int main() {

    LinkedList list;

    list.InsertNode(10);
    list.InsertNode(20);
    list.InsertNode(30);

    list.PrintValues();

    return 0;
}