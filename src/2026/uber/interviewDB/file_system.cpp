#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Design and implement a simplified in-memory file system that supports the following commands:

mkdir <dir_name>
Creates a new directory inside the current working directory. If a directory with the same name already exists, throw an error.

pwd
Prints the absolute path of the current working directory.

cd <dir_name>
Changes the current directory to the specified subdirectory.

Support cd .. to move up one directory (unless already at root).

Support absolute paths (e.g., /a/b/c) and relative paths (e.g., ../x).


Idea:
- Maintain Hashmap<string, vector<String>> -> where we map directory (absolute path) to list of subdirectories (relative name)
- need way to handle `cd ..` -> could just pop_back characters from current path, until we hit another `/`
*/
int main() {
}