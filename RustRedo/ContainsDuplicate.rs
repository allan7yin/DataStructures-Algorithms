use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut my_set: HashSet<&i32> = HashSet::new();
        for num in &nums {
            my_set.insert(num);
        }

        my_set.len() != nums.len()
    }
}