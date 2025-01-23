#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

void flatten(vector<int> &result, const vector<NestedInteger> &nestedList) {
    for (auto &ni : nestedList) {
        if (ni.isInteger()) {
            result.push_back(ni.getInteger());
        } else {
            flatten(result, ni.getList());
        }
    }
}

class NestedIterator {
    vector<int> nums;
    int i;

  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nums, nestedList);
        this->i = 0;
    }

    int next() {
        int val = nums[i];
        i++;
        return val;
    }

    bool hasNext() {
        return (i < nums.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */