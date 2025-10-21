# Terminal Todo Manager

A lightweight command-line todo list management tool developed in C++.

## Features

- ✅ Add new tasks
- 📝 List all tasks  
- ✔️ Mark tasks as done
- 🗑️ Delete tasks
- 💾 Persistent data storage

## Build & Installation

```bash
# Clone the repository
git clone https://github.com/LiZhuoyan17/terminal-todo-manager.git
cd terminal-todo-manager

# Compile
make

# Install to system path (optional)
sudo make install
```

## Usage

###1. Add a task
```bash
./todo add "Learn C++ programming"
./todo add "Read project documentation"
./todo add "Complete homework assignment"
```

###2. List all tasks
```bash
./todo list
```
Example output:

```ID:1   | [ ] Learn C++ programming     | Created: Wed Oct 21 16:30:45 2025
ID:2   | [ ] Read project documentation | Created: Wed Oct 21 16:31:02 2025```

###3. Mark task as done
```bash
./todo done 1
```
Marks task with ID 1 as completed.

###4. Delete a task
```bash
./todo remove 2
```
Deletes task with ID 2.

###5. View updated task list
```bash
./todo list
```
Example output:
```ID:1   | [*] Learn C++ programming     | Created: Wed Oct 21 16:30:45 2025
ID:3   | [ ] Complete homework assignment | Created: Wed Oct 21 16:32:15 2025```

##Data Storage
Task data is automatically saved in  tasks.in  file. Data persists after program restart.

##Technical Details
- **Language**: C++    
- **Standard**: C++11
- **Storage**: Plain text file  
- **Dependencies**: Standard Library only

##License
MIT License