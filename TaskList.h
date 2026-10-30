#ifndef TASKLIST_H
#define TASKLIST_H

// TODO: Define the TaskList class as specified in spec.txt
class TaskList {
public:
	TaskList(); // Constructor

	// Rule of 3
	~TaskList(); // Destructor
	TaskList(const TaskList& other); // Copy Constructor
	TaskList& operator=(const TaskList& rhs); // Assignment Operator

	bool empty() const;
	int size() const;
	void addBack(const std::string& task);
	bool removeFront();
	bool get(int pos, std::string& task) const;
	int find(const std::string& task) const;
	void clear();
	void printAll() const;

private:
	// Node Struct
	struct Node {
		std::string task;

		Node* next;
		Node* prev;
	};

	// Member Variables
	Node* head;
	Node* tail;

	int size;

	// Helper Functions
	void copyList(const TaskList& other);
	void freeList();
	Node* getNode(int pos) const;

};

#endif // TASKLIST_H
