#include <vector>
#include <unordered_map>

using namespace std;

/*
Jan 4th, 2024
    - Min Operations Until Empty: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int num_operations = 0;
        // push everything into a hashmap 
        for (int i = 0; i < nums.size(); i++) {
            hmap[nums[i]]++;
        }

        for (auto &kv:hmap) {
            if (kv.second == 1) {
                return -1;
            }
            // 3 situations -> %3 = 0,1,2
            if (kv.second % 3 == 1) {
                num_operations += 2;
                kv.second -= 4;
            } else if (kv.second % 3 == 2) {
                num_operations += 1;
                kv.second -= 2;
            }

            // now the rest is dividible by 3
            num_operations += (kv.second / 3);
            kv.second = 0; 
        }

        return num_operations;
    }
};


int main() {}
