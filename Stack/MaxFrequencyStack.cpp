#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

/*
    - Pushing elements to stack -> pairs of {number, count of the value after insertion}
    - Can greatly improve this by using multiple stacks, one per frequency level, and using maxFrequeny to 
*/
class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freqMap[val]++;
        stackMap[freqMap[val]].push_back(val);
        maxFreq = max(maxFreq, freqMap[val]);
    }
    
    int pop() {
        int result = stackMap[maxFreq].back();
        freqMap[result]--;
        stackMap[maxFreq].pop_back();
        if (stackMap[maxFreq].empty()) {
            maxFreq--;
        }
        return result;
    }

private:
    unordered_map<int, int> freqMap;
    int maxFreq;
    unordered_map<int, vector<int>> stackMap;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    FreqStack freqStack;
    freqStack.push(5); // The stack is [5]
    freqStack.push(7); // The stack is [5,7]
    freqStack.push(5); // The stack is [5,7,5]
    freqStack.push(7); // The stack is [5,7,5,7]
    freqStack.push(4); // The stack is [5,7,5,7,4]
    freqStack.push(5); // The stack is [5,7,5,7,4,5]
    freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes 
}