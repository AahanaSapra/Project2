#include "TaskList.h"
#include <iostream>

// TODO: Implement all member functions

TaskList::TaskList() {
    // TODO: Initialize members
    head = nullptr;
    tail = nullptr;
    size = 0;
}

TaskList::~TaskList() {
    // TODO: Free all allocated memory
    freeList();
}

TaskList::TaskList(const TaskList& other) {
    // TODO: Copy constructor logic
    // 1. determine resources used by src object
    // 2. allocated matching set of resources for target object
    head = nullptr;
    tail = nullptr;
    size = 0;
    
    // 3. copy contents of src object to target object
    copyList(other);
}

TaskList& TaskList::operator=(const TaskList& rhs) {
    // TODO: Assignment operator logic
    // 0. check for aliasing
    if (this != &rhs) {
        // 1. free resources held by target object
        // 2. determine resources used by src object
        // 3. allocate matching set of resources for target object
        // 4. copy contents of src object to target object
        freeList();

        copyList(rhs);
    }
    
    // 5. return reference to target object
    return *this;
}

bool TaskList::empty() const {
    return (size == 0); // TODO: Return true if list is empty
}

int TaskList::size() const {
    return size; // TODO: Return actual size
}

void TaskList::addBack(const std::string& task) {
    // TODO: Add new node to back
    Node* newNode = new Node(task, nullptr, nullptr);

    // Empty list
    if (empty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size++;
}

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
    size--;

    return true; // TODO: Remove first node
}

bool TaskList::get(int pos, std::string& task) const {
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

    return false; // TODO: Retrieve task at pos
}

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

    return -1; // TODO: Return index of task or -1
}

void TaskList::clear() {
    // TODO: Clear the list
    freeList();
}

void TaskList::printAll() const {
    // TODO: Print all tasks to cerr
    Node* curr = head;
    while (curr != nullptr) {
        std::cerr << curr->task << std::endl;
        curr = curr->next;
    }
}

void TaskList::copyList(const TaskList& other) {
    // TODO: Deep copy all nodes from other
    Node* curr = other.head; // use .head instead of ->head for references
    while (curr != nullptr) {
        addBack(curr->task);
        curr = curr->next;
    }
}

void TaskList::freeList() {
    // TODO: Free all nodes
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

TaskList::Node* TaskList::getNode(int pos) const {
    // Invalid pos
    if (pos < 0 || pos >= size) {
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
    return nullptr; // TODO: Return pointer to node at pos
}
