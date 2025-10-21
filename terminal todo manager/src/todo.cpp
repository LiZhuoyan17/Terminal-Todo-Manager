#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "todo.h"
using namespace std;

vector<Task> load_tasks(const string& filename) {
    vector<Task> tasks;
    ifstream file(filename);
    if (!file.is_open()) {
        return tasks; // File doesn't exist, return empty task list
    }
    Task t;
    while (file >> t.id >> t.is_done) {
        file.ignore();
        getline(file, t.content);
        getline(file, t.creat_time);
        tasks.push_back(t);
    }
    file.close();
    return tasks;
}

void save_tasks(const vector<Task>& tasks, const string& file_path) {
    ofstream file(file_path);
    if (!file.is_open()) {
        cerr << "Failed to open file for saving" << endl;
        return;
    }
    for (const auto& t : tasks) {
        file << t.id << " " << t.is_done << endl;
        file << t.content << endl;
        file << t.creat_time << endl;
    }
    file.close();
    cout << "Operation completed successfully" << endl;
}

void add_task(vector<Task>& tasks, const string& content) {
    Task new_task;
    new_task.id = tasks.empty() ? 1 : tasks.back().id + 1;
    new_task.content = content;
    new_task.is_done = false;
    time_t now = time(nullptr);
    new_task.creat_time = ctime(&now);
    new_task.creat_time.pop_back();
    tasks.push_back(new_task);
    cout << "Task added: " << content << endl;
}

void list_task(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks" << endl;
        return;
    }
    cout << "\n============================= TODO LIST ==============================\n\n";
    for (const auto& t : tasks) {
        cout << "ID:" << setw(3) << left
            << t.id << " | " << (t.is_done ? "[*] " : "[ ] ")
            << t.content
            << "\t\t\t | Created: " << t.creat_time << endl;
    }
    cout << "\n======================================================================\n";
}

void mark_task_done(vector<Task>& tasks, int task_id) {
    for (auto& t : tasks) {
        if (t.id == task_id) {
            t.is_done = true;
            cout << "Task " << task_id << " marked as completed!\n";
            return;
        }
    }
    cout << "Task with ID " << task_id << " not found\n";
}

void remove_task(vector<Task>& tasks, int task_id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == task_id) {
            cout << "Task deleted: " << it->content << endl;
            tasks.erase(it);
            return;
        }
    }
    cout << "Task with ID " << task_id << " not found\n";
}