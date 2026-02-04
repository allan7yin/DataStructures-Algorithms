#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Part 1: Given a letter matrix, determine whether you can find four consecutive letters 'u', 'b', 'e', 'r' in order,
in any of the up/down/left/right/diagonal straight directions. Note: you cannot turn/change directions.

Part 2: What if you are allowed to turn/change directions during the search? (The solution becomes DFS or BFS, treating the matrix as a graph.)

Part 3: Back to the constraint where you can only move up/down/left/right/diagonal in a straight line, but now other letters can be
inserted between the target characters, as long as their order is maintained (for example, "ubaedr" would count as a match).
Also, discuss the time complexity.

Ideas for how to solve:
- Part 1: you just iterate through the grid, on every `u`, check the 4 directions for the word
- Part 2: just do bfs from every `u` until you see an `uber` word
- Part 3: Same thing, but in each thing pushed to the frontier, also push the path so far -> check if uber word is in the path
*/

int main() {
}