class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> mp;

  public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.count(val) > 0) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.count(val) == 0) return false;

        int i = mp[val];
        nums[i] = nums.back();
        mp[nums.back()] = i;
        mp.erase(val);

        nums.pop_back();
        return true;
    }

    int getRandom() {
        int i = rand() % nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */