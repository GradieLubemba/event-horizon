#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure pour représenter une tâche
struct Task {
    int id;
    string name;
    bool completed;
};

// Afficher toutes les tâches
void displayTasks(const vector<Task>& tasks) {
    cout << "\n===== Group Task List =====\n";
    
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (const auto& task : tasks) {
        cout << "ID: " << task.id 
             << " | Task: " << task.name
             << " | Status: " 
             << (task.completed ? "Completed" : "Pending")
             << endl;
    }
}

// Ajouter une tâche
void addTask(vector<Task>& tasks, int& nextId) {
    string name;
    
    cout << "Enter task name: ";
    getline(cin, name);

    Task newTask = {nextId, name, false};
    tasks.push_back(newTask);
    nextId++;

    cout << "Task added successfully!\n";
}

// Marquer une tâche comme complétée
void completeTask(vector<Task>& tasks) {
    int id;
    cout << "Enter task ID to complete: ";
    cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Task marked as completed!\n";
            return;
        }
    }

    cout << "Task not found.\n";
}

int main() {
    vector<Task> tasks;
    int choice;
    int nextId = 1;

    do {
        cout << "\n===== Event Horizon System =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // important for getline

        switch (choice) {
            case 1:
                addTask(tasks, nextId);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
