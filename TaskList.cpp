#include "TaskList.h"
#include <iostream>
#include <string>

// TODO: Implement all member functions

// TODO: Initialize members
TaskList::TaskList() {
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}


// TODO: Free all allocated memory
TaskList::~TaskList() {
    freeList();
}


// TODO: Copy constructor logic
TaskList::TaskList(const TaskList& other) {
    // 1. determine resources used by src object
    // 2. allocated matching set of resources for target object
    head = nullptr;
    tail = nullptr;
    m_size = 0;
    
    // 3. copy contents of src object to target object
    copyList(other);
}


// TODO: Assignment operator logic
TaskList& TaskList::operator=(const TaskList& rhs) {
    // 0. check for aliasing
    if (this != &rhs) {
        // 1. free resources held by target object
        // 2. determine resources used by src object
        // 3. allocate matching set of resources for target object
        freeList();

        // 4. copy contents of src object to target object
        copyList(rhs);
    }
    
    // 5. return reference to target object
    return *this;
}


// TODO: Return true if list is empty
bool TaskList::empty() const {
    return (m_size == 0); 
}


// TODO: Return actual size
int TaskList::size() const {
    return m_size; 
}


// TODO: Add new node to back
void TaskList::addBack(const std::string& task) {
    Node* newNode = new Node;
    newNode->task = task;

	if (empty()) { // Check if list is empty
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

	m_size++; // Increment size
}


// TODO: Remove first node
bool TaskList::removeFront() {
    // Check if list is empty
    if (empty()) {
        return false;
    }

    Node* temp = head;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    }
    // List becomes empty after removal
    else {
        tail = nullptr;
    }

    delete temp;
	m_size--; // Decrement size

    return true; 
}


// TODO: Retrieve task at pos
bool TaskList::get(int pos, std::string& task) const {
    // Check if pos invalid
    if (pos < 0 || pos >= m_size) {
        return false;
    }

    Node* curr = head;
    int index = 0;

    while (curr != nullptr) {
        if (index == pos) {
            task = curr->task;
            return true;
        }

        curr = curr->next;
        index++;
    }

    return false; 
}


// TODO: Return index of task or -1
int TaskList::find(const std::string& task) const {
    Node* curr = head;
    int index = 0;

    while (curr != nullptr) {
        if (curr->task == task) {
            return index;
        }

        curr = curr->next;
        index++;
    }

    return -1; 
}


// TODO: Clear the list
void TaskList::clear() {
    freeList();
}


// TODO: Print all tasks to cerr
void TaskList::printAll() const {
    Node* curr = head;
    while (curr != nullptr) {
        std::cerr << curr->task << std::endl;
        curr = curr->next;
    }
}


// TODO: Deep copy all nodes from other
void TaskList::copyList(const TaskList& other) {
    Node* curr = other.head; // use .head instead of ->head for references
    while (curr != nullptr) {
        addBack(curr->task);
        curr = curr->next;
    }
}


// TODO: Free all nodes
void TaskList::freeList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }

    head = nullptr;
    tail = nullptr;
    m_size = 0;
}


// TODO: Return pointer to node at pos
TaskList::Node* TaskList::getNode(int pos) const {
    // Check if pos invalid
    if (pos < 0 || pos >= m_size) {
        return nullptr;
    }

    Node* curr = head;
    int index = 0;

    while (curr != nullptr) {
        if (index == pos) {
            return curr;
        }
        curr = curr->next;
        index++;
    }
    return nullptr; 
}
