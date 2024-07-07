#include <stack>

using namespace std;
/*
    - Really think about the properties of stack and what that means 
    - each entry in minStack is pair of the value itself, and the number of occurences in the stack 
    - we maintain a "min stack" which is a monotonically increasing stack, with top of stack being smallest 
*/
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stck.push(val);
        if (minStack.empty() || val < minStack.top().first) {
            minStack.push({val,1});
        } else if (minStack.top().first == val) {
            minStack.top().second++;
        }
    }
    
    void pop() {
        int val = stck.top();
        stck.pop();
        if (minStack.top().first == val) {
            minStack.top().second--;
            
            if (minStack.top().second == 0) {
                minStack.pop();
            }
        }
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minStack.top().first;
    }
private:
    stack<int> stck;
    stack<pair<int, int>> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {}