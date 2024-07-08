#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// To-do list class
class ToDoList {
private:
    vector<Task> tasks;

public:
    
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    
    void removeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task index!" << endl;
        } else {
            cout << "Task removed: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        }
    }

    
    void completeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task index!" << endl;
        } else {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        }
    }

    
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
            }
        }
    }
};


int main() {
    ToDoList myList;

    // Example usage
    myList.addTask("Finish homework");
    myList.addTask("Go grocery shopping");
    myList.addTask("Call mom");

    myList.displayTasks();

    myList.completeTask(1);
    myList.removeTask(2);

    myList.displayTasks();

    return 0;
}

