#include <iostream>
#include <string>
#include "todo.h"
using namespace std;

// Define task file path as constant
const string TASK_FILE = "tasks.in";

string get_program_name(const string& path) {
    // Find last path separator (compatible with Windows and Linux)
    size_t pos = path.find_last_of("/\\");
    if (pos != string::npos) {
        // Extract the part after the separator (pure filename)
        return path.substr(pos + 1);
    }
    // If no path separator found, return original string
    return path;
}

int main(int argc, char* argv[]) {
    vector<Task> tasks = load_tasks(TASK_FILE);
    string name = get_program_name(argv[0]);
    
    if (argc < 2) { // Insufficient parameters
        cout << "Usage: " << name << " [command] [arguments]\n";
        cout << "Commands: add \"task content\" | list | done taskID | remove taskID\n";
        return 1;
    }
    
    string command = argv[1];
    
    if (command == "add" && argc == 3) {
        add_task(tasks, argv[2]);
        save_tasks(tasks, TASK_FILE);
        cout << "Task added successfully.\n";
    }
    else if (command == "list") {
        list_task(tasks);
    }
    else if (command == "done" && argc == 3) {
        int task_id = stoi(argv[2]);
        mark_task_done(tasks, task_id);
        save_tasks(tasks, TASK_FILE);
        cout << "Task " << task_id << " marked as done.\n";
    }
    else if (command == "remove" && argc == 3) {
        int task_id = stoi(argv[2]);
        remove_task(tasks, task_id);
        save_tasks(tasks, TASK_FILE);
        cout << "Task " << task_id << " removed successfully.\n";
    }
    else {
        cout << "Invalid command! Please use correct format: ./todo [add/list/done/remove].\n";
        return 1;
    }
    
    return 0;
}
