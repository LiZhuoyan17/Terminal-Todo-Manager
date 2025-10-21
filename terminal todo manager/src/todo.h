#pragma once
#include<string>
#include<vector>
using namespace std;
struct Task {
	int id;
	string content;
	bool is_done;
	string creat_time;
};
vector <Task> load_tasks(const string& filename);
void save_tasks(const vector<Task>& tasks, const string& fole_path);
void add_task(vector<Task>& tasks, const string& content);
void list_task(const vector<Task>& tasks);
void mark_task_done(vector<Task>& tasks, int task_id);
void remove_task(vector<Task>& tasks, int task_id);
