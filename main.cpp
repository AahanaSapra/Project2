#include "TaskList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    // TODO: Add test cases or interactively add/remove items
    cerr << "Run your tests here." << endl;

    // Test Case 1: Initial State Verification
    {
        TaskList list;
        assert(list.empty() == true);
        assert(list.size() == 0);
        assert(list.find("Task") == -1);

        string temp = "temp";
        assert(list.get(0, temp) == false);
        assert(temp == "temp");
        assert(list.removeFront() == false);
    }

    // Test Case 2: Daily Task Queue
    {
        TaskList list;
        list.addBack("Reply to client emails");
        assert(list.empty() == false);
        assert(list.size() == 1);

        list.printAll();

        assert(list.removeFront() == true);
        assert(list.empty() == true);
        assert(list.size() == 0);

        list.printAll();
    }


    // Test Case 3: Student Assignment Tracker
    {
        TaskList list;
        list.addBack("Finish history essay");
        list.addBack("Study for math quiz");
        assert(list.size() == 2);

        list.printAll();

        assert(list.find("Finish history essay") == 0);
        assert(list.find("Study for math quiz") == 1);
        assert(list.find("Task") == -1);

        string task = "";
        assert(list.get(0, task) == true);
        assert(task == "Finish history essay");

        assert(list.get(1, task) == true);
        assert(task == "Study for math quiz");

        assert(list.get(2, task) == false);
        assert(list.get(-1, task) == false);
    }
	

    // Test Case 4: Restaurant Kitchen Prep
    {
        TaskList list;
        list.addBack("Chop vegetables");
        list.addBack("Marinate chicken");
        assert(list.size() == 2);

        list.printAll();

        assert(list.removeFront() == true);
		assert(list.size() == 1);

        list.printAll();

        string task = "";
        assert(list.get(0, task) == true);
        assert(task == "Marinate chicken");

        list.clear();
        assert(list.empty() == true);
        assert(list.size() == 0);

        list.printAll();
    }
      

    // Test Case 5: Personal Productivity Bot
    {
        TaskList list;
        list.addBack("Task A");
        list.addBack("Task B");

        TaskList copyList(list);
        assert(copyList.size() == 2);
        assert(copyList.find("Task A") == 0);

        list.addBack("Task C");
        assert(list.size() == 3);
        assert(copyList.size() == 2);

        TaskList assignedList;
        assignedList.addBack("Task 1");
        assignedList.addBack("Task 2");

        assignedList = list; 
        assert(assignedList.size() == 3);
        assert(assignedList.find("Task C") == 2);

        assignedList = assignedList;
        assert(assignedList.size() == 3);
    }

    cerr << "All tests passed!" << endl;

    return 0;
}
