/*Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks
Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.TASK 5
IMAGE PROCESSING TOOL
Build a tool that allows users to perform various image processing operations*/

#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed)
                std::cout << " [Completed]";
            std::cout << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todo;
    char choice;

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::cin.ignore();
                std::string taskDesc;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDesc);
                todo.addTask(taskDesc);
                break;
            }
            case '2':
                todo.viewTasks();
                break;
            case '3': {
                size_t index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                todo.markTaskCompleted(index);
                break;
            }
            case '4': {
                size_t index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todo.removeTask(index);
                break;
            }
            case '5':
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}

